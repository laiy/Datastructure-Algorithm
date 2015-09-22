enum ErrorCode {
     success,
     underflow,
     overflow
};

template <class StackEntry>
struct Node {
     StackEntry data;
     Node *next;
};

template <class StackEntry>
class MyStack {
public:
     MyStack() : pTop(0) {}

     /*
       判断栈是否为空，若为空则返回true，非空则返回false
      */
     bool empty() const {
         return pTop == 0;
     }

     int size() const {
         if (pTop == 0) {
             return 0;
         }
         Node<StackEntry>* temp = pTop;
         int size = 1;
         while (temp->next != 0) {
             size++;
             temp = temp->next;
         }
         return size;
     }

     /*
       出栈操作，若正常出栈则返回success，若栈内无元素则返回underflow
      */
     ErrorCode pop() {
         if (empty()) {
             return underflow;
         } else {
             Node<StackEntry>* temp = pTop;
             pTop = pTop->next;
             delete temp;
             temp = 0;
             return success;
         }
     }

     /*
       获取栈顶元素，若正常获取到栈顶元素则返回success，若栈内无元素则返回underflow
       元素内容保存在引用参数item中
      */
     ErrorCode top(StackEntry &item) const {
         if (empty()) {
             return underflow;
         } else {
             item = pTop->data;
             return success;
         }
     }

     /*
       入栈操作，若正常入栈则返回success，若入栈失败则返回overflow
      */
     ErrorCode push(const StackEntry &item) {
         Node<StackEntry>* new_node = 0;
         new_node = new Node<StackEntry>;
         if (new_node == 0) return overflow;
         new_node->data = item;
         new_node->next = pTop;
         pTop = new_node;
         return success;
     }

     /*
       清空栈
      */
     void clear() {
         while (pTop->next != 0) {
             pop();
         }
         pTop = 0;
     }

private:
     Node<StackEntry> *pTop;
};

