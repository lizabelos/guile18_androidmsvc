/* classes: h_files */

#ifndef SCM_VALUES_H
#define SCM_VALUES_H

/* Copyright (C) 2000,2001, 2006 Free Software Foundation, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */



#include "libguile/__scm.h"

extern SCM scm_values_vtable;

#define SCM_VALUESP(x) (SCM_STRUCTP (x)\
                        && scm_is_eq (scm_struct_vtable (x), scm_values_vtable))

SCM scm_values (SCM args);
void scm_init_values (void);

#endif  /* SCM_VALUES_H */

/*
  Local Variables:
  c-file-style: "gnu"
  End:
*/
