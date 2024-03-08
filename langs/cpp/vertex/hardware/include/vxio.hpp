#ifndef VERTEX_4_POLARIS_HARDWARE_IO_HPP__
#define VERTEX_4_POLARIS_HARDWARE_IO_HPP__

/**************************************************************************//**
 * @file     vxio.hpp
 * @brief    Vertex 4 Polaris. Hardware library. GPIO.
 * @version  V4.0.0
 * @date     5. Mar 2024
 * @author   Matvey Rybalkin
 ******************************************************************************/

/** 
 * @brief Standard Vertex namespace.
*/
namespace vx {

namespace pin {

/** 
 * @brief Pin mode. Standard Vertex type.
*/
enum class mode {
    INPUT, OUTPUT,
    ANALOG_INPUT, ANALOG_OUTPUT,
};

/** 
 * @brief Pin state. Standard Vertex type.
*/
enum class state : bool {
    LOW = false, HIGH = true
};

/** 
 * @brief Pin number. Standard Vertex type.
*/
using num = uint16;

/** 
 * @brief Pin number. Standard Vertex type.
*/
using analog = float;

}

/** 
 * @brief Standard Vertex Hardware class for delay.
*/
class gpio {
public:
    /** 
     * @brief Sets mode for specific port.
     * 
     * @param[in] n GPIO number.
     * @param[in] mode GPIO mode.
    */
    static void mode(pin::num n, pin::mode mode);
    /** 
     * @brief Writes ditial value for specific port.
     * 
     * @param[in] n GPIO number.
     * @param[in] mode GPIO mode.
    */
    static void write(pin::num n, pin::state state);
    /** 
     * @brief Writes analog value for specific port.
     * 
     * @param[in] n GPIO number.
     * @param[in] mode GPIO mode.
    */
    static void write(pin::num n, pin::analog value);
    
    /** 
     * @brief Reads digital/analog value for specific port.
     * 
     * @param[in] n GPIO number.
     * @return value in pin::state or pin::analog type.
    */
    template<typename T>
    static T read(pin::num n);


    /** 
     * @brief Toggles/inverts digital value on the specific port.
     * 
     * @param[in] n GPIO number.
    */
    static void toggle(pin::num n);
};

/** 
 * @brief Reads digital value for specific port.
 * 
 * @param[in] n GPIO number.
 * @return value in pin::state
*/
template<>
pin::state gpio::read<pin::state>(pin::num n);

/** 
 * @brief Reads analog value for specific port.
 * 
 * @param[in] n GPIO number.
 * @return value in pin::analog type.
*/
template<>
pin::analog gpio::read<pin::analog>(pin::num n);

}

#endif // VERTEX_4_POLARIS_HARDWARE_IO_HPP__