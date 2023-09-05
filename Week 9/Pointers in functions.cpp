#include <iostream>
using namespace std;

void function1 (int* ptr)
{
    int* n = new int;
    *n = 10;
    ptr = n;
    cout<<"Inside function1, my ptr value is: "<<*ptr<<endl; //10
}

void function2 (int*& ptr)
{
    int* n = new int;
    *n = 20;
    ptr = n;
    cout<<"Inside function2, my ptr value is: "<<*ptr<<endl; //20
}

void function3 (int* ptr)
{
    int* n = new int;
    *n = 30;
    *ptr = *n;
    //or, simpler version for line 24:
    //*ptr = 30;
    cout<<"Inside function3, my ptr value is: "<<*ptr<<endl; //30
}

void function4 (int** ptr)
{
    int* n = new int;
    *n = 40;
    *ptr = n;
    //Dereferencing ptr, which is also a pointer. We are setting that to point to
    //the same place pointer n points to.

    cout<<"Inside function4, my ptr value is: "<<*ptr<<", which is the address of the inner pointer."<<endl;
    cout<<"To get the value of the inner pointer, we have to dereference twice! "<< **ptr <<endl; //40
}

void function5 (int** ptr)
{
    int* n = new int;
    *n = 50;
    ptr = &n; //ptr points to n, which points to 50

    cout<<"Inside function5, my ptr value is: "<<*ptr<<", which is the address of the inner pointer."<<endl;
    cout<<"To get the value of the inner pointer, we have to dereference twice! "<< **ptr <<endl; //50
}

int main ()
{
  int* ptrInMain = new int;
  *ptrInMain = 1;

  function1 (ptrInMain);
  cout<<"In main after function1, my ptrInMain value is: "<<*ptrInMain<<endl;
  //Because function1 uses call by value, the changes made to the pointer inside the function is made to
  //the function's local copy of the pointer. Changes are made to the copy,
  //so ptrInMain in the main still points to 1.
  cout<<endl;

  function2 (ptrInMain);
  cout<<"In main after function2, my ptrInMain value is: "<<*ptrInMain<<endl;
  //Function2 uses call by reference (the parameter uses &), so changes made to the pointer affects main
  cout<<endl;

  function3 (ptrInMain);
  cout<<"In main after function3, my ptrInMain value is: "<<*ptrInMain<<endl;
  //Function3 like function1 uses call by value, so it makes a copy of ptrInMain in the function stack.
  //In line 24, by using *ptr, we are dereferencing the local pointer ptr, which is a copy of ptrInMain.
  //Because both ptr and ptrInMain point to the same memory location in the heap, any changes made to the data
  //at that location are reflected in main as well.
  cout<<endl;

  //Same logic applies to double pointers
  function4 (&ptrInMain);
  cout<<"In main after function4, my ptrInMain value is: "<<*ptrInMain<<endl;
  cout<<endl;

  //Unlike function4, not dereferencing when calling by value means it wont make changes to main
  function5 (&ptrInMain);
  cout<<"In main after function5, my ptrInMain value is: "<<*ptrInMain<<endl;
  cout<<endl;

  return 0;
}