#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "files_op.h"
#include "argv-memory_op.h"
#include "strings_op.h"
#include "list_structure.h"
/*Uncomment the desired library to test:*/
/*#define TEST_FILES_OP*/
/*#define TEST_ARGV_MEMORY_OP*/
/*#define TEST_STRINGS_OP*/
#define TEST_LIST_STRUCTURE

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
#ifdef TEST_STRINGS_OP
    /*Some code to test sting_op.h*/
    char name[DIM + 1], surname[DIM + 1], full_name[2 * DIM + 1];
    int op = 0;
    do
    {
        if (y_or_n_p("Do you want to quit? yes or no?"))
            break;
        else
        {
            init_str(name), init_str(surname), init_str(full_name);
            printf("Insert first name: ");
            scanf("%s", name);
            cleanstdin();
            printf("Insert surname: ");
            scanf("%s", surname);
            printf("Full name: %s %s, aka: ", name, surname);
            delenter(surname);
            strcpy(full_name, surname);
            strcat(full_name, NAME_SEP);
            strcat(full_name, name);
            puts(full_name);
            cleanstdin();
            printf("Insert a full name: ");
            fgets(full_name, sizeof(name), stdin);
            printf("Full name: %s\n", full_name);
            printf("\"%s\" has %d letters, ", full_name, strcount(full_name));
            printf("\'%c\' is the Max Ascii character ", Max_Ascii(full_name));
            printf("and \'%c\' is the 3º character\n", nth_char(full_name, 3));
            printf("After summing +1 to each character we get:\n\t %s\n", next_char(full_name));
            printf("Toggle string letters:\n\t %s\n", UpDown(full_name));
            printf("Remove string characters in lowercase:\n\t %s\n", All_Big(full_name));
            printf("Turn upercase to lowercase:\n\t %s\n", strlwr(full_name));
            printf("Turn lowercase to upercase:\n\t %s\n", struper(full_name));
            printf("Replace letters with spaces:\n\t\"%s\"\n", allspaces(full_name));
            printf("Delete spaces:\n\t\"%s\"\n", init_str(full_name));
        }
    } while (op != 1);
#endif
#ifdef TEST_LIST_STRUCTURE
    List *list;
    Init(&list);
    Load(&list);
    printf("\n\n***** Display Content *****\n\n");
    List_display(list);
    Save(&list);
    Remove(&list, 1);
    printf("\n\n***** Display Content *****\n\n");
    List_display(list);
    Load_bin(&list);
    printf("\n\n***** Display Content *****\n\n");
    List_display(list);
#endif
    return 0;
}