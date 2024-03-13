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
    LOCKED,
    INPUT_OPEN_DRAIN,
    INPUT_PULL_UP,
    INPUT_PULL_DOWN,
    INPUT_ADC,
    OUTPUT,
    OUTPUT_PWM,
    OUTPUT_DAC,
    RESERVED
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
using num = vx::uint16;




}

}

#endif // VERTEX_4_POLARIS_FLEX_HARDWARE_IO_HPP__