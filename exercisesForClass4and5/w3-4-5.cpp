#include <stack>
using namespace std;

class Queue { 
public: 
      bool IsEmpty() const {
          return firstStack.empty() && secondStack.empty();
      }
  int &front() {
      while (!firstStack.empty()) {
          secondStack.push(firstStack.top());
          firstStack.pop();
      }
      int ans = secondStack.top();
      while (!secondStack.empty()) {
          firstStack.push(firstStack.top());
          secondStack.pop();
      }
  }
  void push(int a) {
      firstStack.push(a);
  }
  void pop() {
      while (!firstStack.empty()) {
          secondStack.push(firstStack.top());
          firstStack.pop();
      }
      secondStack.pop();
      while (!secondStack.empty()) {
          firstStack.push(firstStack.top());
          secondStack.pop();
      }
  }
 private: 
     stack<int> firstStack; 
     stack<int> secondStack; 
}; 

