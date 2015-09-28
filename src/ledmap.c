/*
Copyright 2014 Kai Ryu <kai1103@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <avr/pgmspace.h>
#include "ledmap.h"

#ifdef LEDMAP_ENABLE

static const uint16_t ledmaps[LED_COUNT] PROGMEM = {
    [0] = LEDMAP_CAPS_LOCK | LEDMAP_BACKLIGHT,      // CapsLock
    [1] = LEDMAP_BACKLIGHT,                         // Backlight
};

ledmap_t ledmap_get_code(uint8_t index)
{
    return (ledmap_t) { .code = pgm_read_word(&ledmaps[index]) };
}

void ledmap_led_init(void)
{
    DDRB |= (1<<PB2);
    PORTB |= (1<<PB2);
    DDRB  |= (1<<PB6);
    PORTB &= ~(1<<PB6);
}

void ledmap_led_on(uint8_t index)
{
    switch (index) {
        case 0:
            PORTB &= ~(1<<PB2);
            break;
        case 1:
            PORTB |= (1<<PB6);
            break;
    }
}

void ledmap_led_off(uint8_t index)
{
    switch (index) {
        case 0:
            PORTB |= (1<<PB2);
            break;
        case 1:
            PORTB &= ~(1<<PB6);
            break;
    }
}

#endif
