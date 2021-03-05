#include <iostream>
#include<string>
using namespace std;
 
class Base
{
public:
    virtual string print() 
    {
        return "This is Base class";
    }
};
 
class Derived : public Base
{
public:
    string print() 
    {
        return "This is Derived class";
    }
};
 
class D : public Derived
{
public:
    virtual string print() 
    {
        return "This is D class";
    }
};
 
// void describe(Derived p)
// {
//     cout << p.print() << endl;
// }
 
int main()
{
    Base *b = new D;
    cout << b->print();
    return 0;
}