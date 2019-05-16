#ifndef STRINGS_OP
#define STRINGS_OP
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
#endif