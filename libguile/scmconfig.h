/* This file is automatically generated -- see configure.in for details */

#ifndef SCM_SCMCONFIG_H
#define SCM_SCMCONFIG_H

/* Important headers */
#include <stdint.h>
#include <stddef.h>
#include <limits.h>
#include <time.h>

#define SCM_HAVE_STDC_HEADERS 0 /* 0 or 1 */
#include <stdlib.h>
#include <sys/types.h>
#include <stddef.h>

#define SCM_HAVE_SYS_SELECT_H 0 /* 0 or 1 */
#define SCM_HAVE_FLOATINGPOINT_H 0 /* 0 or 1 */
#define SCM_HAVE_IEEEFP_H 0 /* 0 or 1 */
#define SCM_HAVE_NAN_H 0 /* 0 or 1 */
#define SCM_HAVE_WINSOCK2_H 0 /* 0 or 1 */


// Declare ssize_t if it's not defined
#ifdef _MSC_VER
#include <BaseTsd.h>
typedef SSIZE_T ssize_t;
#else
#include <unistd.h>
#endif

/* Define to include various undocumented debugging functions. */
/* #undef GUILE_DEBUG */

/* Define this to debug the free list (helps w/ GC bugs). */
/* #undef GUILE_DEBUG_FREELIST */

/* Set to 1 if you want to enable discouraged features. */
/* (value will be 0 or 1). */
#define SCM_ENABLE_DISCOURAGED 0

/* Set to 1 if you want to enable deprecated features. */
/* (value will be 0 or 1). */
#define SCM_ENABLE_DEPRECATED 0

/* Set to 1 to add Elisp support (in addition to Scheme). */
#define SCM_ENABLE_ELISP 0 /* 0 or 1 */

/* Set to 1 if the stack grows up, 0 otherwise. */
extern int SCM_STACK_GROWS_UP; /* 0 or 1 */

/* C compiler's syntax for inline functions if any,
   otherwise undefined. */
#define SCM_C_INLINE inline

/* Standard types. */
/* These are always defined */
#define SCM_SIZEOF_CHAR 1
#define SCM_SIZEOF_UNSIGNED_CHAR 1
#define SCM_SIZEOF_SHORT 2
#define SCM_SIZEOF_UNSIGNED_SHORT 2
#define SCM_SIZEOF_LONG 4
#define SCM_SIZEOF_UNSIGNED_LONG 4
#define SCM_SIZEOF_INT 4
#define SCM_SIZEOF_UNSIGNED_INT 4
#define SCM_SIZEOF_SIZE_T 8

/* Size of (unsigned) int64_t or 0 if not available (scm_t_*64 may
   be more likely to be what you want */
#define SCM_SIZEOF_LONG_LONG 8
#define SCM_SIZEOF_UNSIGNED_LONG_LONG 8

/* handling for the deprecated long_long and ulong_long types */
/* If anything suitable is available, it'll be defined here.  */
#if (SCM_ENABLE_DEPRECATED == 1)
typedef int64_t long_long;
typedef uint64_t ulong_long;
#endif /* SCM_ENABLE_DEPRECATED == 1 */

/* These are always defined. */
typedef int8_t scm_t_int8;
typedef uint8_t scm_t_uint8;
typedef int16_t scm_t_int16;
typedef uint16_t scm_t_uint16;
typedef int32_t scm_t_int32;
typedef uint32_t scm_t_uint32;
typedef intmax_t scm_t_intmax;
typedef uintmax_t scm_t_uintmax;
#define SCM_SIZEOF_INTMAX 8

#define SCM_HAVE_T_INT64 1 /* 0 or 1 */
typedef int64_t scm_t_int64;
#define SCM_HAVE_T_UINT64 1 /* 0 or 1 */
typedef uint64_t scm_t_uint64;

/* scm_t_ptrdiff_t and size, always defined -- defined to long if
   platform doesn't have ptrdiff_t. */
typedef ptrdiff_t scm_t_ptrdiff;
#define SCM_SIZEOF_SCM_T_PTRDIFF 8

/* Size of intptr_t or 0 if not available */
#define SCM_SIZEOF_INTPTR_T 8
/* Size of uintptr_t or 0 if not available */
#define SCM_SIZEOF_UINTPTR_T 8

/* same as POSIX "struct timespec" -- always defined */
/* POSIX.4 structure for a time value.  This is like a `struct timeval'   but has nanoseconds instead of microseconds.  */
typedef struct
{
  int64_t tv_sec;		/* Seconds.  */
  int64_t tv_nsec;		/* Nanoseconds.  */
} scm_t_timespec;

/*** Threading model (scmconfig.h support not finished) ***/
/* Define to 1 if using pthread multithreading. */
#define SCM_USE_PTHREAD_THREADS 0 /* 0 or 1 */
/* Define to 1 if using one-thread 'multi'threading. */
#define SCM_USE_NULL_THREADS 1 /* 0 or 1 */
/* Define to 1 if need braces around PTHREAD_ONCE_INIT (for Solaris). */
#define SCM_NEED_BRACES_ON_PTHREAD_ONCE_INIT 0 /* 0 or 1 */
/* Define to 1 if need braces around PTHREAD_MUTEX_INITIALIZER
   (for IRIX with GCC)  */
#define SCM_NEED_BRACES_ON_PTHREAD_MUTEX_INITIALIZER 0 /* 0 or 1 */


/*** File system access ***/
/* Define to 1 if `struct dirent64' is available.  */
#define SCM_HAVE_STRUCT_DIRENT64 0 /* 0 or 1 */
/* Define to 1 if `readdir64_r ()' is available.  */
#define SCM_HAVE_READDIR64_R 0 /* 0 or 1 */

#if SCM_ENABLE_DEPRECATED == 1
# define USE_THREADS 1 /* always true now */
# define GUILE_ISELECT 1 /* always true now */
# define READER_EXTENSIONS 1 /* always true now */
# define DEBUG_EXTENSIONS 1 /* always true now */
# define DYNAMIC_LINKING 1 /* always true now */
#endif

#define SCM_HAVE_ARRAYS 1 /* always true now */
#endif
