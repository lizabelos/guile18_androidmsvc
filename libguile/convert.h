/* classes: h_files */

#ifndef SCM_CONVERT_H
#define SCM_CONVERT_H

/* Copyright (C) 2002, 2006 Free Software Foundation, Inc.
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

char *scm_c_scm2chars (SCM obj, char *dst);
short *scm_c_scm2shorts (SCM obj, short *dst);
int *scm_c_scm2ints (SCM obj, int *dst);
SCM_API int64_t *scm_c_scm2longs (SCM obj, int64_t *dst);
float *scm_c_scm2floats (SCM obj, float *dst);
double *scm_c_scm2doubles (SCM obj, double *dst);

SCM scm_c_chars2scm (const char *src, int64_t n);
SCM scm_c_shorts2scm (const short *src, int64_t n);
SCM scm_c_ints2scm (const int *src, int64_t n);
SCM scm_c_longs2scm (const int64_t *src, int64_t n);
SCM scm_c_floats2scm (const float *src, int64_t n);
SCM scm_c_doubles2scm (const double *src, int64_t n);

SCM scm_c_chars2byvect (const char *src, int64_t n);
SCM scm_c_shorts2svect (const short *src, int64_t n);
SCM scm_c_ints2ivect (const int *src, int64_t n);
SCM scm_c_uints2uvect (const unsigned int *src, int64_t n);
SCM scm_c_longs2ivect (const int64_t *src, int64_t n);
SCM scm_c_ulongs2uvect (const uint64_t *src, int64_t n);
SCM scm_c_floats2fvect (const float *src, int64_t n);
SCM scm_c_doubles2dvect (const double *src, int64_t n);

#endif /* SCM_CONVERT_H */
