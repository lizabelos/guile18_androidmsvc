#include <libguile.h>

static void inner_main(void *closure, int argc, char **argv) {
    /* module initializations would go here */
   // scm_shell(argc, argv);
}

int main(int argc, char **argv) {
    scm_boot_guile(argc, argv, inner_main, 0);
    return 0; /* never reached */
}