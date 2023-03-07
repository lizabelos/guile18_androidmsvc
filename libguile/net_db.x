 scm_host_not_found_key = scm_permanent_object (scm_from_locale_symbol ("host-not-found")) ;
 scm_try_again_key = scm_permanent_object (scm_from_locale_symbol ("try-again")) ;
 scm_no_recovery_key = scm_permanent_object (scm_from_locale_symbol ("no-recovery")) ;
 scm_no_data_key = scm_permanent_object (scm_from_locale_symbol ("no-data")) ;
 scm_c_define_gsubr (s_scm_gethost, 0, 1, 0, (SCM (*)()) scm_gethost); ;
