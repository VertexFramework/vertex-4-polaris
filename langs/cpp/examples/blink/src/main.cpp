#include <vertex.hpp>
#include <polaris.hpp>
using namespace vx;

class blink : public vertex <blink> {
public:
    void setup(void) {
        gpio::init(5, gpio::mode::OUTPUT);
    }
    void loop(void) {
        //gpio::toggle(13);
        //delay::s(0.25);
    }
};
 

VERTEX_START(blink);
