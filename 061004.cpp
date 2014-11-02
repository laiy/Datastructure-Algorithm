#include <iostream>
using namespace std;

enum Error_code
{
         success,
         underflow,
         overflow
};

template <class List_entry>
struct Node
{
         List_entry entry;
         Node<List_entry> *next;
         Node<List_entry> *back;
};

template <class List_entry>
class MyList
{
public:
         MyList() : count(0), curPosition(0), current(NULL) {}
         ~MyList() {
            clear();
         }
         // 拷贝构造函数和赋值运算符重载，注意深拷贝与浅拷贝的差异
         MyList(const MyList<List_entry> &copy) {
            count = curPosition = 0;
            current = NULL;
            copy.setPosition(0);
            while (count < copy.count) {
               insert(count, copy.current->entry);    // count is increase 1 after this statement
               if (count < copy.count) {
                  copy.setPosition(count);
               }
            }
         }
         void operator =(const MyList<List_entry> &copy) {
            this->clear();
            copy.setPosition(0);
            while (count < copy.count) {
               insert(count, copy.current->entry);    // count is increase 1 after this statement
               if (count < copy.count) {
                  copy.setPosition(count);
               }
            }
         }
         // 清空list
         void clear() {
            Node<List_entry> * temp;
            setPosition(0);
            while (count > 0) {
               temp = current;
               current = current->next;
               delete temp;
               count--;
            }
            count = curPosition = 0;
            current = NULL;
         }
         // 判断list是否为空
         bool empty() const {
            if (count > 0) {
               return false;
            } else {
               return true;
            }
         }
         // 判断list是否已满
         bool full() const {
            Node<List_entry> * temp = new Node<List_entry>;
            if (NULL == temp) {
               return true;
            } else {
               delete temp;
               return true;
            }
         }
         // 获取list的元素数量
         int size() const {
            return count;
         }
         // 在第position个位置插入值为entry的元素，如果position为0则插入在链表头，依次类推
         // 若position < 0 或者 position > count，则返回underflow
         Error_code insert(int position, const List_entry &entry) {
            if (position < 0 || position > count) {
               return underflow;
            }
            Node<List_entry> *temp = new Node<List_entry>;
            if (NULL == temp) {
               return overflow;
            } else {
               temp->entry = entry;
               temp->next = temp->back = NULL;
            }
            if (position > 0) {
               setPosition(position - 1);
            } else {
               setPosition(0);
            }

            if (empty()) {       /// insert when the list is empty
               current = temp;
            } else if (0 == position) {      /// insert from the head
               temp->next = current;
               current->back = temp;
               curPosition++;
            } else if (position == count) {     /// insert from the back
               current->next = temp;
               temp->back = current;
            } else {                         /// insert from the middle
               temp->next = current->next;
               temp->back = current;
               current->next->back = temp;
               current->next = temp;
            }
            count++;
            return success;
         }
         // 删除第position个位置的元素，并将该元素的值保存在entry中
         // 若position < 0 或者 position >= count，则返回underflow
         Error_code remove(int position, List_entry &entry) {
            if (position < 0 || position >= count) {
               return underflow;
            }
            setPosition(position);
            entry = current->entry;
            Node<List_entry> *temp = current;
            if (0 == position) {     /// delete head
               current = current->next;
               if (current != NULL) {
                  current->back = NULL;
               }
            } else if (NULL == current->next) {    /// delete tail
               current = current->back;
               if (current != NULL) {
                  current->next = NULL;
                  curPosition--;
               }
            } else {             /// delete middle
               current->back->next = current->next;
               current->next->back = current->back;
               current = current->next;
            }
            delete temp;
            count--;
            return success;
         }
         // 获取第position个位置的元素，保存在entry中
         // 若position < 0 或者 position >= count，则返回underflow
         Error_code retrieve(int position, List_entry &entry) const {
            if (position < 0 || position >= count) {
               return underflow;
            }
            setPosition(position);
            entry = current->entry;
            return success;
         }
         // 将第position个位置的元素替换为entry
         // 若position < 0 或者 position >= count，则返回underflow
         Error_code replace(int position, const List_entry &entry) {
            if (position < 0 || position >= count) {
               return underflow;
            }
            setPosition(position);
            current->entry = entry;
            return success;
         }
         // 用visit函数遍历list内所有的元素
         void traverse(void (*visit)(List_entry &)) {
            if (0 == count) {    // empty now
               return;
            }
            setPosition(0);
            while (curPosition < count) {
               visit(current->entry);
               curPosition++;
               if (curPosition < count) {
                  current = current->next;
               }
            }
            if (curPosition == count) {
               curPosition--;
            }
         }

protected:
         int count;                                         // 记录list内元素数量
         mutable int curPosition;                           // current指针的位置编号
         mutable Node<List_entry> *current;                 // current指针
         // 设置current指针的位置，指向第position个位置
         void setPosition(int position) const {
            if (curPosition < position) {
               for (; curPosition != position; curPosition++) {
                  current = current->next;
               }
            } else if (curPosition > position) {
               for (; curPosition != position; curPosition--) {
                  current = current->back;
               }
            }
         }
};

//////////////////////////// for test code //////////////////////////////////////

