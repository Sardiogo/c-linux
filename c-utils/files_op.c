#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clean_enter(void)
{
    char ch, buffer[50];
    if ((ch = getc(stdin))!='\n')
        ungetc(ch,stdin);
    else
        while (ch == '\n')
            ch = getc(stdin);
}

FILE *open_check(void)
{
    FILE *f;
    char name[100], mode[6];
    clean_enter(); /*Test enter*/
    puts("Insert file name:");
    fgets(name, sizeof(name), stdin);
    clean_enter(); /*Test enter*/
    puts("Insert file open mode (opt:r,w,a,r+,w+,a+,'opt'b):");
    fgets(mode, sizeof(mode), stdin);
    f = fopen(name, mode);
    if (f == NULL)
    {
        perror("Error opening file");
        printf("\"%s\"\n", name);
        exit(EXIT_FAILURE);
    }
    else
        printf("%s file opened successfully!!!\n", name);
    return f;
}

void ffcopy(void)
{
    FILE *fin, *fout;
    fin = open_check();
    fout = open_check();
    int ch;
    while ((ch = fgetc(fin)) != EOF)
        fputc(ch, fout);
    fclose(fin);
    fclose(fout);
}

void insert_lines(void)
{
    FILE *f;
    int n;
    char str[256];
    f = open_check();
    clean_enter(); /*Test enter*/
    puts("How many lines?");
    scanf("%d", &n);
    clean_enter(); /*Test enter*/
    puts("Insert line strat text:");
    fgets(str,sizeof(str),stdin);
    for(int i=0;i<n;i++){
        fprintf(f,"%s %d\n",str,i+1);
        if (ferror(f))
        {
            perror("Error writing to file");
            break;
        }
    }
}

int main(void)
{
    int option;
    do{
        printf("Choose operation number:\n");
        printf("\n\t1: insert_lines()");
        printf("\n\t2: fcopy()");
        printf("\n\t3: Exit");
        printf("\n\n\tOption:");
        fscanf(stdin," %d", &option);
        switch (option){
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
    } while (option != 4);
    return 0;
}
