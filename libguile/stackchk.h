/* classes: h_files */

#ifndef SCM_STACKCHK_H
#define SCM_STACKCHK_H

/* Copyright (C) 1995,1996,1998,2000, 2003, 2006 Free Software Foundation, Inc.
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

#include "libguile/continuations.h"
#include "libguile/debug.h"

extern int scm_stack_checking_enabled_p;



SCM_API void scm_report_stack_overflow (void);
SCM_API int64_t scm_stack_size (SCM_STACKITEM *start);
SCM_API void scm_stack_report (void);
SCM_API SCM scm_sys_get_stack_size (void);
SCM_API void scm_init_stackchk (void);

/* With debug options we have the possibility to disable stack checking.
 */
#define SCM_STACK_CHECKING_P SCM_STACK_LIMIT

#ifdef STACK_CHECKING
inline int SCM_STACK_OVERFLOW_P(void *s);
inline void SCM_CHECK_STACK(void);
#else
inline void SCM_CHECK_STACK(void);
#endif /* STACK_CHECKING */

//SCM_API int scm_stack_checking_enabled_p;





#endif  /* SCM_STACKCHK_H */

/*
  Local Variables:
  c-file-style: "gnu"
  End:
*/
