/*Operations with pointers */

#include <stdio.h>
#include <string.h>

void exchange(float *a, float *b);

int main(void)
{
    int v[] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 100}; 
    int i, *ptr2, *ptr = v;
    ptr2 = v;

    float a=1.1, b=3.3, y = 2.2, *ptr_y;
    int x = 5, *ptr_x, **ptr_ptr_x;

    char s[] = "Exams";
    char *ps = s, **pps = &ps;

    printf("Before exchange  a=%f e b=%f\n", a, b);
    exchange(&a, &b);
    printf("After exchange a=%f e b=%f\n", a, b);
    ptr_y = &y;
    printf("%f\n", *ptr_y);
    *ptr_y = y * y;
    printf("%f\n", *ptr_y);
    ptr_x = &x;
    ptr_ptr_x = &ptr_x;
    printf("x = %d - &x = %p\n", x, (void *)&x);
    printf("x = %d - &x = %p\n", *ptr_x, (void *)ptr_x);
    printf("x = %d - &x = %p\n", **ptr_ptr_x, (void *)*ptr_ptr_x);


    printf("&s=%p - s=%p - s[0]=%c - *s=%c\n", (void *)&s, s, s[0], *s);
    printf("&ps=%p - ps=%p - ps[0]=%c - *ps=%c\n", (void *)&ps, ps, ps[0], *ps);
    printf("&pps=%p - pps=%p - *pps=%p - *pps[0]=%c - **pps=%c\n", (void *)&pps, (void *) pps, *pps, *pps[0], **pps);
    printf("strlen(s)=%ld - strlen(ps)=%ld - strlen(*pps)=%ld\n", strlen(s), strlen(ps), strlen(*pps));

    puts("");

    printf("s[4]=%c - *(s+4)=%c - *s+4=%c\n",s[4], *(s+4), *s+4);
    printf("ps[4]=%c - *(ps+4)=%c - *ps+4=%c\n", ps[4], *(ps+4), *ps+4);
    printf("(*pps)[4]=%c - *((*pps)+4)=%c - **pps+4=%c\n", (*pps)[4], *((*pps)+4), **pps+4);

    puts("");
    
    printf("&v=%p - v=%p - v[0]=%d - *v=%d\n", (void *)&v, (void *)v, v[0], *v);
    printf("&ptr=%p - ptr=%p - ptr[0]=%d - *ptr=%d\n", (void *)&ptr, (void *)ptr, ptr[0], *ptr);
    printf("&ptr2=%p - ptr2=%p - ptr2[0]=%d - *ptr2=%d\n", (void *)&ptr2, (void *)ptr2, ptr2[0], *ptr2);
    
    puts("");
    
    printf("ptr+1=%p, *ptr+1=%d\n", (void *)(ptr+1), *ptr+1);
    printf("v+1=%p, *v+1=%d\n", (void *)(v+1), *v+1);
    
    puts("");
    
    for (i = 0; i < 10; i++, ptr++)
        printf("%d ", *ptr);
    puts("");
    /*Inverted vector:*/
    for (i = 0, ptr--; i < 10; i++)
        printf("%d ", *ptr--);
    return (0);
}

/*10 passing by reference */
void exchange(float *a, float *b)
{
    float tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}