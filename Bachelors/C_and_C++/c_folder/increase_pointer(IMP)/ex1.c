#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch_arr[2] = {'a','b'};
    char *ch__ptr;
    float f_arr[2] = {1.1,2.2};
    float *f_ptr;
    ch__ptr = &ch_arr[0];  
    printf("%p\n", ch__ptr); /* address of 1st elem*/
    ch__ptr++;
    printf("%p\n", ch__ptr); /* address of 2nd elem*/
    printf("%c\n", *ch__ptr); /* content of 2nd element*/

    f_ptr = f_arr; /* same as &f_arr[0]*/
    printf("%p\n", f_ptr); /* address of 1st elem*/

    f_ptr++;
    printf("%p\n", f_ptr); /* address of 2nd elem*/
    printf("%f\n", *f_ptr); /* content of 2nd element*/
    return 0;
}


