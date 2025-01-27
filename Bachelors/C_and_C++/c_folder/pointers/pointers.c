/* This is my first C program */
#include <stdio.h>
 int main ()
 {

    int a = 10;
    printf ("value of a: %d \n", a);
    int *b = &a;

    *b += 2;

    printf ("value of a: %d \n", a);
    

    printf ("address of a: %d \n", &a);
    printf ("address of a or value of b: %d \n", b);
    printf ("value of a from b: %d \n", *b);
    return 0;
 }

#include <stdio.h>

int main () 
{
    char name[] = "Hello World ";
    printf ("%s\n", name ) ;
    name [5] = '\0';
    printf ("%s\n", name ) ;
    return 0;
}