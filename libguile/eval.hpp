#ifndef GUILE_EVAL_HPP
#define GUILE_EVAL_HPP

#include <libguile.h>

#include <unordered_map>
#include <stdexcept>
#include <utility>
#include <algorithm>
#include <functional>

extern std::unordered_map<SCM, std::function<SCM(SCM)>> scm_callbacks;

template <typename ...Args> inline SCM mergeArgs(SCM t, Args... args) {
    return scm_cons(t, mergeArgs(args...));
}

inline SCM mergeArgs(SCM t) {
    return t;
}

inline SCM mergeArgs() {
    return scm_list_n(SCM_UNDEFINED);
}

SCM proxy_callback_0(SCM proc);
SCM proxy_callback_1(SCM proc, SCM arg1);
SCM proxy_callback_2(SCM proc, SCM arg1, SCM arg2);
SCM proxy_callback_3(SCM proc, SCM arg1, SCM arg2, SCM arg3);
SCM proxy_callback_4(SCM proc, SCM arg1, SCM arg2, SCM arg3, SCM arg4);
SCM proxy_callback_5(SCM proc, SCM arg1, SCM arg2, SCM arg3, SCM arg4, SCM arg5);
SCM proxy_callback_6(SCM proc, SCM arg1, SCM arg2, SCM arg3, SCM arg4, SCM arg5, SCM arg6);
SCM proxy_callback_7(SCM proc, SCM arg1, SCM arg2, SCM arg3, SCM arg4, SCM arg5, SCM arg6, SCM arg7);
SCM proxy_callback_8(SCM proc, SCM arg1, SCM arg2, SCM arg3, SCM arg4, SCM arg5, SCM arg6, SCM arg7, SCM arg8);
SCM proxy_callback_9(SCM proc, SCM arg1, SCM arg2, SCM arg3, SCM arg4, SCM arg5, SCM arg6, SCM arg7, SCM arg8, SCM arg9);

inline void register_callback(std::string name, std::function<SCM(SCM)> callback, int req = 0) {
    SCM proc;
    switch (req) {
        case 0:
            proc = scm_c_define_gsubr(name.c_str(), 0, 0, 0, reinterpret_cast<SCM (*)(void)>(proxy_callback_0));
            break;
        case 1:
            proc = scm_c_define_gsubr(name.c_str(), 1, 0, 0, reinterpret_cast<SCM (*)(void)>(proxy_callback_1));
            break;
        case 2:
            proc = scm_c_define_gsubr(name.c_str(), 2, 0, 0, reinterpret_cast<SCM (*)(void)>(proxy_callback_2));
            break;
        case 3:
            proc = scm_c_define_gsubr(name.c_str(), 3, 0, 0, reinterpret_cast<SCM (*)(void)>(proxy_callback_3));
            break;
        case 4:
            proc = scm_c_define_gsubr(name.c_str(), 4, 0, 0, reinterpret_cast<SCM (*)(void)>(proxy_callback_4));
            break;
        case 5:
            proc = scm_c_define_gsubr(name.c_str(), 5, 0, 0, reinterpret_cast<SCM (*)(void)>(proxy_callback_5));
            break;
        case 6:
            proc = scm_c_define_gsubr(name.c_str(), 6, 0, 0, reinterpret_cast<SCM (*)(void)>(proxy_callback_6));
            break;
        case 7:
            proc = scm_c_define_gsubr(name.c_str(), 7, 0, 0, reinterpret_cast<SCM (*)(void)>(proxy_callback_7));
            break;
        case 8:
            proc = scm_c_define_gsubr(name.c_str(), 8, 0, 0, reinterpret_cast<SCM (*)(void)>(proxy_callback_8));
            break;
        case 9:
            proc = scm_c_define_gsubr(name.c_str(), 9, 0, 0, reinterpret_cast<SCM (*)(void)>(proxy_callback_9));
            break;
        default:
            throw std::runtime_error("Too many arguments");
    }
    scm_callbacks[proc] = std::move(callback);
}

#endif