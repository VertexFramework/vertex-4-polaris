#include <vertex.hpp>

/* Native libraries */
namespace native {

extern "C" {
#include <avr/io.h>
#include <avr/pgmspace.h>
}

const static vx::uint8 PROGMEM atmega328p_n[] = {    
    0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U,
    0U, 1U, 2U, 3U, 4U, 5U,
    0U, 1U, 2U, 3U, 4U, 5U, 
};

volatile vx::uint8* __attribute__((always_inline)) atmega328p_port(const vx::pin::num n) {
    return (n <= 7) ? &PORTD : (n <= 13) ? &PORTB : &PORTC;
}

volatile vx::uint8* __attribute__((always_inline)) atmega328p_ddr(const vx::pin::num n) {
    return (n <= 7) ? &DDRD : (n <= 13) ? &DDRB : &DDRC;
}

volatile vx::uint8* __attribute__((always_inline)) atmega328p_pin(const vx::pin::num n) {
    return (n <= 7) ? &PIND : (n <= 13) ? &PINB : &PINC;
}


constexpr vx::pin::num MAX_PIN = 19;

bool assert_param(vx::pin::num n) {
    return (n <= MAX_PIN);
}

};

using namespace native;

void __attribute__((always_inline)) vx::gpio::mode(const pin::num n, pin::mode mode) {
    if (!native::assert_param(n)) {
        return;
    }
    (*native::atmega328p_ddr(n)) |= (1 << atmega328p_n[n]);
}

void VX_API_FUNC vx::gpio::write(const pin::num n, pin::state state) {
    if (native::assert_param(n)) {
        return;
    }
    if (state == pin::state::HIGH) {
        (*native::atmega328p_port(n)) |= (1 << n); 
    } else {
        (*native::atmega328p_port(n)) &= ~(1 << n); 
    }
}

void VX_API_FUNC vx::gpio::write(pin::num n, pin::analog value) {
    ///
}

void VX_API_FUNC vx::gpio::toggle(pin::num n) {
    ///
}

template<>
vx::pin::state vx::gpio::read<vx::pin::state>(pin::num n) {
    return vx::pin::state::HIGH;
}


template<>
vx::pin::analog vx::gpio::read<vx::pin::analog>(pin::num n) {
    return static_cast<vx::pin::analog>(0);
}
