#include <vertex.hpp>
using namespace vx;

class blink : public vertex <blink> {
public:
    void setup(void) {
        gpio::mode(13, pin::mode::OUTPUT);
    }
    void loop(void) {

    }
};



VERTEX_START(blink);
