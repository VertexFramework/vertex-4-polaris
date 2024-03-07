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

/** 
 * @brief Standard Vertex Hardware class for delay.
*/
class gpio {
public:
    /** 
     * @brief Makes a delay for a certain number of seconds.
     * 
     * @param[in] time number of seconds.
    */
    void mode();
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
};


}

#endif // VERTEX_4_POLARIS_HARDWARE_IO_HPP__