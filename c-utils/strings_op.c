#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define DIM 64
#define NAME_SEP ", "

/*Counts the number of letters in a sentence */
    int strcount(char *s);
/*Find the largest ASCII in a string */
    char Max_Ascii(char *str);
/*Converts each character in the following ASCII  */
    char *next_char(char *s);
/*Toggle string letters between uppercase and lowercase */
    char *UpDown(char *s);
/*Replace string letters with spaces */
    char *allspaces(char *s);
/*Place strings only in lowercase */
    char *strlwr(char *str);
/*Place strings only in Upercase */
    char *struper(char *str);
/*Initializes string */
    char *init_str(char *s);
/*Remove string characters in lowercase */
    char *All_Big(char *s);
/*Find the nth character in the string */
    char nth_char(char *s, int n);
/*Clears all upper characters in the string */
    char *StrDelUpper(char *s);
/*Clean stdin */
    void cleanstdin();
/*Replace \ n with space */
    char *delenter(char *s);
/*Print a string foward and backword*/
    char *forward_back(char *s);
/*Test the answer to a given question*/
    int y_or_n_p(char *question);

/*Some code to test sting_op.h*/
int main(void)
{
    char name[DIM+1], surname[DIM+1], full_name[2*DIM+1];
    int op=0;
    do{
        if (y_or_n_p("Do you want to quit? yes or no?"))
            break;
        else{ 
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
            printf("After summing +1 to each character we get:\n\t %s\n",next_char(full_name));
            printf("Toggle string letters:\n\t %s\n",UpDown(full_name));
            printf("Remove string characters in lowercase:\n\t %s\n", All_Big(full_name));
            printf("Turn upercase to lowercase:\n\t %s\n", strlwr(full_name));
            printf("Turn lowercase to upercase:\n\t %s\n", struper(full_name));
            printf("Replace letters with spaces:\n\t\"%s\"\n", allspaces(full_name));
            printf("Delete spaces:\n\t\"%s\"\n", init_str(full_name));
        }
    } while (op!= 1);
    return 0;
}

/*Counts the number of letters in a sentence */
int strcount(char *s)
{
    int i,count;
    for (i=count=0 ; s[i]!='\0' ; i++)
        if (isalpha(s[i]))
            count++;
    return count;
}

/*Find the largest ASCII in a string */
char Max_Ascii(char *str)
{
    int i;
    char res = '\0'; /*Lowest ASCII Code */
    for (i=0; str[i]!='\0';i++)
        res = res > str[i] ? res : str[i];
    return res;
}

/*Converts each character in the following ASCII  */
char *next_char(char *s)
{
    int i;
    for (i=0;s[i]!='\0';i++)
        s[i]=s[i]+1;
    return s;
}

/*Toggle string letters between uppercase and lowercase */
char *UpDown(char *s)
{
    int i;
    for (i=0;s[i]!='\0'; i++)
        s[i] = (i%2==0) ? toupper(s[i]) : tolower(s[i]);
    return s;
}

/*Replace string letters with spaces */
char *allspaces(char *s)
{
    int i;
    for (i=0;s[i]!='\0'; i++)
        s[i]=' ';
    return s;
}

/*Place strings only in lowercase */
char *strlwr(char *str)
{
    int i;
    for (i=0 ; str[i]!='\0' ; i++)
        str[i] = tolower(str[i]);
    return str;
}

/*Place strings only in Upercase */
char *struper(char *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
        str[i] = toupper(str[i]);
    return str;
}

/*Initializes string */
char *init_str(char *s)
{
    s[0] = '\0';
    return s;
}

/*Remove string characters in lowercase */
char * All_Big(char *s)
{
    int i,j;
    for (i=j=0; s[i]!='\0'; i++)
        if (isupper(s[i]))
          s[j++]=s[i];
    s[j]='\0';
    return s;
}

/*Find the nth character in the string */
char nth_char(char *s, int n)
{
    return s[n - 1]; /*Because the indexes of the vectors start at 0*/
}

/*Clears all upper characters in the string */
char *StrDelUpper(char *s)
{
    char *prim, *ptr;
    prim = ptr = s;
    while (*s){ /* or (*s!='\0') */
        /*if uppercase - does not copy character
         for return string*/
        if (!isupper(*s))
          *ptr++=*s;
        s++;
    }
    *ptr='\0';
    return prim;
}

/*Clean stdin */
void cleanstdin()
{
    char s[256];
    fgets(s, sizeof(s), stdin);
}

/*Replace \n with space */
char *delenter(char *s)
{
    int i;
    for (i=0;s[i]!='\0'; i++)
        if (s[i]=='\n')
            s[i]=' ';
    return s;
}

/*Print a string foward and backword*/
char *forward_back(char *s)
{
    char *ptr = s;
    while (*s == '\0' || *s == '\n'){
        printf("Insert a string: ");
        fgets(s, sizeof(s), stdin);
    }
    /*Print string:*/
    if (*ptr == '\0')
        return s;
    while (*ptr != '\0')
        putchar(*ptr++);
    /*Print Inverted string:*/
    ptr--; /*because '\0'*/
    while (ptr >= s)
        putchar(*ptr--);
    printf("\n");
    return s;
}

/*Test the answer to a given question*/
int y_or_n_p(char *question)
{
    fputs(question, stdout);
    while (1){
        int c, answer;
        /* Write a space to separate answer from question. */
        fputc(' ', stdout);
        /* Read the first character of the line.This should be the answer character, but might not be. */
        c = tolower(fgetc(stdin));
        answer = c;
        /* Discard rest of input line. */
        while (c != '\n' && c != EOF)
            c = fgetc(stdin);
        /* Obey the answer if it was valid. */
        if (answer == 'y')
            return 1;
        if (answer == 'n')
            return 0;
        /* Answer was invalid: ask for valid answer. */
        fputs("Please answer y or n:", stdout);
    }
}