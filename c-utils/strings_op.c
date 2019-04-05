#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define DIM 20
#define NAME_SEP ", "

/*1 Counts the number of letters in a sentence */
    int strcount(char *s);
/*2 Find the largest ASCII in a string */
    char Max_Ascii(char *str);
/*3 Converts each character in the following ASCII  */
    char *next_char(char *s);
/*4 Toggle string letters between uppercase and lowercase */
    char *UpDown(char *s);
/*5 Replace string letters with spaces */
    char *allspaces(char *s);
/*6 Place strings only in lowercase */
    char *strlwr(char *str);
/*7 Initializes string */
    char *init_str(char *s);
/*6 Only return string characters that are in uppercase */
    char *All_Big(char *s);
/*7 Find the nth character in the string */
    char nth_char(char *s, int n);
/*8 Clears all upper characters in the string */
    char *StrDelUpper(char *s);
/*9 Clean stdin */
    void cleanstdin();
/*10 Replace \ n with space */
    char *delenter(char *s);
/*11 Print a string foward and backword*/
    char *forward_back(char *s);
/*12 Test the answer to a given question*/
    int y_or_n_p(char *question);
    /*
'\0' = NULL
    The '\ 0' character whose ASCII code is 0 has nothing to do with the '0' character whose ASCII code is 48.
    A string always corresponds to a vector of characters with a special character as a delimiter (''\0 ").
'n'
    1 char, a char is one byte on all architectures.
"n"
    2 chars, the string with one character, but it takes two characters of storage
    countining one n and one terminating NULL char.
    The string is implicitly null-terminated, so it will take up one more byte than the observable number of characters.
'\n'
    1 char, 1byte, the newline (ctrl-J on ASCII based systems)
"\n"
    2 chars, 2 bytes, as \n stand for "new line" which takes one byte, plus one byte for the null char.
"\\n"
    3 chars, 3 bytes, one for \, one for newline and the null character
""
    1 char, 1 byte, just the null character.
    The string literal, countining one terminating NULL char.
*/

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
            printf("Replace letters with spaces:\n\t\"%s\"\n", allspaces(full_name));
            printf("Delete spaces:\n\t\"%s\"\n", init_str(full_name));
        }
    } while (op!= 1);
    return 0;
}

/*1 Counts the number of letters in a sentence */
int strcount(char *s)
{
	int i,count;
	for (i=count=0 ; s[i]!='\0' ; i++)
		if (isalpha(s[i]))
			count++;
	return count;
}

/*2 Find the largest ASCII in a string */
char Max_Ascii(char *str)
{
    int i;
    char res = '\0'; /*Lowest ASCII Code */
    for (i=0; str[i]!='\0';i++)
		res = res > str[i] ? res : str[i];
	return res;
}

/*3 Converts each character in the following ASCII  */
char *next_char(char *s){
	int i;
	for (i=0;s[i]!='\0';i++)
		s[i]=s[i]+1;
	return s;
}

/*4 Toggle string letters between uppercase and lowercase */
char *UpDown(char *s)
{
	int i;
	for (i=0;s[i]!='\0'; i++)
			s[i] = (i%2==0) ? toupper(s[i]) : tolower(s[i]);
	return s;
}

/*5 Replace string letters with spaces */
char *allspaces(char *s)
{
	int i;
	for (i=0;s[i]!='\0'; i++)
		s[i]=' ';
	return s;
}

/*6 Place strings only in lowercase */
char *strlwr(char *str)
{
	int i;
	for (i=0 ; str[i]!='\0' ; i++)
		str[i] = tolower(str[i]);
	return str;
}

/*7 Initializes string */
char *init_str(char *s)
{
	s[0] = '\0';
	return s;
}

/*Only return string characters that are in uppercase */
char * All_Big(char *s){
  int i,j;
  for (i=j=0; s[i]!='\0'; i++)
	 if (isupper(s[i]))
		s[j++]=s[i];
  s[j]='\0';
  return s;
}

/*7 Find the nth character in the string */
char nth_char(char *s, int n)
{
    return s[n - 1]; /*Because the indexes of the vectors start at 0*/
}

/*8 Clears all upper characters in the string */
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

/*9 Clean stdin */
void cleanstdin()
{
    char s[100];
    fgets(s, sizeof(s), stdin);
}

/*10 Replace \n with space */
char *delenter(char *s)
{
	int i;
	for (i=0;s[i]!='\0'; i++)
		if (s[i]=='\n')
            s[i]=' ';
	return s;
}

/*11 Print a string foward and backword*/
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

/*12 Test the answer to a given question*/
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