#ifndef VERTEX_4_POLARIS_HARDWARE_DELAY_HPP__
#define VERTEX_4_POLARIS_HARDWARE_DELAY_HPP__

/**************************************************************************//**
 * @file     vxdelay.hpp
 * @brief    Vertex 4 Polaris. Hardware library. GPIO.
 * @version  V4.0.0
 * @date     5. Mar 2024
 * @author   Matvey Rybalkin
 ******************************************************************************/

/** 
 * @brief Standard Vertex namespace.
*/
namespace vx {

/** 
 * @brief Standard Vertex Hardware class for delay.
*/
class delay {
public:
    /** 
     * @brief Makes a delay for a certain number of seconds.
     * 
     * @param[in] time number of seconds.
    */
    static void s(double time);
    /** 
     * @brief Makes a delay for a certain number of milliseconds.
     * 
     * @param[in] time number of milliseconds.
    */
    static void ms(double time);
    /** 
     * @brief Makes a delay for a certain number of nanoseconds.
     * 
     * @param[in] time number of nanoseconds.
    */
    static void us(double time);
};


}

#endif // VERTEX_4_POLARIS_HARDWARE_DELAY_HPP__