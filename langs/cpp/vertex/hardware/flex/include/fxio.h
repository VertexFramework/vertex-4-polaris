#ifndef VERTEX_4_POLARIS_FLEX_HARDWARE_IO_HPP__
#define VERTEX_4_POLARIS_FLEX_HARDWARE_IO_HPP__

/**************************************************************************//**
 * @file     fxio.hpp
 * @brief    Vertex 4 Polaris. Flex Hardware library. GPIO.
 * @version  V4.0.0
 * @date     13. Mar 2024
 * @author   Matvey Rybalkin
 ******************************************************************************/

/* Include Standard Vertex library */
#include <vertex.hpp>

/* Include Standard Hardware libraries */
#include "../../include/hardware.hpp"

/** 
 * @brief Standard Flex namespace.
*/
namespace fx {

/** 
 * @brief Standard Flex Hardware namespace for GPIO.
*/
namespace gpio {

/** 
 * @brief GPIO mode. Standard Flex GPIO type.
*/
enum class mode {
    INPUT_FLOATING, INPUT_PULL_DOWN, INPUT_PULL_UP,
    OUTPUT_OPEN_DRAIN, OUTPUT_PULL_DOWN, OUTPUT_PULL_UP,
    OUTPUT_PUSH_PULL,
    ANALOG,
    AF_OPEN_DRAIN, AF_PUSH_PULL
};

/** 
 * @brief Pin state. Standard Flex GPIO type.
*/
enum class state : bool {
    LOW = false, HIGH = true
};

/** 
 * @brief Pin number. Standard Vertex GPIO type.
*/
using num = unsigned short;

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
 * @brief Reads digital value for specific port.
 * 
 * @param[in] n GPIO number.
 * @return value in state
*/
state read(num n);

/** 
 * @brief Toggles/inverts digital value on the specific port.
 * 
 * @param[in] n GPIO number.
*/
void toggle(const num n);

}

}

#endif // VERTEX_4_POLARIS_FLEX_HARDWARE_IO_HPP__