#ifndef VCNL4040_H
#define VCNL4040_H

#include "pico/stdlib.h"
#include "hardware/i2c.h"

// VCNL4040 I2C address
#define VCNL4040_ADDR 0x13

// Register addresses for VCNL4040 (some key registers)
#define VCNL4040_PROXIMITY_DATA_REG 0x80
#define VCNL4040_AMBIENT_DATA_REG 0x84
#define VCNL4040_COMMAND_REG 0x80

// Function prototypes
void vcnl4040_init();
uint16_t vcnl4040_read_proximity();
uint16_t vcnl4040_read_ambient_light();
void vcnl4040_read_both();

#endif // VCNL4040_H
