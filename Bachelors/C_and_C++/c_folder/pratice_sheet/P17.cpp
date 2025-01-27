#include <iostream>
#include <string.h>


class Book
{
    private:
        char *title;
        int pages;
    public:
        Book(const Book &obj);
        Book(const char *t,const int p);
        Book();

};

Book::Book(const Book &obj)
{
    title = new char[30];
    strcpy(title,obj.title);
    this->pages = obj.pages;
    delete []title;
}

//The compiler-generated copy constructor performs a basic copy of each member, which might be problematic when dealing with dynamic memory (e.g., pointers).

//Programmers should provide their own copy constructor when the class has pointers or resources that need careful handling to prevent issues like double-deletion of memory or unintended sharing of resources. This allows for a more customized and appropriate copying mechanism tailored to the class's specific needs.