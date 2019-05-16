#include <stdio.h>
#include <stdlib.h>
#include "files_op.h"
#include "argv-memory_op.h"

#define TEST_FILES_OP
 #define TEST_ARGV_MEMORY_OP

int main(int argc, char *argv[], char **env)
{
#ifdef TEST_FILES_OP
    int option;
    do
    {
        printf("files_op: Choose operation number:\n");
        printf("\n\t1: insert_lines()");
        printf("\n\t2: fcopy()");
        printf("\n\t3: Exit");
        printf("\n\n\tOption:");
        fscanf(stdin, " %d", &option);
        clean_enter(); /*Test enter*/
        switch (option)
        {
        case 1:
            insert_lines();
            break;
        case 2:
            ffcopy();
            break;
        case 3:
            break;
        default:
            puts("Invalid Option!!!");
        }
    } while (option != 3);
#endif
#ifdef TEST_ARGV_MEMORY_OP
    printf("atoi(\"%s\") = %d\n", "98993489", atoi("98993489"));
    printf("atoi(\"%s\") = %d\n", "SDFAeevf 9885", atoi("SDFAeevf 9885"));
    puts("");
    display_argv(argc, argv);
    puts("");
    invert_argv(argc, argv);
    puts("");
    puts(argv_single_str(argc, argv, " - "));
    puts("");
    printf("Sum of all int program arguments = %d\n", argv_isum(argc,argv));
    puts("");
    display_env(env);
#endif

    return 0;
}