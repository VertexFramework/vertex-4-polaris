/* Include main Vertex library */
#include <vertex.hpp>

/* Native libraries */
namespace native {
extern "C" {
/* Include standard AVR IO library */
#include <avr/io.h>
#include <avr/pgmspace.h>
}

const static vx::uint8 PROGMEM atmega328p_n[] = {    
    0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U,
    0U, 1U, 2U, 3U, 4U, 5U,
    0U, 1U, 2U, 3U, 4U, 5U, 
};

volatile vx::uint8* VX_ALWAYS_INLINE atmega328p_port(const vx::gpio::num n) {
    return (n <= 7) ? &PORTD : (n <= 13) ? &PORTB : &PORTC;
}

volatile vx::uint8* VX_ALWAYS_INLINE atmega328p_ddr(const vx::gpio::num n) {
    return (n <= 7) ? &DDRD : (n <= 13) ? &DDRB : &DDRC;
}

volatile vx::uint8* VX_ALWAYS_INLINE atmega328p_pin(const vx::gpio::num n) {
    return (n <= 7) ? &PIND : (n <= 13) ? &PINB : &PINC;
}

constexpr vx::gpio::num MAX_PIN = 19;

bool assert_param(vx::gpio::num n) {
    return (n <= MAX_PIN);
}

}

namespace vx {
namespace gpio {

void VX_ALWAYS_INLINE init(const num n, mode mode) {
    if (!native::assert_param(n)) {
        return;
    }
    (*native::atmega328p_ddr(n)) |= (1 << native::atmega328p_n[n]);
}

}
}

