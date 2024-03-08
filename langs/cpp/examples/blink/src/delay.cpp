#include <vertex.hpp>

/* Native libraries */
namespace native {

extern "C" {
#include <math.h>
#include <util/delay.h>
}

};

VX_API_FUNC void vx::delay::s(double time) {
    while (time) {
        //native::_delay_ms(1000);
    }
}

VX_API_FUNC void vx::delay::ms(double time) {
    //native::_delay_ms(time);
}

VX_API_FUNC void vx::delay::us(double time) {
    //native::_delay_us(time);
}