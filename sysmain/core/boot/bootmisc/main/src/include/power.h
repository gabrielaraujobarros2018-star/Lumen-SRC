// include/power.h
#pragma once

void power_set_idle(int state);
int power_is_idle();

void thermal_update(float temp);
float thermal_get();

void charge_set(int state);
int charge_is_active();