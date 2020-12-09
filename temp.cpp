#include <cstdio>
#include<iostream>
class A{
  public:
  	int a;
  A(){
  	std::cout << "ds";
  }
  int operator +(int j){
  	return this->a + j;
  }
};
int main()
{
  A o1, o2;
  o1.a = 10, o2.a = 20;
  int data = o1 + 5;
  std::cout << data;
}