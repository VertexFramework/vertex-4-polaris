#include <vertex.hpp>

/* Native libraries */
namespace native {

extern "C" {
#include <math.h>
#include <util/delay.h>
}

};

void vx::delay::s(double time) {
    while (time) {
        //native::_delay_ms(1000);
    }
}

void vx::delay::ms(double time) {
    //native::_delay_ms(time);
}

void vx::delay::us(double time) {
    //native::_delay_us(time);
}