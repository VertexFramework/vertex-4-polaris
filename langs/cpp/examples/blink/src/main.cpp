#include <vertex.hpp>
using namespace vx;

class blink : public vertex <blink> {
public:
    void setup(void) {
        vx::gpio::init(1, vx::gpio::mode::OUTPUT);
        vx::gpio::init(2, vx::gpio::mode::OUTPUT);
        vx::gpio::init(3, vx::gpio::mode::OUTPUT);
        vx::gpio::init(4, vx::gpio::mode::OUTPUT);
        vx::gpio::init(5, vx::gpio::mode::OUTPUT);

        vx::gpio::deinit(4);
    }
    void loop(void) {
    }
};



VERTEX_START(blink);
