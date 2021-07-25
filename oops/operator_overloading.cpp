#include <iostream>
using namespace std;

class Test
{
private:
  int count;

public:
  Test(): count(100)
  {

    //writing fuction name followed by data member and passed on value works like constructor
  }

  // we write operator before overloading such operators

  void operator &(int b) {
    count = count + b;

  }

  void operator ++()
  {
    count = count + 100;
  }
  void Display()
  {
    cout << "Count: " << count;
  }
};

class PrepInsta
{
  int x;
public:

  void display()
  {
    cout << "The value is: " << x << endl;
  }

  PrepInsta(int x1) {
    x = x1;
  }


};



int main()
{
  Test t;
  // this calls "function void operator ++()" function
  // ++t;
  // t.Display();
  PrepInsta p1(50 );
  p1.display();
// Default Operator Overloading happens here
// Calls constructor again as single passing argument cal call it.
  p1 = 100;
  p1.display();
  return 0;
}