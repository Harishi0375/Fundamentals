#include <stdio.h>

void (*func) (void); //define pointer to function
void a(void) {printf("func a\n");}
void b(void) {printf("func b\n");}

int main()
{
    func = &a;
    func = a;
    func();
}