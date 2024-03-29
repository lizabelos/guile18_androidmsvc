#ifdef HAVE_POSIX
 scm_c_define_gsubr (s_scm_chmod, 2, 0, 0, (SCM (*)()) scm_chmod); ;
 scm_c_define_gsubr (s_scm_umask, 0, 1, 0, (SCM (*)()) scm_umask); ;
 scm_c_define_gsubr (s_scm_open_fdes, 2, 1, 0, (SCM (*)()) scm_open_fdes); ;
 scm_c_define_gsubr (s_scm_open, 2, 1, 0, (SCM (*)()) scm_open); ;
 scm_c_define_gsubr (s_scm_close, 1, 0, 0, (SCM (*)()) scm_close); ;
 scm_c_define_gsubr (s_scm_close_fdes, 1, 0, 0, (SCM (*)()) scm_close_fdes); ;
 scm_sym_regular = scm_permanent_object (scm_from_locale_symbol ("regular")) ;
 scm_sym_directory = scm_permanent_object (scm_from_locale_symbol ("directory")) ;
 scm_sym_block_special = scm_permanent_object (scm_from_locale_symbol ("block-special")) ;
 scm_sym_char_special = scm_permanent_object (scm_from_locale_symbol ("char-special")) ;
 scm_sym_fifo = scm_permanent_object (scm_from_locale_symbol ("fifo")) ;
 scm_sym_sock = scm_permanent_object (scm_from_locale_symbol ("socket")) ;
 scm_sym_unknown = scm_permanent_object (scm_from_locale_symbol ("unknown")) ;
 scm_c_define_gsubr (s_scm_stat, 1, 0, 0, (SCM (*)()) scm_stat); ;
 scm_c_define_gsubr (s_scm_rename, 2, 0, 0, (SCM (*)()) scm_rename); ;
 scm_c_define_gsubr (s_scm_delete_file, 1, 0, 0, (SCM (*)()) scm_delete_file); ;
 scm_c_define_gsubr (s_scm_mkdir, 1, 1, 0, (SCM (*)()) scm_mkdir); ;
 scm_c_define_gsubr (s_scm_rmdir, 1, 0, 0, (SCM (*)()) scm_rmdir); ;
 scm_c_define_gsubr (s_scm_directory_stream_p, 1, 0, 0, (SCM (*)()) scm_directory_stream_p); ;
 scm_c_define_gsubr (s_scm_opendir, 1, 0, 0, (SCM (*)()) scm_opendir); ;
 scm_c_define_gsubr (s_scm_readdir, 1, 0, 0, (SCM (*)()) scm_readdir); ;
 scm_c_define_gsubr (s_scm_rewinddir, 1, 0, 0, (SCM (*)()) scm_rewinddir); ;
 scm_c_define_gsubr (s_scm_closedir, 1, 0, 0, (SCM (*)()) scm_closedir); ;
 scm_c_define_gsubr (s_scm_chdir, 1, 0, 0, (SCM (*)()) scm_chdir); ;
 scm_c_define_gsubr (s_scm_getcwd, 0, 0, 0, (SCM (*)()) scm_getcwd); ;
 scm_c_define_gsubr (s_scm_fsync, 1, 0, 0, (SCM (*)()) scm_fsync); ;
 scm_c_define_gsubr (s_scm_copy_file, 2, 0, 0, (SCM (*)()) scm_copy_file); ;
 #endif
 scm_c_define_gsubr (s_scm_dirname, 1, 0, 0, (SCM (*)()) scm_dirname); ;
 scm_c_define_gsubr (s_scm_basename, 1, 1, 0, (SCM (*)()) scm_basename); ;
