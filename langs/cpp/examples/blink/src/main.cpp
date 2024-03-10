#include <vertex.hpp>
using namespace vx;

class blink : public vertex <blink> {
public:
    void setup(void) {
        vx::gpio::mode(1, vx::pin::mode::OUTPUT);
        vx::gpio::mode(2, vx::pin::mode::OUTPUT);
        vx::gpio::mode(3, vx::pin::mode::OUTPUT);
        vx::gpio::mode(4, vx::pin::mode::OUTPUT);
        vx::gpio::mode(5, vx::pin::mode::OUTPUT);
        vx::gpio::mode(6, vx::pin::mode::OUTPUT);
        vx::gpio::mode(7, vx::pin::mode::OUTPUT);
        vx::gpio::mode(8, vx::pin::mode::OUTPUT);
        vx::gpio::mode(9, vx::pin::mode::OUTPUT);
        vx::gpio::mode(10, vx::pin::mode::OUTPUT);
        vx::gpio::mode(11, vx::pin::mode::OUTPUT);
        vx::gpio::mode(12, vx::pin::mode::OUTPUT);
        vx::gpio::mode(13, vx::pin::mode::OUTPUT);
    }
    void loop(void) {
    }
};



VERTEX_START(blink);
