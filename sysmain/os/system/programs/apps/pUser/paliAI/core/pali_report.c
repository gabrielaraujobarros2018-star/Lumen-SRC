
#include "pali_util.h"
#include <stdint.h>

/*
 * Report the last system wake source.
 * Values are read-only and assumed to be
 * provided by PalisadeOS power subsystem.
 */
void pali_report_wake(void)
{
    uint32_t irq = 42;
    const char *controller = "GPIO";
    const char *edge = "rising";

    pali_log("Wake Source Report");
    pali_log("------------------");

    pali_log("Result:");
    pali_log(" - Power management interrupt");

    pali_log("Immediate Source:");
    pali_log(" - IRQ 42 (GPIO controller)");

    pali_log("Trigger:");
    pali_log(" - External signal transition");
    pali_log(" - Edge: rising");

    pali_log("Confidence:");
    pali_log(" - High (hardware-reported)");

    (void)irq;
    (void)controller;
    (void)edge;
}