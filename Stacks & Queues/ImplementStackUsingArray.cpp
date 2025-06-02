#include <iostream>
using namespace std;

int SIZE=10;
class StImpl {
  int top=-1;
  int st[SIZE];
  
  
  bool push(int x) {
      if(top==SIZE-1) {
          cout << "Overflow" << endl;
          return false;
      }
      top++;
      st[top] = x;
      return true;
  }
  
  int top() {
      if(top!=-1) {
          return st[top];
      }
      cout << "Empty Stack" << endl;
      return -1;
  }
  bool pop() {
      if(top==-1) {
          cout << "Empty Stack" << endl;
          return false;
      }
      top--;
      return true;
  }
};
