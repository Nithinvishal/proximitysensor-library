#include "pico/stdlib.h"
#include "vcnl4040.h"
#include <stdio.h>

int main() {
    stdio_init_all();  // Initialize standard I/O for UART or USB debugging

    // Initialize the VCNL4040 sensor
    vcnl4040_init();

    while (1) {
        // Option 1: Read only proximity
        uint16_t proximity = vcnl4040_read_proximity();
        printf("Proximity: %u\n", proximity);

        // Option 2: Read only ambient light
        uint16_t ambient_light = vcnl4040_read_ambient_light();
        printf("Ambient Light: %u\n", ambient_light);

        // Option 3: Read both
        vcnl4040_read_both();

        sleep_ms(1000); // Delay for 1 second before repeating
    }

    return 0;
}
