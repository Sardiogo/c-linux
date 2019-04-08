#include <stdio.h>

void add(int a, int b);
void subtract(int a, int b);
void multiply(int a, int b);
void caller(void (*fun)(int, int));
void fun1(void);
void fun2(void);
void wrapper(void (*fun)(void));
void test(void);
int compare(void *a, void *b);
int search(void *arr, int arr_len, int ele_size, void *x, int compare(void *, void *));
void finder(void);

int main(void)
{
    void (*fun_ptr_arr[])(int, int) = {add, subtract, multiply};
    /* fun_ptr_arr is an array of function pointers */
    int op, a = 15, b = 10;
    test();
    finder();
    do{
        fflush(stdin);
        printf("Enter option: 0 for add, 1 for subtract, 2 for multiply and 3 to exit\n");
        scanf(" %d", &op);
        switch (op)
        {
        case 0:
            (*fun_ptr_arr[op])(a, b);
            break;
        case 1:
            (*fun_ptr_arr[op])(a, b);
            break;
        case 2:
            (*fun_ptr_arr[op])(a, b);
            break;
        case 3:
            break;
        default:
            puts("Incorrect Option!!!");
        }
    } while (op != 3);
    return 0;
}
void add(int a, int b)
{
    printf("%d + %d = %d\n", a, b, a + b);
}
void subtract(int a, int b)
{
    printf("%d - %d = %d\n", a, b, a - b);
}
void multiply(int a, int b)
{
    printf("%d x %d = %d\n", a, b, a * b);
}
/*A function that receives a function as parameter and calls that function*/
void caller(void (*fun)(int, int))
{
    fun(3, 2);
}
/*Two simple functions*/
void fun1(void) { puts("Fun1"); }
void fun2(void) { puts("Fun2"); }
/*A function that receives a simple function as parameter and calls that function*/
void wrapper(void (*fun)(void))
{
    fun();
}
void test(void)
{
    caller(add);
    caller(subtract);
    caller(multiply);
    wrapper(fun1);
    wrapper(fun2);
}
/*A compare function that is used for searching an integer array*/
int compare(void *a, void *b)
{
    return (*(int *)a == *(int *)b);
}
/* General purpose search() function. Note that void pointers are used so that the function can be called by passing a pointer of any type. */
int search(void *arr, int arr_len, int ele_size, void *x, int compare(void *, void *))
{
    /*Since char takes one byte, we can use char pointer for any type to get pointer arithmetic correct. */
    char *ptr = (char *)arr;
    int i;
    for (i = 0; i < arr_len; i++)
        /*Then we need to multiply index with size of an array element ele_size */
        if (compare(ptr + i * ele_size, x))
            return i;
    return -1; /* If element not found */
}
void finder(void)
{
    int arr[] = {2, 5, 7, 90, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 7;
    printf("Searched out index is %d \n", search(arr, n, sizeof(int), &x, compare));
}