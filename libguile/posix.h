/* classes: h_files */

#ifndef SCM_POSIX_H
#define SCM_POSIX_H

/* Copyright (C) 1995,1996,1997,1998,2000,2001, 2003, 2006 Free Software Foundation, Inc.
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






SCM scm_tcsetpgrp (SCM port, SCM pgid);
SCM scm_tcgetpgrp (SCM port);
SCM scm_ctermid (void);
SCM scm_setsid (void);
SCM scm_setpgid (SCM pid, SCM pgid);
SCM scm_pipe (void);
SCM scm_getgroups (void);
SCM scm_setgroups (SCM groups);
SCM scm_getpgrp (void);
SCM scm_getpwuid (SCM user);
SCM scm_setpwent (SCM arg);
SCM scm_getgrgid (SCM name);
SCM scm_setgrent (SCM arg);
SCM scm_kill (SCM pid, SCM sig);
SCM scm_waitpid (SCM pid, SCM options);
SCM scm_status_exit_val (SCM status);
SCM scm_status_term_sig (SCM status);
SCM scm_status_stop_sig (SCM status);
SCM scm_getppid (void);
SCM scm_getuid (void);
SCM scm_getgid (void);
SCM scm_geteuid (void);
SCM scm_getegid (void);
SCM scm_setuid (SCM uid);
SCM scm_setgid (SCM gid);
SCM scm_seteuid (SCM euid);
SCM scm_setegid (SCM egid);
SCM scm_ttyname (SCM port);
SCM scm_execl (SCM filename, SCM args);
SCM scm_execlp (SCM filename, SCM args);
SCM scm_execle (SCM filename, SCM env, SCM args);
SCM scm_fork (void);
SCM scm_uname (void);
SCM scm_environ (SCM env);
SCM scm_tmpnam (void);
SCM scm_mkstemp (SCM tmpl);
SCM scm_open_pipe (SCM pipestr, SCM modes);
SCM scm_close_pipe (SCM port);
SCM scm_utime (SCM pathname, SCM actime, SCM modtime);
SCM scm_access (SCM path, SCM how);
SCM scm_getpid (void);
SCM scm_putenv (SCM str);
SCM scm_setlocale (SCM category, SCM locale);
SCM scm_mknod (SCM path, SCM type, SCM perms, SCM dev);
SCM scm_nice (SCM incr);
SCM scm_sync (void);
SCM scm_crypt (SCM key, SCM salt);
SCM scm_chroot (SCM path);
SCM scm_getlogin (void);
SCM scm_cuserid (void);
SCM scm_getpriority (SCM which, SCM who);
SCM scm_setpriority (SCM which, SCM who, SCM prio);
SCM scm_getpass (SCM prompt);
SCM scm_flock (SCM file, SCM operation);
SCM scm_sethostname (SCM name);
SCM scm_gethostname (void);
void scm_init_posix (void);

#endif  /* SCM_POSIX_H */

/*
  Local Variables:
  c-file-style: "gnu"
  End:
*/
