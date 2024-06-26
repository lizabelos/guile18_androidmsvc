/* classes: h_files */

#ifndef SCM_ALIST_H
#define SCM_ALIST_H

/* Copyright (C) 1995,1996,2000, 2006 Free Software Foundation, Inc.
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



SCM scm_acons (SCM w, SCM x, SCM y);
SCM scm_sloppy_assq (SCM x, SCM alist);
SCM scm_sloppy_assv (SCM x, SCM alist);
SCM scm_sloppy_assoc (SCM x, SCM alist);
SCM scm_assq (SCM x, SCM alist);
SCM scm_assv (SCM x, SCM alist);
SCM scm_assoc (SCM x, SCM alist);
SCM scm_assq_ref (SCM alist, SCM key);
SCM scm_assv_ref (SCM alist, SCM key);
SCM scm_assoc_ref (SCM alist, SCM key);
SCM scm_assq_set_x (SCM alist, SCM key, SCM val);
SCM scm_assv_set_x (SCM alist, SCM key, SCM val);
SCM scm_assoc_set_x (SCM alist, SCM key, SCM val);
SCM scm_assq_remove_x (SCM alist, SCM key);
SCM scm_assv_remove_x (SCM alist, SCM key);
SCM scm_assoc_remove_x (SCM alist, SCM key);
void scm_init_alist (void);

static inline SCM
scm_sloppy_assoc_var (SCM obj1, SCM obj2, void* closure)
{
  (void) closure;
  return scm_sloppy_assoc (obj1, obj2);
}

static inline SCM
scm_sloppy_assq_var (SCM obj1, SCM obj2, void* closure)
{
  (void) closure;
  return scm_sloppy_assq (obj1, obj2);
}

static inline SCM
scm_sloppy_assv_var (SCM obj1, SCM obj2, void* closure)
{
  (void) closure;
  return scm_sloppy_assv (obj1, obj2);
}

#endif  /* SCM_ALIST_H */

/*
  Local Variables:
  c-file-style: "gnu"
  End:
*/
