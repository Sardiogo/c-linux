#ifndef ARGV_MEMORY_OP
#define ARGV_MEMORY_OP
    /*Find lengths in bytes of all argv*/
    int count_argv_bytes(int arg_c, char **arg_v);
    /*Creates a clone of argv*/
    char **argv_clone(int argc, char **argv);
    /*Prints program arguments entered on the command line */
    void display_argv(int argc, char **argv);
    /*Invert and print the order of command line arguments */
    void invert_argv(int argc, char **argv);
    /*Creates a single string with with each argument of argv spaced by a separator*/
    char *argv_single_str(int argc, char **argv, char *separator);
    /*Adds the integer numbers inserted as arguments*/
    int argv_isum(int argc, char **argv);
    /*Show environment variables*/
    void display_env(char **env);
#endif