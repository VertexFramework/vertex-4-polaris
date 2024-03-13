#ifndef VERTEX_4_POLARIS_HARDWARE_DELAY_HPP__
#define VERTEX_4_POLARIS_HARDWARE_DELAY_HPP__

/**************************************************************************//**
 * @file     vxdelay.hpp
 * @brief    Vertex 4 Polaris. Hardware library. GPIO.
 * @version  V4.0.0
 * @date     5. Mar 2024
 * @author   Matvey Rybalkin
 ******************************************************************************/

/* Include Standard Vertex library */
#include <vertex.hpp>

/* Include Standard Hardware libraries */
#include "../../include/hardware.hpp"

/** 
 * @brief Standard Vertex namespace.
*/
namespace vx {

/** 
 * @brief Standard Vertex Hardware namespace delay.
*/
namespace delay {

/** 
 * @brief Makes a delay for a certain number of seconds.
 * 
 * @param[in] time number of seconds.
*/
void s(double time);

/** 
 * @brief Makes a delay for a certain number of milliseconds.
 * 
 * @param[in] time number of milliseconds.
*/
void ms(double time);

/** 
 * @brief Makes a delay for a certain number of nanoseconds.
 * 
 * @param[in] time number of nanoseconds.
*/
void us(double time);

}


}

#endif // VERTEX_4_POLARIS_HARDWARE_DELAY_HPP__