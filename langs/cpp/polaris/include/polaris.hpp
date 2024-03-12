#ifndef VERTEX_4_POLARIS_LIB_HPP__
#define VERTEX_4_POLARIS_LIB_HPP__

/**************************************************************************//**
 * @file     vertex.hpp
 * @brief    Vertex 4 Polaris. Main header file.
 * @version  V4.0.0
 * @date     12. Mar 2024
 * @author   Matvey Rybalkin
 ******************************************************************************/

/*
 * This file is part of Vertex 4 Polaris.
 * Multilingual, cross-platform framework for robots and embedded systems.
 * 
 * Copyright (C) 2024 Matvey Ryblkin
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

/* Check C++ standard */
#if __cplusplus >= 201402L

/* Include Polaris standard ML libraries */
#include "ML/ps_ml1.hpp"

#else
#error "[Vertex 4 Polaris]: Requires at least version C++ 2014 (__cplusplus >= 201402L)"
#endif

#endif // VERTEX_4_POLARIS_LIB_HPP__