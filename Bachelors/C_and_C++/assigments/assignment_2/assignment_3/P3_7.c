/*
  CH-230-A
  a3_p7.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <stdio.h>

void print_form(int n,int m,char c); //function declaration

int main()
{
    int n,m;
    char c;
    printf("input you character: ");  //character
    scanf("%c", &c);
    printf("input the height of trapezoid: "); // height
    scanf("%d", &n);
    printf("input the base of trapezoid: "); //base
    scanf("%d", &m);


    print_form(n,m,c); //calling function

    return 0;
}

void print_form(int n,int m,char c)
{
    for (int i = n; i >= 1; i--) //going backwards
    {
        for (int j = 1; j <= m+n-i; j++) //algorithm
        {
            printf("%c",c);
        }
        printf("\n");
    }
    
}