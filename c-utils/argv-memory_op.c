#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>
#include <string.h>

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

int main(int argc, char *argv[], char **env)
{
    printf("atoi(\"%s\") = %d\n", "98993489", atoi("98993489"));
    printf("atoi(\"%s\") = %d\n", "SDFAeevf 9885", atoi("SDFAeevf 9885"));
    puts("");
    display_argv(argc,argv);
    puts("");
    invert_argv(argc,argv);
    puts("");
    puts(argv_single_str(argc, argv," - "));
    puts("");
    printf("Sum of all int program arguments = %d\n", argv_isum(argc,argv));
    puts("");
    display_env(env);
    return 0;
}

/*Find lengths in bytes of all argv*/
int count_argv_bytes(int arg_c, char **arg_v)
{
	int i,j,k;
	for (i=0, k=0; i!=arg_c; i++)
		for(j=0; arg_v[i][j]!='\0';j++,k++) ;
	return k;
}

/*Creates a clone of argv*/
char **argv_clone(int argc, char **argv)
{
    int i;
    char **ptr;
    ptr = (char **)malloc(argc);
    for (i = 0; i < argc; i++)
        ptr[i] = (char *)malloc((argc * (1 + strlen(argv[i]))) * sizeof(char));
    /*+1 for each '\0' of argc*/
    return ptr;
}
/*Prints program arguments entered on the command line */
void display_argv(int argc, char **argv)
{
    int i;
    for (i = 0; i < argc; i++)
        printf("Parameter#%d = \"%s\"\n", i, argv[i]);
}
/*Invert and print the order of command line arguments */
void invert_argv(int argc, char **argv)
{
    int i, n;
    char *ptr, **argv_copy;
    argv_copy = argv_clone(argc, argv);
    for (i = 0; i < argc / 2; i++)
    {
        ptr = argv[i];
        argv_copy[i] = argv[argc - i - 1];
        argv_copy[argc - i - 1] = ptr;
    }
    for (i = 0, n = argc - 1; i < argc; i++, n--)
        printf("Parameter#%d = \"%s\"\n", n, argv_copy[i]);
}
/*Creates a single string with with each argument of argv spaced by a separator*/
char *argv_single_str(int argc, char **argv, char *separator)
{
    int i;
    char *s;
    i = count_argv_bytes(argc, argv);
    s = (char *)malloc((i + 1 + (argc - 1) * strlen(separator)) * sizeof(char));
    /* i+1 -> Adds space for a unique '\0' of the new string */
    /* (argc-1)*strlen(separator) -> the end word doesn't need one */
    for (i = 0; i < argc; i++)
    {
        strcat(s, argv[i]);
        if (i != (argc - 1))
            strcat(s, separator);
    }
    return s;
}

/*Adds the integer numbers inserted as arguments*/
int argv_isum(int argc, char **argv)
{
    int i, total;
    for (i = 1, total = 0; i < argc; i++)
        total += atoi(argv[i]);
    return total;
}

/*Show environment variables*/
void display_env(char **env)
{
    int i;
    char **aux;
    puts("--------- Environment variables: -----------");
    for (aux=env; *env; env++, aux++)
    {
        fprintf(stdout, "%s: \n", *env);
        fprintf(stdout,"\tVar: ");
        for(i=0; *((*aux)+i) != '='; i++)
            fputc( *((*aux)+i), stdout);
        fprintf(stdout, "\n\tVal: %s\n",(strchr(*env, '=') + 1));
        /*strchr(*env++,'=') return the position where character '=' was found*/
        /*the +1 is to point to the position next to '='*/
    }

}