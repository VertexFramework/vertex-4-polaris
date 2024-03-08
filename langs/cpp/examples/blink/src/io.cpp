#include <vertex.hpp>

/* Native libraries */
namespace native {

extern "C" {
#include <avr/io.h>
}

static vx::uint8 VX_API_DATA atmega328p_n[] = {    
    0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U,
    0U, 1U, 2U, 3U, 4U, 5U,
    0U, 1U, 2U, 3U, 4U, 5U, 
};

static volatile VX_API_DATA vx::uint8* atmega328p_port[] = {    
    &PORTD, &PORTD, &PORTD, &PORTD, &PORTD, &PORTD, &PORTD, &PORTD,
    &PORTB, &PORTB, &PORTB, &PORTB, &PORTB, &PORTB,
    &PORTC, &PORTC, &PORTC, &PORTC, &PORTC, &PORTC, 
};

static volatile VX_API_DATA vx::uint8* atmega328p_ddr[] = {    
    &DDRD, &DDRD, &DDRD, &DDRD, &DDRD, &DDRD, &DDRD, &DDRD,
    &DDRB, &DDRB, &DDRB, &DDRB, &DDRB, &DDRB,
    &DDRC, &DDRC, &DDRC, &DDRC, &DDRC, &DDRC, 
};

static volatile VX_API_DATA vx::uint8* atmega328p_pin[] = {    
    &PIND, &PIND, &PIND, &PIND, &PIND, &PIND, &PIND, &PIND,
    &PINB, &PINB, &PINB, &PINB, &PINB, &PINB,
    &PINC, &PINC, &PINC, &PINC, &PINC, &PINC, 
};

constexpr vx::pin::num MAX_PIN = 20;

bool assert_param(vx::pin::num n) {
    return (n > MAX_PIN);
}

};


VX_API_FUNC void vx::gpio::mode(pin::num n, pin::mode mode) {
    if (native::assert_param(n)) {
        return;
    }
    switch (mode) {
        case pin::mode::OUTPUT:
            (*native::atmega328p_ddr[n]) |= (1 << native::atmega328p_n[n]); 
            break;
        case pin::mode::INPUT:
            (*native::atmega328p_ddr[n]) &= ~(1 << native::atmega328p_n[n]); 
            break;
        default:{
            (*native::atmega328p_ddr[n]) &= ~(1 << native::atmega328p_n[n]);
        }
    }
}

VX_API_FUNC void vx::gpio::write(pin::num n, pin::state state) {
    if (state == pin::state::HIGH) {
        (*native::atmega328p_port[n]) |= (1 << n); 
    } else {
        (*native::atmega328p_port[n]) &= ~(1 << n); 
    }
}

VX_API_FUNC void vx::gpio::write(pin::num n, pin::analog value) {
    ///
}

VX_API_FUNC void vx::gpio::toggle(pin::num n) {
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
