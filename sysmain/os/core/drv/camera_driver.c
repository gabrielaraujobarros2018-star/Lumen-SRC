/*
 * camera_driver.c
 * Minimal phone camera driver for PalisadeOS
 *
 * Scope:
 *  - Sensor initialization (I2C)
 *  - CSI/ISP configuration
 *  - Frame capture control
 *  - Interrupt-driven buffer handling
 *
 * Not a HAL. Not V4L2. OS-native driver.
 */

#include <stdint.h>
#include <stddef.h>

/* ===========================
 * Hardware Definitions
 * =========================== */

#define CAMERA_BASE_ADDR   0x41000000U   /* CSI / ISP base (SoC-specific) */
#define CAMERA_IRQ_LINE    42

#define I2C_CAMERA_BUS     1
#define CAMERA_I2C_ADDR    0x36           /* Example: Sony IMX / OmniVision */

/* CSI Registers (example offsets) */
#define CSI_CTRL           0x000
#define CSI_STATUS         0x004
#define CSI_FRAME_START    0x010
#define CSI_FRAME_DONE     0x014
#define CSI_BUF_ADDR       0x020
#define CSI_BUF_SIZE       0x024

/* Control flags */
#define CSI_ENABLE         (1 << 0)
#define CSI_START_CAPTURE  (1 << 1)

/* ===========================
 * Frame Buffer
 * =========================== */

#define FRAME_WIDTH   1920
#define FRAME_HEIGHT  1080
#define FRAME_BPP     2              /* YUV422 */

#define FRAME_SIZE (FRAME_WIDTH * FRAME_HEIGHT * FRAME_BPP)

static uint8_t camera_framebuffer[FRAME_SIZE] __attribute__((aligned(64)));

/* ===========================
 * Low-Level Access
 * =========================== */

static inline void mmio_write(uint32_t reg, uint32_t val) {
    volatile uint32_t *addr = (volatile uint32_t *)(CAMERA_BASE_ADDR + reg);
    *addr = val;
}

static inline uint32_t mmio_read(uint32_t reg) {
    volatile uint32_t *addr = (volatile uint32_t *)(CAMERA_BASE_ADDR + reg);
    return *addr;
}

/* ===========================
 * I2C Sensor Control (Stub)
 * =========================== */

/* These must be implemented by the platform I2C driver */
extern int i2c_write_reg(uint8_t bus, uint8_t addr, uint16_t reg, uint8_t val);
extern int i2c_read_reg(uint8_t bus, uint8_t addr, uint16_t reg, uint8_t *val);

/* ===========================
 * Sensor Initialization
 * =========================== */

static int camera_sensor_init(void) {
    /* Reset sensor */
    i2c_write_reg(I2C_CAMERA_BUS, CAMERA_I2C_ADDR, 0x0103, 0x01);

    /* Basic sensor configuration (example values) */
    i2c_write_reg(I2C_CAMERA_BUS, CAMERA_I2C_ADDR, 0x3000, 0x08); /* standby off */
    i2c_write_reg(I2C_CAMERA_BUS, CAMERA_I2C_ADDR, 0x0340, FRAME_HEIGHT >> 8);
    i2c_write_reg(I2C_CAMERA_BUS, CAMERA_I2C_ADDR, 0x0341, FRAME_HEIGHT & 0xFF);
    i2c_write_reg(I2C_CAMERA_BUS, CAMERA_I2C_ADDR, 0x0342, FRAME_WIDTH >> 8);
    i2c_write_reg(I2C_CAMERA_BUS, CAMERA_I2C_ADDR, 0x0343, FRAME_WIDTH & 0xFF);

    return 0;
}

/* ===========================
 * CSI / ISP Setup
 * =========================== */

static void camera_csi_init(void) {
    mmio_write(CSI_BUF_ADDR, (uint32_t)camera_framebuffer);
    mmio_write(CSI_BUF_SIZE, FRAME_SIZE);
    mmio_write(CSI_CTRL, CSI_ENABLE);
}

/* ===========================
 * Capture Control
 * =========================== */

int camera_start_capture(void) {
    mmio_write(CSI_CTRL, CSI_ENABLE | CSI_START_CAPTURE);
    return 0;
}

int camera_stop_capture(void) {
    mmio_write(CSI_CTRL, CSI_ENABLE);
    return 0;
}

/* ===========================
 * Interrupt Handling
 * =========================== */

void camera_irq_handler(void) {
    uint32_t status = mmio_read(CSI_STATUS);

    if (status & CSI_FRAME_DONE) {
        /* Frame is now in camera_framebuffer */
        mmio_write(CSI_STATUS, CSI_FRAME_DONE); /* clear interrupt */

        /* Notify OS compositor / userspace */
        /* os_signal_device_event("camera0"); */
    }
}

/* ===========================
 * Driver Entry Points
 * =========================== */

int camera_driver_init(void) {
    camera_sensor_init();
    camera_csi_init();

    /* Register IRQ */
    /* irq_register(CAMERA_IRQ_LINE, camera_irq_handler); */

    return 0;
}

void *camera_get_framebuffer(void) {
    return camera_framebuffer;
}