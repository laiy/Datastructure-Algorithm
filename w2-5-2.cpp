enum ErrorCode {
         success,
         underflow,
         overflow
};

const int maxQueue = 100;
template <class QueueEntry>
class MyQueue {
public:
         MyQueue() : front(0), rear(0) {}
         // 判断队列是否为空
         bool empty() const {
             return  front == rear;
         }
         // 入队操作
         ErrorCode append(const QueueEntry &item) {
             if (full()) {
                 return overflow;
             } else {
                 entry[rear++] = item;
                 if (rear == 100) {
                     rear = 0;
                 }
                 return success;
             }
         }
         // 出队操作
         ErrorCode serve() {
             if (empty()) {
                 return underflow;
             } else {
                 front++;
                 if (front == 100) {
                     front = 0;
                 }
                 return success;
             }
         }
         // 获取队头元素
         ErrorCode retrieve(QueueEntry &item) const {
             if (empty()) {
                 return underflow;
             } else {
                 item = entry[front];
                 return success;
             }
         }
         // 判断队列是否已满
         bool full() const {
             return (rear + 1) % 100 == front;
         }
         // 获取队列已有元素个数
         int size() const {
             int count = 0, step = front;
             while (step != rear) {
                 count++;
                 step++;
                 if (step == 100) {
                     step = 0;
                 }
             }
             return count;
         }
         // 清除队列所有元素
         void clear() {
             front = rear = 0;
         }
         // 获取队头元素并出队
         ErrorCode retrieve_and_serve(QueueEntry &item) {
             if (empty()) {
                 return underflow;
             } else {
                 item = entry[front++];
                 if (front == 100) {
                     front = 0;
                 }
                 return success;
             }
         }
private:
         int front;                             // 队头下标
         int rear;                              // 队尾下标
         QueueEntry entry[100];       // 队列容器
};

