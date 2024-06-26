/* classes: h_files */

#ifndef SCM_FILESYS_H
#define SCM_FILESYS_H

/* Copyright (C) 1995,1997,1998,1999,2000,2001, 2006 Free Software Foundation, Inc.
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



extern scm_t_bits scm_tc16_dir;

#define SCM_DIR_FLAG_OPEN (((int64_t) 1) << 16)

#define SCM_DIRP(x) (!SCM_IMP (x) && (SCM_TYP16 (x) == scm_tc16_dir))
#define SCM_DIR_OPEN_P(x) (SCM_CELL_WORD_0 (x) & SCM_DIR_FLAG_OPEN)



SCM scm_chown (SCM object, SCM owner, SCM group);
SCM scm_chmod (SCM object, SCM mode);
SCM scm_umask (SCM mode);
SCM scm_open_fdes (SCM path, SCM flags, SCM mode);
SCM scm_open (SCM path, SCM flags, SCM mode);
SCM scm_close (SCM fd_or_port);
SCM scm_close_fdes (SCM fd);
SCM scm_stat (SCM object);
SCM scm_link (SCM oldpath, SCM newpath);
SCM scm_rename (SCM oldname, SCM newname);
SCM scm_delete_file (SCM str);
SCM scm_mkdir (SCM path, SCM mode);
SCM scm_rmdir (SCM path);
SCM scm_directory_stream_p (SCM obj);
SCM scm_opendir (SCM dirname);
SCM scm_readdir (SCM port);
SCM scm_rewinddir (SCM port);
SCM scm_closedir (SCM port);
SCM scm_chdir (SCM str);
SCM scm_getcwd (void);
SCM scm_select (SCM reads, SCM writes, SCM excepts, SCM secs, SCM msecs);
SCM scm_fcntl (SCM object, SCM cmd, SCM value);
SCM scm_fsync (SCM object);
SCM scm_symlink (SCM oldpath, SCM newpath);
SCM scm_readlink (SCM path);
SCM scm_lstat (SCM str);
SCM scm_copy_file (SCM oldfile, SCM newfile);
SCM scm_dirname (SCM filename);
SCM scm_basename (SCM filename, SCM suffix);

void scm_init_filesys (void);

#endif  /* SCM_FILESYS_H */

/*
  Local Variables:
  c-file-style: "gnu"
  End:
*/
