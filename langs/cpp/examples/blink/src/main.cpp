#include <vertex.hpp>
#include <polaris.hpp>
using namespace vx;

class blink : public vertex <blink> {
public:
    void setup(void) {
        gpio::multiple::init_config led[] = {
            {13, gpio::mode::OUTPUT},
            {11, gpio::mode::OUTPUT},
        };
        gpio::multiple::init(1, led);
    }
    void loop(void) {
    }
};

VERTEX_START(blink);