template<typename List_entry>
void print(MyList<List_entry> a) {
   List_entry num;
   for (int i = 0; i < a.size(); i++) {
      if (a.retrieve(i, num) == underflow) {    /// test for retrive
        cout << "underflow\n";
        break;
      }
      cout << num << " ";
   }
   if (a.empty()) cout << "none" << endl;
   cout << endl;
}

template<typename List_entry>
void visit(List_entry & cur) {
   cout << cur << " ";
}

void small_test() {
   cout << "------------------small test------------------------" << endl;
   int num;
   MyList<int> a;
   for (int i = 0; i < 5; i++) {
      a.insert(i, i);
   }
   cout << "insert OK" << endl;

   for (int i = 0; i < a.size(); i++) {
      if (a.retrieve(i, num) == underflow) {    /// test for retrive
        cout << "underflow\n";
        break;
      }
      cout << num << " ";
   }
   cout << endl;

   print(a);            /// test for constructor copy

   a.traverse(visit);
   a.clear();           /// test for clear
   if (a.empty()) cout << endl << "Is empty now" << endl;

   a.remove(1, num);
   num = 1;
   a.replace(0, num);   /// test for replace
   print(a);                     // none
   a.insert(1, num);    /// test for insert
   print(a);                     // none
   a.insert(0, num);    /// test for insert again
   print(a);                     // 1
   a.replace(1, 3);     /// test for replace again
   print(a);                     // 1
   a.replace(0, 3);     /// test for replace again
   print(a);                     // 3
   a.remove(1, num);    /// test for remove
   print(a);                     // 3
   a.remove(0, num);    /// test for remove
   print(a);                     // none
}
// test for int type
void bigger_test() {
   cout << "-----------------bigger test ----------------------" << endl;
   int num;
   MyList<int> a;
   /// test for insert
   for (int i = 0; i < 10; i++) {
      a.insert(i, i);
   }
   print(a);

   /// test for replace
   for (int i = 0; i < 10; i++) {
      if (i % 2 == 1) {
         a.replace(i, i * 2);
      }
   }
   print(a);

   /// test for remove from the head
   if (a.remove(0, num) == success) {
      cout << "head element is " << num << endl;
   } else {
      cout << "remove head failed because the outside position" << endl;
   }
   if (a.remove(0, num) == success) {
      cout << "head element is " << num << endl;
   } else {
      cout << "remove head failed because the outside position" << endl;
   }
   if (a.remove(-1, num) == success) {
      cout << "head element is " << num << endl;
   } else {
      cout << "remove head failed because the outside position" << endl;
   }
   cout << "after remove from head : ";
   print(a);

   /// test for remove from the tail
   if (a.remove(a.size() - 1, num) == success) {
      cout << "tail element is " << num << endl;
   } else {
      cout << "remove tail failed" << endl;
   }
   if (a.remove(a.size() - 1, num) == success) {
      cout << "tail element is " << num << endl;
   } else {
      cout << "remove tail failed" << endl;
   }
   if (a.remove(a.size(), num) == success) {
      cout << "tail element is " << num << endl;
   } else {
      cout << "remove tail failed" << endl;
   }
   cout << "after remove from tail : ";
   print(a);

   /// test for remove from the middle
   if (a.remove(a.size() / 2, num) == success) {
      cout << "middle element is " << num << endl;
   } else {
      cout << "remove middle failed" << endl;
   }
   if (a.remove(a.size() / 2, num) == success) {
      cout << "middle element is " << num << endl;
   } else {
      cout << "remove middle failed" << endl;
   }
   if (a.remove(a.size() / 2, num) == success) {
      cout << "middle element is " << num << endl;
   } else {
      cout << "remove middle failed" << endl;
   }
   cout << "after remove from middle : ";
   print(a);

   /// test for insert head
   for (int i = 0; i < 3; i++) {
      a.insert(0, i + 10);
   }
   cout << "after insert from the head : ";
   print(a);

   /// test for insert tail
   for (int i = 0; i < 3; i++) {
      a.insert(a.size(), i + 20);
   }
   cout << "after insert from the tail : ";
   print(a);

   /// test for insert middle
   for (int i = 0; i < 3; i++) {
      a.insert(3, 100 + i);
   }
   cout << "after insert from the middle : ";
   print(a);

   /// test for insert out of range
   for (int i = 3; i > 0; i--) {
      a.insert(a.size() + i, 200 + i);
   }
   a.insert(-2, 222);
   cout << "after test for out of range : ";
   print(a);
}

void lager_test() {
   cout << "\n----------------large test-------------------" << endl;
   string temp;
   MyList<string> test;

   cout << "Please input 5 strings for test :" << endl;
   for (int i = 0; i < 5; i++) {
      cin >> temp;
      test.insert(i, temp);
   }
   print(test);

   for (int i = 0; i < test.size(); i++) {
      if (i % 2 == 0) test.replace(i, "replace");
   }
   print(test);

   for (int i = 0; i < 3; i++) {
      test.remove(i, temp);
      cout << temp << endl;
   }
   print(test);
}
int main() {
   small_test();
   bigger_test();
   lager_test();
   return 0;
}
