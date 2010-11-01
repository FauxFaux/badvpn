/**
 * @file modadd.h
 * @author Ambroz Bizjak <ambrop7@gmail.com>
 * 
 * @section LICENSE
 * 
 * This file is part of BadVPN.
 * 
 * BadVPN is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation.
 * 
 * BadVPN is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 * 
 * @section DESCRIPTION
 * 
 * Modular addition macro.
 */

#ifndef BADVPN_MISC_MODADD_H
#define BADVPN_MISC_MODADD_H

#include <misc/debug.h>

/**
 * Calculates (x + y) mod m, assuming
 * 0 <= x < m and 0 <= y < m.
 */
#define BMODADD(x, y, m) \
    ({ \
        typeof (x) _modadd_x = (x); \
        typeof (y) _modadd_y = (y); \
        typeof (m) _modadd_m = (m); \
        ASSERT(_modadd_x >= 0) \
        ASSERT(_modadd_x < _modadd_m) \
        ASSERT(_modadd_y >= 0) \
        ASSERT(_modadd_y < _modadd_m) \
        (_modadd_y >= _modadd_m - _modadd_x ? _modadd_y - (_modadd_m - _modadd_x) : _modadd_x + _modadd_y); \
    })

#endif