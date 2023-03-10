#include <libguile.hpp>

static void inner_main(void *closure, int argc, char **argv) {
    /* module initializations would go here */
   // scm_shell(argc, argv);

    register_callback("testfn", [](SCM args) {
        printf("testfn called\n");
        return SCM_UNSPECIFIED;
    }, 0);
    register_callback("testfn1", [](SCM args) {
        printf("testfn1 called\n");
        return SCM_UNSPECIFIED;
    }, 1);
    register_callback("testfn2", [](SCM args) {
        printf("testfn2 called\n");
        return SCM_UNSPECIFIED;
    }, 2);
    register_callback("testfn3", [](SCM args) {
        printf("testfn3 called\n");
        return SCM_UNSPECIFIED;
    }, 3);
    register_callback("testfn4", [](SCM args) {
        printf("testfn4 called\n");
        return SCM_UNSPECIFIED;
    }, 4);
    register_callback("testfn5", [](SCM args) {
        printf("testfn5 called\n");
        return SCM_UNSPECIFIED;
    }, 5);
    register_callback("testfn6", [](SCM args) {
        printf("testfn6 called\n");
        return SCM_UNSPECIFIED;
    }, 6);
    register_callback("testfn7", [](SCM args) {
        printf("testfn7 called\n");
        return SCM_UNSPECIFIED;
    }, 7);
    register_callback("testfn8", [](SCM args) {
        printf("testfn8 called\n");
        return SCM_UNSPECIFIED;
    }, 8);
    register_callback("testfn9", [](SCM args) {
        printf("testfn9 called\n");
        return SCM_UNSPECIFIED;
    }, 9);

    scm_c_eval_string("(testfn)");
    scm_c_eval_string("(testfn1 1)");
    scm_c_eval_string("(testfn2 1 2)");
    scm_c_eval_string("(testfn3 1 2 3)");
    scm_c_eval_string("(testfn4 1 2 3 4)");
    scm_c_eval_string("(testfn5 1 2 3 4 5)");
    scm_c_eval_string("(testfn6 1 2 3 4 5 6)");
    scm_c_eval_string("(testfn7 1 2 3 4 5 6 7)");
    scm_c_eval_string("(testfn8 1 2 3 4 5 6 7 8)");
    scm_c_eval_string("(testfn9 1 2 3 4 5 6 7 8 9)");
}

int main(int argc, char **argv) {
    scm_boot_guile(argc, argv, inner_main, 0);
    return 0; /* never reached */
}
