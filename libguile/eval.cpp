#include "eval.hpp"

std::unordered_map<SCM, std::function<SCM(SCM)>> scm_callbacks;

SCM proxy_callback_0(SCM proc) {
    auto it = scm_callbacks.find(proc);
    if (it != scm_callbacks.end()) {
        return it->second(mergeArgs());
    }
    throw std::runtime_error("Unknown callback");
}

SCM proxy_callback_1(SCM proc, SCM arg1) {
    auto it = scm_callbacks.find(proc);
    if (it != scm_callbacks.end()) {
        return it->second(mergeArgs(arg1));
    }
    throw std::runtime_error("Unknown callback");
}

SCM proxy_callback_2(SCM proc, SCM arg1, SCM arg2) {
    auto it = scm_callbacks.find(proc);
    if (it != scm_callbacks.end()) {
        return it->second(mergeArgs(arg1, arg2));
    }
    throw std::runtime_error("Unknown callback");
}

SCM proxy_callback_3(SCM proc, SCM arg1, SCM arg2, SCM arg3) {
    auto it = scm_callbacks.find(proc);
    if (it != scm_callbacks.end()) {
        return it->second(mergeArgs(arg1, arg2, arg3));
    }
    throw std::runtime_error("Unknown callback");
}

SCM proxy_callback_4(SCM proc, SCM arg1, SCM arg2, SCM arg3, SCM arg4) {
    auto it = scm_callbacks.find(proc);
    if (it != scm_callbacks.end()) {
        return it->second(mergeArgs(arg1, arg2, arg3, arg4));
    }
    throw std::runtime_error("Unknown callback");
}

SCM proxy_callback_5(SCM proc, SCM arg1, SCM arg2, SCM arg3, SCM arg4, SCM arg5) {
    auto it = scm_callbacks.find(proc);
    if (it != scm_callbacks.end()) {
        return it->second(mergeArgs(arg1, arg2, arg3, arg4, arg5));
    }
    throw std::runtime_error("Unknown callback");
}

SCM proxy_callback_6(SCM proc, SCM arg1, SCM arg2, SCM arg3, SCM arg4, SCM arg5, SCM arg6) {
    auto it = scm_callbacks.find(proc);
    if (it != scm_callbacks.end()) {
        return it->second(mergeArgs(arg1, arg2, arg3, arg4, arg5, arg6));
    }
    throw std::runtime_error("Unknown callback");
}

SCM proxy_callback_7(SCM proc, SCM arg1, SCM arg2, SCM arg3, SCM arg4, SCM arg5, SCM arg6, SCM arg7) {
    auto it = scm_callbacks.find(proc);
    if (it != scm_callbacks.end()) {
        return it->second(mergeArgs(arg1, arg2, arg3, arg4, arg5, arg6, arg7));
    }
    throw std::runtime_error("Unknown callback");
}

SCM proxy_callback_8(SCM proc, SCM arg1, SCM arg2, SCM arg3, SCM arg4, SCM arg5, SCM arg6, SCM arg7, SCM arg8) {
    auto it = scm_callbacks.find(proc);
    if (it != scm_callbacks.end()) {
        return it->second(mergeArgs(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8));
    }
    throw std::runtime_error("Unknown callback");
}

SCM proxy_callback_9(SCM proc, SCM arg1, SCM arg2, SCM arg3, SCM arg4, SCM arg5, SCM arg6, SCM arg7, SCM arg8, SCM arg9) {
    auto it = scm_callbacks.find(proc);
    if (it != scm_callbacks.end()) {
        return it->second(mergeArgs(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9));
    }
    throw std::runtime_error("Unknown callback");
}