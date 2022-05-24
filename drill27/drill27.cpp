#include <stdlib.h>
#include <stdio.h>

void print_out(const char* p, const int x)
{
    printf("p is\"%s\" and x is %i\n", p, x);
}

int main()
{
    /* Ex 1 */
    printf("Hello World!\n");

    /* Ex 2 */
    char* first = "Hello";
    char* last = "World!";
    printf("%s %s\n", first, last);

    /* Ex 3 */
    print_out("May", 6);
    print_out("Chris", 39);
    print_out("C", 89);
    return 0;
}
