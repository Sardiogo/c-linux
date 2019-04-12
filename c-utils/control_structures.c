#include <stdio.h> /*include information about standard library*/
#include <ctype.h> /*Functions to determine the type contained in character data*/

void test_operators(void)
{
    int x, y;
    printf("Enter 2 integers");
    scanf("%d%d", &x, &y);
    printf("The result of %d == %d : %d\n", x, y, x == y);
    printf("The result of %d >  %d : %d\n", x, y, x > y);
    printf("The result of %d >= %d : %d\n", x, y, x >= y);
    printf("The result of %d <  %d : %d\n", x, y, x < y);
    printf("The result of %d <= %d : %d\n", x, y, x <= y);
    printf("The result of %d != %d : %d\n", x, y, x != y);
    if (x) /* instead of if(x!=0) */
        printf("%d is not zero!!!\n", x);
    else
        printf("%d is zero!!!\n\n", x);
}

void test_cycles(void)
{
    char c;
    int n, i, j;
    /*******************************************************/
    do{
        puts("if character is a digit cycle ends\n");
        puts("insert a character:");
        scanf(" %c", &c);
        if (!isdigit(c)) /* if not digit */
            putchar(c);
    } while (isalpha(c)); /* as long as it is alphabetic */
    /*******************************************************/
    n = 10;
    while (n)
    {
        printf("%d\n", n);
        n = n - 1;
    }
    /*******************************************************/
    printf("How many tree branches?:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
            putchar('*');
        putchar('\n');
    }
    /*******************************************************/
    printf("check if your number is multiple of 10 or 3: ");
    scanf(" %d", &n);
    for (i = j = n;; i++, j--)
    {
        /*Infinite Cycle */
        if (i % 10 == 0)
        {
            /*Multiple of 10*/
            /*If true infinite cycle ends*/
            printf("%d is multiple of 10\n j=%d\n", i, j);
            break;
        }
        else if (i % 3 == 0)
        {
            /*Multiple of 3*/
            /*If true go to the next iteration*/
            printf("%d is multiple of 3\n j=%d\n", i, j);
            continue;
        }
        printf("%d  is not a multiple of 10 or 3\n j=%d\n", i, j);
    }
    /*******************************************************/
}

void test_conditions(void)
{
    float salary;
    printf("How much is the salary: ");
    scanf("%f", &salary);
    /*Apply rate*/
    salary = salary > 1000 ? salary * 1.05 : salary * 1.07;
    printf("New salary: %.2f\n\n", salary);
    /*The Conditional Operator ? is the only ternary operator of C, which indicates that it expects three arguments.
     Its syntax is : condition ? expression : expression2
     Operation :
     • The condition is evaluated.
     • If the result is Truth, the result of the entire expression is the value returned per expression
     • If the result is False, the result of the entire expression is the value returned by expression2.*/
}

void test_menu(void)
{
    char c, option;
    do{
        printf("\tM A I N   M E N U\n");
        printf("\n\n\t\tCustomers");
        printf("\n\n\t\tSuppliers");
        printf("\n\n\t\tOrders");
        printf("\n\n\t\tExit");
        printf("\n\n\n\t\t\tOption:");
        /* Stop Screen*/
        /* space before %c clears previous enter*/
        fscanf(stdin, " %c", &option);
        /*Test enter*/
        while ((c = getc(stdin)) != '\n')
            ungetc(c, stdin);
        switch (option)
        {
        case 'c':
        case 'C':
            puts("Customers Option");
            break;
        case 's':
        case 'S':
            puts("Suppliers Option");
            break;
        case 'o':
        case 'O':
            puts("Orders Option");
            break;
        case 'e':
        case 'E':
            break; /* Don't do anything */
        default:
            puts("Invalid Option!!!");
        }
    } while (option != 'e' && option != 'E');
}

int main(void)
{
    int op;
    void (*function_ptr[])(void) = {test_operators, test_cycles, test_conditions, test_menu};
    /* function_ptr is an array of function pointers */
    do{
        fflush(stdin);
        printf("0: test_operators\n1: test_cycles\n");
        printf("2: test_conditions\n3: test_menu\n");
        printf("Enter option:");
        scanf(" %d", &op);
        switch (op)
        {
        case 0:
            (*function_ptr[op])();
            break;
        case 1:
            (*function_ptr[op])();
            break;
        case 2:
            (*function_ptr[op])();
            break;
        case 3:
            (*function_ptr[op])();
            break;
        case 4:
            break;
        default:
            puts("Incorrect Option!!!");
        }
    } while (op != 4);
    return 0;
}

