#ifndef FILES_OP
#define FILES_OP
    #define FILES_PATH "./files/"
    void clean_enter(void);
    void str_creator(char *str, char c);
    long int file_bytes(FILE *fp, long int type_size);
    FILE *open_check(void);
    void ffcopy(void);
    void insert_lines(void);
#endif
