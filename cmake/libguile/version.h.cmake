/* classes: h_files */

#ifndef SCM_VERSION_H
#define SCM_VERSION_H

/* Copyright (C) 1995,1996,1998,1999,2000,2001, 2006 Free Software Foundation, Inc.
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
 * License with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */



#include "libguile/__scm.h"



#define SCM_MAJOR_VERSION @GUILE_MAJOR_VERSION@
#define SCM_MINOR_VERSION @GUILE_MINOR_VERSION@
#define SCM_MICRO_VERSION @GUILE_MICRO_VERSION@

SCM_API SCM scm_major_version (void);
SCM_API SCM scm_minor_version (void);
SCM_API SCM scm_micro_version (void);
SCM_API SCM scm_effective_version (void);
SCM_API SCM scm_version (void);
SCM_API void scm_init_version (void);

#endif  /* SCM_VERSION_H */

/*
  Local Variables:
  c-file-style: "gnu"
  mode: c
  End:
*/
