#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define DIM 20
#define NAME_SEP ", "

/*1 counts the number of letters in a sentence */
    int strcount(char *s);
/*2 Find the largest ASCII in a string */
    char Max_Ascii(char *str);
/*3 Converts each character in the following ASCII  */
    char *next_char(char *s);
/*4 Toggle string letters between uppercase and lowercase */
    char *UpDown(char *s);
/*5 replace string letters with spaces */
    char *allspaces(char *s);
/*6 Place strings only in lowercase */
    char *strlwr(char *str);
/*7 initializes string */
    char *init_str(char *s);
/*6 Only put strings in uppercase */
    char *All_Big(char *s);
/*7 find the nth character in the string */
    char nth_char(char *s, int n);
/*8 Clears all upper characters in the string */
    char *StrDelUpper(char *s);
/*9 Clean stdin */
    void cleanstdin();
/*10 replace \ n with space */
    char *delenter(char *s);
/*
'\ 0' = NULL
    The '\ 0' character whose ASCII code is 0 has nothing to do with the '0' character whose ASCII code is 48.
    A string always corresponds to a vector of characters with a special character as a delimiter ('' \ 0 ").
'n'
    1 char, a char is one byte on all architectures.
"n"
    2 chars, the string with one character, but it takes two characters of storage
    countining one n and one terminating NULL char.
    The string is implicitly null-terminated, so it will take up one more byte than the observable number of characters.
'\ n'
    1 char, 1byte, the newline (ctrl-J on ASCII based systems)
"\ n"
    2 chars, 2 bytes, as \ n stand for "new line" which takes one byte, plus one byte for the null char.
"\\ n"
    3 chars, 3 bytes, one for \, one for newline and the null character
""
    1 char, 1 byte, just the null character.
    The string literal, countining one terminating NULL char.
*/

int main(void) {
    char name[DIM + 1], surname[DIM + 1], full_name[2 * DIM + 1], aux;
    char s[100], s1[100],*ptr = s, op=' ';
    int temp;
    init_str(s);
    do{
		printf("Options: (s)strings, (n)names, (q)quit : \n");
		op = getchar();
		switch (op){
			 case 's':
                while(*s=='\0'|| *s=='\n'){
                    printf("Insert a string: ");
                    fgets(s, sizeof(s), stdin);
                }
                if (*ptr == '\0')
                    return 0;
                while (*ptr!='\0')
                    putchar(*ptr++);
                /*Inverted string:*/
                ptr--;/*because '\0'*/
                while (ptr>=s)
                    putchar(*ptr--);
                printf("\n");
                strcpy(s1,s);
                puts(StrDelUpper(s1));
                break;
			 case 'n':
                printf("Insert first name: ");
                scanf("%s",name);
                cleanstdin();
                printf("Insert surname: ");
                scanf("%s",surname);
                printf("full name: %s %s\n\n",name, surname);
                printf("Insert a full name: ");
	            fgets(name, sizeof(name), stdin);
                printf("name full_name: %s\n\n",name);
                cleanstdin();
                printf("name: ");
                fgets(name, sizeof(name), stdin);
                printf("surnames: ");
                fgets(surname, sizeof(surname), stdin);
                delenter(surname);
                strcpy(full_name, surname);
                puts(full_name);
                strcat(full_name, NAME_SEP);
                puts(full_name);
                strcat(full_name, name);
                puts(full_name);
                temp = strcount(full_name);
                printf("%d \n",temp);
                aux = Max_Ascii(full_name);
                printf("%c \n",aux);
                aux = nth_char(full_name,3);
                printf("%c \n",aux);
                puts(next_char(full_name));
                puts(UpDown(full_name));
                puts(All_Big(full_name));
                puts(strlwr(full_name));
                puts(allspaces(full_name));
                puts(init_str(full_name));
                break;
			 case 'q':
                break;
			 default :
                puts("Invalid Option !!!");
            }
    }
    while (op!= 'q');
    return 0;
}

/*1 counts the number of letters in a sentence */
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
char *UpDown(char *s){
	int i;
	for (i=0;s[i]!='\0'; i++)
			s[i] = (i%2==0) ? toupper(s[i]) : tolower(s[i]);
	return s;
}

/*5 replace string letters with spaces */
char *allspaces(char *s){
	int i;
	for (i=0;s[i]!='\0'; i++)
		s[i]=' ';
	return s;
}

/*6 Place strings only in lowercase */
char *strlwr(char *str){
	int i;
	for (i=0 ; str[i]!='\0' ; i++)
		str[i] = tolower(str[i]);
	return str;
}

/*7 initializes string */
char *init_str(char *s){
	s[0] = '\0';
	return s;
}

/*6 Only put strings in uppercase */
char * All_Big(char *s){
  int i,j;
  for (i=j=0; s[i]!='\0'; i++)
	 if (isupper(s[i]))
		s[j++]=s[i];
  s[j]=0;
  return s;
}

/*7 find the nth character in the string */
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
void cleanstdin(){
    char s[100];
    fgets(s, sizeof(s), stdin);
}

/*10 replace \n with space */
char *delenter(char *s){
	int i;
	for (i=0;s[i]!='\0'; i++)
		if (s[i]=='\n')
            s[i]=' ';
	return s;
}