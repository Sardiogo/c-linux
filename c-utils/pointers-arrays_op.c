/*Operations with pointers, vectors, arrays and strings*/
#include <stdio.h>
#include <string.h>

void exchange(float *a, float *b);
void pointers_ex(void);
void vectors_pointers_ex(void);
void string_op_ex(void);

int main(void)
{
    pointers_ex();
    vectors_pointers_ex();
    string_op_ex();
    return (0);
}

/* Passing parameters by reference */
void exchange(float *a, float *b)
{
    float tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

/* Pointers operations example */
void pointers_ex(void)
{
    float y = 1.1, *ptr_y;
    float x = 1.2, *ptr_x, **ptr_ptr_x;

    puts("\n***** void pointers_ex(void) *****\n");
    printf("Before exchange  x=%f e y=%f\n", x, y);
    exchange(&x, &y);
    printf("After exchange x=%f e y=%f\n", x, y);
    ptr_y = &y;
    printf("ptr_y = &y; \n*ptr_y=%f\n", *ptr_y);
    *ptr_y = y * y;
    printf("*ptr_y = y * y = %f\n", *ptr_y);
    ptr_x = &x;
    ptr_ptr_x = &ptr_x;
    printf("x=%f - &x=%p\n", x, (void *)&x);
    printf("*ptr_x=%f - ptr_x=%p - &ptr_x=%p\n", *ptr_x, (void *)ptr_x, (void *)&ptr_x);
    printf("**ptr_ptr_x=%f - *ptr_ptr_x=%p - ptr_ptr_x=%p - &ptr_ptr_x=%p\n", **ptr_ptr_x, (void *)*ptr_ptr_x, (void *)ptr_ptr_x, (void *)&ptr_ptr_x);
    puts("");
}

/*Vectors and Pointers operations*/
void vectors_pointers_ex(void)
{
    int v[] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 100};
    int i, *ptr2, *ptr = v;
    ptr2 = v; /*<=> ptr2 = &v*/

    puts("\n***** void vector_pointers_ex(void) *****\n");
    printf("&v=%p - v=%p - v[0]=%d - *v=%d\n", (void *)&v, (void *)v, v[0], *v);
    printf("&ptr=%p - ptr=%p - ptr[0]=%d - *ptr=%d\n", (void *)&ptr, (void *)ptr, ptr[0], *ptr);
    printf("&ptr2=%p - ptr2=%p - ptr2[0]=%d - *ptr2=%d\n", (void *)&ptr2, (void *)ptr2, ptr2[0], *ptr2);
    puts("");
    printf("ptr+1=%p, *ptr+1=%d\n", (void *)(ptr + 1), *ptr + 1);
    printf("v+1=%p, *v+1=%d\n", (void *)(v + 1), *v + 1);
    puts("");
    /*Print Vesctor*/
    for (i = 0; i < 10; i++, ptr++)
        printf("%d ", *ptr);
        /*Error: for (i = 0; i < 10; i++, v++) ->  error:lvalue required as increment operand for (i = 0; i < 10; i++, ptr++) */
    puts("");
    /*Print inverted Vector:*/
    for (i = 0, ptr--; i < 10; i++)
        printf("%d ", *ptr--);
    puts("");
}

/*Strngs operations example*/
void string_op_ex(void)
{
    char s[] = "Exams";
    char *ps = s, **pps = &ps;

    puts("\n***** void string_op_ex(void) *****\n");
    printf("&s=%p - s=%p - s[0]=%c - *s=%c\n", (void *)&s, s, s[0], *s);
    printf("&ps=%p - ps=%p - ps[0]=%c - *ps=%c\n", (void *)&ps, ps, ps[0], *ps);
    printf("&pps=%p - pps=%p - *pps=%p - *pps[0]=%c - **pps=%c\n", (void *)&pps, (void *)pps, *pps, *pps[0], **pps);
    printf("strlen(s)=%ld - strlen(ps)=%ld - strlen(*pps)=%ld\n", strlen(s), strlen(ps), strlen(*pps));
    puts("");
    printf("s[4]=%c - *(s+4)=%c - *s+4=%c\n", s[4], *(s + 4), *s + 4);
    printf("ps[4]=%c - *(ps+4)=%c - *ps+4=%c\n", ps[4], *(ps + 4), *ps + 4);
    printf("(*pps)[4]=%c - *((*pps)+4)=%c - **pps+4=%c\n", (*pps)[4], *((*pps) + 4), **pps + 4);
    puts("");
}
