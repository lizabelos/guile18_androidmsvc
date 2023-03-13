#include <libguile.hpp>

static void inner_main(void *closure, int argc, char **argv) {
    SCM k = scm_c_eval_string("(+ 1 1)");
    int res = scm_to_int32(k);
    printf("%d\n", res);
}

int main(int argc, char **argv) {
    scm_use_embedded_ice9();
    scm_boot_guile(argc, argv, inner_main, nullptr);
    return 0; /* never reached */
}
