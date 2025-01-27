#include <stdio.h>


int substitute_vowels(char *s,char ch)
{
    int replace = 0;
    while (*s != '\0')
    {
        if (*s == 'a' ||*s == 'e' ||*s == 'i' ||*s == 'o' ||*s == 'u')
        {
            *s = ch;
            replace++;
        }
        s++;
    }

return replace;
}

int main()
{
    char s[] = "This is a sentence";
    printf("%s\n",s);
    int n = substitute_vowels(s,'o');
    printf("%s\n",s);
    printf("%d\n",n);

    return 0;
}

