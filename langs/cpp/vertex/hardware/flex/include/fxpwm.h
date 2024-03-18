#ifndef VERTEX_4_POLARIS_FLEX_HARDWARE_PWM_HPP__
#define VERTEX_4_POLARIS_FLEX_HARDWARE_PWM_HPP__

/**************************************************************************//**
 * @file     fxpwm.hpp
 * @brief    Vertex 4 Polaris. Flex Hardware library. PWM.
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
 * @brief Standard Flex Hardware namespace for PWM.
*/
namespace pwm {

/** 
 * @brief PWM mode. Standard Flex PWM type.
*/
enum class mode {
    FAST, PHASE_CORRECT, PHASE_FREQUENCY_CORRECT,
    VARIABLE_PHASE_CORRECT, CENTER_ALIGNED,
    SINGLE_SLOPE, DUAL_SLOPE, DEAD_TIME_INSERTION,
    COMPLEMENTARY
};

/** 
 * @brief PWM channel number type.
*/
using num = vx::uint16;

/** 
 * @brief Inits PWM
 * 
 * @param[in] n PWM channel.
 * @param[in] mode PWM mode.
*/
void init(const num n, mode mode);

}

}

#endif // VERTEX_4_POLARIS_FLEX_HARDWARE_PWM_HPP__