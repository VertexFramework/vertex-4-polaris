#include <vertex.hpp>
#include <polaris.hpp>
using namespace fx;

class blink : public vertex <blink> {
public:
    void setup(void) {
        fx::gpio::init(13, gpio::mode::AF_OPEN_DRAIN);
    }
    void loop(void) {

    }
};
 
VERTEX_START(blink);