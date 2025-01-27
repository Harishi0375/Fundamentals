#include <iostream>

using namespace std;
class worker
{
    private:
        int n;
        string name;
    public:
        worker(const int an,const string &Name) : n(an), name(Name) {}

        inline void setn(const int an) {n = an;}
        const int getn() {return n;}

        inline void setname(const string &Name) {name = Name;}
        const string getname() {return name;}

        friend ostream& operator<<(ostream &out,const worker &obj);
};

ostream& operator<<(ostream &out,const worker &obj)
{
    out << "ID: " << obj.n << " NAME:" << obj.name << endl;
    return out; 
}

int main() {
    worker a(234, "John McEnroe");
    worker b(324, "Jack Nicholson");
    std::cout << a << b;

    return 0;
}