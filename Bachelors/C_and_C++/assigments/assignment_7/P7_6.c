/*
CH-230-A
a7_p6.c
Harishi Velavan
hvelavan@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person
{
    char name[30];
    int age; 
};

void swap(struct Person* lhs, struct Person* rhs)
{
    struct Person temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
}

int compareName(struct Person* lhs, struct Person* rhs);

int compareAge(struct Person* lhs, struct Person* rhs)
{
    if (lhs->age == rhs->age)
    {
        return compareName(lhs, rhs);
    }
    else if (lhs->age > rhs->age)
    {
        swap(lhs, rhs);
        return 1;
    }
    return 0;
}

int compareName(struct Person* lhs, struct Person* rhs)
{
    if (strcmp(lhs->name, rhs->name) == 0)
    {
        return compareAge(lhs, rhs);
    }
    else if (strcmp(lhs->name, rhs->name) > 0)
    {
        swap(lhs, rhs);
        return 1;
    }
}

void sort(struct Person* person,  int num, int (*comparator)(struct Person* lhs, struct Person* rhs))
{
    int swapped = 0;
    while(!swapped)
    {
        swapped = 0;
        for (int i = 0; i < num - 1; ++i)
        {
            if(comparator(person+i, person+i+1))
            {
                swapped = 1;
            }
        }

    }
}

int main()
{

    int num;
    scanf("%d",&num);

    // initialize
    struct Person personsByAge[num];
    struct Person personsByName[num];

    for (int i = 0; i < num; ++i)
    {
        int age;
        char name[30];
        struct Person person;
        scanf(" %s", person.name);
        scanf("%d", &person.age);
        personsByAge[i] = person;
        personsByName[i] = person;
    }

    sort(personsByName, num, compareName);

    for (int i = 0; i < num; ++i)
    {
        printf("{name: %s, age: %d}; ", personsByName[i].name, personsByName[i].age);
    }
    
    printf("\n");

    sort(personsByAge, num, compareAge);

    for (int i = 0; i < num; ++i)
    {
        printf("{name: %s, age: %d}; ", personsByAge[i].name, personsByAge[i].age);
    }
    
    printf("\n");

    return EXIT_SUCCESS;
}
