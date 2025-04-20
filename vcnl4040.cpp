#include "vcnl4040.h"
#include <cstdio>


static void write_register(uint8_t reg, uint8_t value) {
    uint8_t buffer[2] = { reg, value };
    i2c_write_blocking(i2c0, VCNL4040_ADDR, buffer, 2, false);
}

static uint16_t read_register(uint8_t reg) {
    uint8_t buffer[2];
    i2c_write_blocking(i2c0, VCNL4040_ADDR, &reg, 1, true);
    i2c_read_blocking(i2c0, VCNL4040_ADDR, buffer, 2, false);
    return (buffer[1] << 8) | buffer[0];
}

void vcnl4040_init() {
    i2c_init(i2c0, 100 * 1000);
    gpio_set_function(4, GPIO_FUNC_I2C);  // SDA
    gpio_set_function(5, GPIO_FUNC_I2C);  // SCL
    gpio_pull_up(4);
    gpio_pull_up(5);
    // Add VCNL4040 specific initialization if needed
}

uint16_t vcnl4040_read_proximity() {
    return read_register(VCNL4040_PROXIMITY_DATA_REG);
}

uint16_t vcnl4040_read_ambient_light() {
    return read_register(VCNL4040_AMBIENT_DATA_REG);
}

void vcnl4040_read_both() {
    uint16_t prox = vcnl4040_read_proximity();
    uint16_t amb = vcnl4040_read_ambient_light();
    printf("Proximity: %u, Ambient Light: %u\n", prox, amb);
}
