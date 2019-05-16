#include <stdio.h>
#include "files_op.h"

int main(void)
{

    int option;
    do
    {
        printf("Choose operation number:\n");
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
    return 0;
}