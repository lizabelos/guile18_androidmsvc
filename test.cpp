#include <libguile.hpp>

static void inner_main(void *closure, int argc, char **argv) {
    scm_c_eval_string("(guile-version)");
}

void error_callback(const char *message) {
    printf("Error: %s\n");
}

int main(int argc, char **argv) {
    scm_use_embedded_ice9();
    scm_boot_guile(argc, argv, inner_main, nullptr);
    return 0; /* never reached */
}
