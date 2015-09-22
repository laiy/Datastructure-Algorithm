enum ErrorCode {
 success,
 underflow,
 overflow
};

template <class QueueEntry>
struct Node {
 QueueEntry data;
 Node<QueueEntry> *next;
};

template <class QueueEntry>
class MyQueue {
public:
 MyQueue() : front(0), rear(0) {}

 // 判断队列是否为空
 bool empty() const {
     return (!front) && (!rear);
 }

 // 入队操作
 ErrorCode append(const QueueEntry &item) {
     Node<QueueEntry>* new_node = 0;
     new_node = new Node<QueueEntry>;
     if (new_node == 0) return overflow;
     new_node->data = item;
     new_node->next = 0;
     if (empty()) {
         front = rear = new_node;
     } else {
         rear->next = new_node;
         rear = new_node;
     }
     return success;
 }

 // 出队操作
 ErrorCode serve() {
     if (empty()) return underflow;
     if (size() == 1) {
         delete front;
         front = rear = 0;
         return success;
     }
     Node<QueueEntry>* temp = front;
     front = front->next;
     delete temp;
     temp = 0;
     return success;
 }

 // 获取队头元素
 ErrorCode retrieve(QueueEntry &item) const {
     if (empty()) return underflow;
     item = front->data;
     return success;
 }

 // 获取队列已有元素个数
 int size() const {
     if (empty()) return 0;
     Node<QueueEntry>* temp = front;
     int size = 1;
     while (temp->next != 0) {
         size++;
         temp = temp->next;
     }
     return size;
 }

 // 清除队列所有元素
 void clear() {
     while (front->next != 0) {
         serve();
     }
     front = rear = 0;
 }

 // 获取队头元素并出队
 ErrorCode retrieve_and_serve(QueueEntry &item) {
     if (empty()) return underflow;
     item = front->data;
     if (size() == 1) {
         delete front;
         front = rear = 0;
         return success;
     }
     Node<QueueEntry>* temp = front;
     front = front->next;
     delete temp;
     temp = 0;
     return success;
 }

private:
 Node<QueueEntry> *front;                           // 队头指针
 Node<QueueEntry> *rear;                             // 队尾指针
};

