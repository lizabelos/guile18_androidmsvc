#include "eval.hpp"
#include <cassert>

std::unordered_map<SCM, std::function<SCM(SCM)>> scm_callbacks;

SCM proxy_callback_0() {
    SCM proc = scm_self();
    assert(proc != NULL);
    scm_reset_self(proc);
    auto it = scm_callbacks.find(proc);
    if (it != scm_callbacks.end()) {
        return it->second(mergeArgs());
    }
    throw std::runtime_error("Unknown callback");
}

SCM proxy_callback_1(SCM arg1) {
    SCM proc = scm_self();
    assert(proc != NULL);
    scm_reset_self(proc);
    auto it = scm_callbacks.find(proc);
    if (it != scm_callbacks.end()) {
        return it->second(mergeArgs(arg1));
    }
    throw std::runtime_error("Unknown callback");
}

SCM proxy_callback_2(SCM arg1, SCM arg2) {
    SCM proc = scm_self();
    assert(proc != NULL);
    scm_reset_self(proc);
    auto it = scm_callbacks.find(proc);
    if (it != scm_callbacks.end()) {
        return it->second(mergeArgs(arg1, arg2));
    }
    throw std::runtime_error("Unknown callback");
}

SCM proxy_callback_3(SCM arg1, SCM arg2, SCM arg3) {
    SCM proc = scm_self();
    assert(proc != NULL);
    scm_reset_self(proc);
    auto it = scm_callbacks.find(proc);
    if (it != scm_callbacks.end()) {
        return it->second(mergeArgs(arg1, arg2, arg3));
    }
    throw std::runtime_error("Unknown callback");
}

SCM proxy_callback_4(SCM arg1, SCM arg2, SCM arg3, SCM arg4) {
    SCM proc = scm_self();
    assert(proc != NULL);
    scm_reset_self(proc);
    auto it = scm_callbacks.find(proc);
    if (it != scm_callbacks.end()) {
        return it->second(mergeArgs(arg1, arg2, arg3, arg4));
    }
    throw std::runtime_error("Unknown callback");
}

SCM proxy_callback_5(SCM arg1, SCM arg2, SCM arg3, SCM arg4, SCM arg5) {
    SCM proc = scm_self();
    assert(proc != NULL);
    scm_reset_self(proc);
    auto it = scm_callbacks.find(proc);
    if (it != scm_callbacks.end()) {
        return it->second(mergeArgs(arg1, arg2, arg3, arg4, arg5));
    }
    throw std::runtime_error("Unknown callback");
}

SCM proxy_callback_6(SCM arg1, SCM arg2, SCM arg3, SCM arg4, SCM arg5, SCM arg6) {
    SCM proc = scm_self();
    assert(proc != NULL);
    scm_reset_self(proc);
    auto it = scm_callbacks.find(proc);
    if (it != scm_callbacks.end()) {
        return it->second(mergeArgs(arg1, arg2, arg3, arg4, arg5, arg6));
    }
    throw std::runtime_error("Unknown callback");
}

SCM proxy_callback_7(SCM arg1, SCM arg2, SCM arg3, SCM arg4, SCM arg5, SCM arg6, SCM arg7) {
    SCM proc = scm_self();
    assert(proc != NULL);
    scm_reset_self(proc);
    auto it = scm_callbacks.find(proc);
    if (it != scm_callbacks.end()) {
        return it->second(mergeArgs(arg1, arg2, arg3, arg4, arg5, arg6, arg7));
    }
    throw std::runtime_error("Unknown callback");
}

SCM proxy_callback_8(SCM arg1, SCM arg2, SCM arg3, SCM arg4, SCM arg5, SCM arg6, SCM arg7, SCM arg8) {
    SCM proc = scm_self();
    assert(proc != NULL);
    scm_reset_self(proc);
    printf("proc: %p\n", proc);
    auto it = scm_callbacks.find(proc);
    if (it != scm_callbacks.end()) {
        return it->second(mergeArgs(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8));
    }
    throw std::runtime_error("Unknown callback");
}

SCM proxy_callback_9(SCM arg1, SCM arg2, SCM arg3, SCM arg4, SCM arg5, SCM arg6, SCM arg7, SCM arg8, SCM arg9) {
    SCM proc = scm_self();
    assert(proc != NULL);
    scm_reset_self(proc);
    auto it = scm_callbacks.find(proc);
    if (it != scm_callbacks.end()) {
        return it->second(mergeArgs(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9));
    }
    throw std::runtime_error("Unknown callback");
}

SCM proxy_callback_10(SCM arg1, SCM arg2, SCM arg3, SCM arg4, SCM arg5, SCM arg6, SCM arg7, SCM arg8, SCM arg9, SCM arg10) {
    SCM proc = scm_self();
    assert(proc != NULL);
    scm_reset_self(proc);
    auto it = scm_callbacks.find(proc);
    if (it != scm_callbacks.end()) {
        return it->second(mergeArgs(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10));
    }
    throw std::runtime_error("Unknown callback");
}

SCM proxy_callback_11(SCM arg1, SCM arg2, SCM arg3, SCM arg4, SCM arg5, SCM arg6, SCM arg7, SCM arg8, SCM arg9, SCM arg10, SCM arg11) {
    SCM proc = scm_self();
    assert(proc != NULL);
    scm_reset_self(proc);
    auto it = scm_callbacks.find(proc);
    if (it != scm_callbacks.end()) {
        return it->second(mergeArgs(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11));
    }
    throw std::runtime_error("Unknown callback");
}

SCM proxy_callback_12(SCM arg1, SCM arg2, SCM arg3, SCM arg4, SCM arg5, SCM arg6, SCM arg7, SCM arg8, SCM arg9, SCM arg10, SCM arg11, SCM arg12) {
    SCM proc = scm_self();
    assert(proc != NULL);
    scm_reset_self(proc);
    auto it = scm_callbacks.find(proc);
    if (it != scm_callbacks.end()) {
        return it->second(mergeArgs(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12));
    }
    throw std::runtime_error("Unknown callback");
}