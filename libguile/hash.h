/* classes: h_files */

#ifndef SCM_HASH_H
#define SCM_HASH_H

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
 * License with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */



#include "libguile/__scm.h"

typedef struct scm_t_ihashx_closure
{
    SCM hash;
    SCM assoc;
} scm_t_ihashx_closure;

typedef uint64_t (*scm_t_hash_fn) (SCM obj, uint64_t d, scm_t_ihashx_closure *closure);
typedef SCM (*scm_t_assoc_fn) (SCM obj, SCM d, scm_t_ihashx_closure *closure);


SCM_API uint64_t scm_string_hash (const unsigned char *str, size_t len);
SCM_API uint64_t scm_hasher (SCM obj, uint64_t n, size_t d);
SCM_API uint64_t scm_ihashq (SCM obj, uint64_t n, scm_t_ihashx_closure *c);
SCM_API SCM scm_hashq (SCM obj, SCM n);
SCM_API uint64_t scm_ihashv (SCM obj, uint64_t n, scm_t_ihashx_closure *closure);
SCM_API SCM scm_hashv (SCM obj, SCM n);
SCM_API uint64_t scm_ihash (SCM obj, uint64_t n, scm_t_ihashx_closure *closure);
SCM_API SCM scm_hash (SCM obj, SCM n);
SCM_API void scm_init_hash (void);

#endif  /* SCM_HASH_H */

/*
  Local Variables:
  c-file-style: "gnu"
  End:
*/
