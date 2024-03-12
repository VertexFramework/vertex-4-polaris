#ifndef VERTEX_4_POLARIS_HARDWARE_IO_HPP__
#define VERTEX_4_POLARIS_HARDWARE_IO_HPP__

/**************************************************************************//**
 * @file     vxio.hpp
 * @brief    Vertex 4 Polaris. Hardware library. GPIO.
 * @version  V4.0.0
 * @date     5. Mar 2024
 * @author   Matvey Rybalkin
 ******************************************************************************/

/* Include Standard Vertex library */
#include <vertex.hpp>

/* Include Standard Hardware libraries */
#include "hardware.hpp"

/** 
 * @brief Standard Vertex namespace.
*/
namespace vx {

/** 
 * @brief Standard Vertex Hardware namespace for GPIO.
*/
namespace gpio {

/** 
 * @brief GPIO mode. Standard Vertex GPIO type.
*/
enum class mode {
    INPUT, OUTPUT,
    ANALOG_INPUT, ANALOG_OUTPUT,
};

/** 
 * @brief Pin state. Standard Vertex GPIO type.
*/
enum class state : bool {
    LOW = false, HIGH = true
};

/** 
 * @brief Pin number. Standard Vertex GPIO type.
*/
using num = uint16;

/** 
 * @brief Analog value. (0 ~ 1). Standard Vertex GPIO type.
*/
using analog = float;

/** 
 * @brief Inits mode for specific port.
 * 
 * @param[in] n GPIO number.
 * @param[in] mode GPIO mode.
*/
void init(const num n, mode mode);

/** 
 * @brief Deinitialize specific port.
 * 
 * @param[in] n GPIO number.
*/
void deinit(const num n);

/** 
 * @brief Writes ditial value for specific port.
 * 
 * @param[in] n GPIO number.
 * @param[in] mode GPIO mode.
*/
void write(const num n, state state);
/** 
 * @brief Writes analog value for specific port.
 * 
 * @param[in] n GPIO number.
 * @param[in] mode GPIO mode.
*/
void write(const num n, analog value);

/** 
 * @brief Reads digital/analog value for specific port.
 * 
 * @param[in] n GPIO number.
 * @return value in gpio::state or gpio::analog type.
*/
template<typename T>
T read(const num n);

/** 
 * @brief Reads digital value for specific port.
 * 
 * @param[in] n GPIO number.
 * @return value in pin::state
*/
template<>
state read<state>(num n);

/** 
 * @brief Reads analog value for specific port.
 * 
 * @param[in] n GPIO number.
 * @return value in pin::analog type.
*/
template<>
analog read<analog>(num n);

/** 
 * @brief Toggles/inverts digital value on the specific port.
 * 
 * @param[in] n GPIO number.
*/
void toggle(const num n);

}
}

#endif // VERTEX_4_POLARIS_HARDWARE_IO_HPP__