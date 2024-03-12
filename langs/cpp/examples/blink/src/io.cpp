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

volatile vx::uint8* __attribute__((always_inline)) atmega328p_port(const vx::gpio::num n) {
    return (n <= 7) ? &PORTD : (n <= 13) ? &PORTB : &PORTC;
}

volatile vx::uint8* __attribute__((always_inline)) atmega328p_ddr(const vx::gpio::num n) {
    return (n <= 7) ? &DDRD : (n <= 13) ? &DDRB : &DDRC;
}

volatile vx::uint8* __attribute__((always_inline)) atmega328p_pin(const vx::gpio::num n) {
    return (n <= 7) ? &PIND : (n <= 13) ? &PINB : &PINC;
}


constexpr vx::gpio::num MAX_PIN = 19;

bool assert_param(vx::gpio::num n) {
    return (n <= MAX_PIN);
}

};

using namespace native;

void __attribute__((always_inline)) vx::gpio::init(const gpio::num n, gpio::mode mode) {
    if (!native::assert_param(n)) {
        return;
    }
    (*native::atmega328p_ddr(n)) |= (1 << atmega328p_n[n]);
}

void __attribute__((always_inline)) vx::gpio::deinit(const gpio::num n) {
    if (!native::assert_param(n)) {
        return;
    }
    (*native::atmega328p_ddr(n)) &= ~(1 << atmega328p_n[n]);
    (*native::atmega328p_port(n)) &= ~(1 << atmega328p_n[n]);
}

void VX_API_FUNC vx::gpio::write(const gpio::num n, gpio::state state) {
    if (native::assert_param(n)) {
        return;
    }
    if (state == gpio::state::HIGH) {
        (*native::atmega328p_port(n)) |= (1 << n); 
    } else {
        (*native::atmega328p_port(n)) &= ~(1 << n); 
    }
}

void VX_API_FUNC vx::gpio::write(gpio::num n, gpio::analog value) {
    ///
}

void VX_API_FUNC vx::gpio::toggle(gpio::num n) {
    ///
}

template<>
vx::gpio::state vx::gpio::read<vx::gpio::state>(gpio::num n) {
    return vx::gpio::state::HIGH;
}


template<>
vx::gpio::analog vx::gpio::read<vx::gpio::analog>(gpio::num n) {
    return static_cast<vx::gpio::analog>(0);
}
