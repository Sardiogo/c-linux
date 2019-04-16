#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILES_PATH "./files/"

void clean_enter(void)
{
    char ch;
    if ((ch = getc(stdin))!='\n')
        ungetc(ch,stdin);
}

void str_creator(char *str, char c)
{
    int i;
    char ch;
    for (i=0; ((ch = getc(stdin)) != c); i++){
        str[i]=ch;
    }
    str[i]='\0';
}

long int file_bytes(FILE *fp, long int type_size)
{
    long int n_bytes, old_pos;
    old_pos = ftell(fp);
    fseek(fp, 0L, SEEK_END);
    n_bytes = ftell(fp) / type_size;
    fseek(fp, old_pos, SEEK_SET);
    return n_bytes;
}

FILE *open_check(void)
{
    FILE *f;
    char name[128], mode[8], fpath_name[128] = FILES_PATH;
    puts("Insert file name:");
    clean_enter(); /*Test enter*/
    str_creator(name,'\n');
    strcat(fpath_name, name);
    puts("Insert file open mode (opt:r,w,a,r+,w+,a+,'opt'b):");
    str_creator(mode, '\n');
    f = fopen(fpath_name, mode);
    if (f == NULL)
    {
        perror("Error opening file");
        printf("\"%s\"\n", fpath_name);
        exit(EXIT_FAILURE);
    }
    else{
        printf("file %s opened successfully!!!\n", fpath_name);
        if (!feof(f))
            printf("This file has %ld bytes\n", file_bytes(f, sizeof(char)));
    }
        return f;
}

void ffcopy(void)
{
    FILE *fin, *fout;
    puts("Source file");
    fin = open_check();
    puts("Destiny file");
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
    puts("How many lines?");
    scanf(" %d", &n);
    puts("Insert line strat text:");
    clean_enter(); /*Test enter*/
    str_creator(str, '\n');
    for(int i=0;i<n;i++){
        fprintf(f,"%-3d %s\n",i+1,str);
        if (ferror(f)){
            perror("Error writing to file");
            break;
        }
    }
    fclose(f);
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
        fscanf(stdin, " %d", &option);
        clean_enter(); /*Test enter*/
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
    } while (option != 3);
    return 0;
}
