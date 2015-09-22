enum Error_code {
    success,
    underflow,
    overflow
};

template <class List_entry>
struct Node {
    List_entry entry;
    Node<List_entry> *next;
    Node<List_entry> *back;
};

template <class List_entry>
class MyList {
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
            insert(count, copy.current->entry);
            if (count < copy.count) copy.setPosition(count);
        }
    }

    void operator =(const MyList<List_entry> &copy) {
        this->clear();
        copy.setPosition(0);
        while (count < copy.count) {
            insert(count, copy.current->entry);
            if (count < copy.count) copy.setPosition(count);
        }
    }

    // 清空list

    void clear() {
        Node<List_entry>* temp;
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
        return count == 0;
    }

    // 判断list是否已满

    bool full() const {
        Node<List_entry>* temp = new Node<List_entry>;
        if (temp == NULL) return true;
        delete temp;
        return false;
    }

    // 获取list的元素数量

    int size() const {
        return count;
    }

    // 在第position个位置插入值为entry的元素，如果position为0则插入在链表头，依次类推

    // 若position < 0 或者 position > count，则返回underflow

    Error_code insert(int position, const List_entry &entry) {
        if (position < 0 || position > count) return underflow;
        Node<List_entry>* temp = new Node<List_entry>;
        if (temp == NULL) return overflow;
        temp->entry = entry;
        temp->next = temp->back = NULL;
        if (position == 0) {
            setPosition(0);
        } else {
            setPosition(position - 1);
        }
        if (empty()) {
            current = temp;
        } else if (position == 0) {
            temp->next = current;
            current->back = temp;
            curPosition++;
        } else if (position == count) {
            current->next = temp;
            temp->back = current;
        } else {
            temp->next = current->next;
            temp->back = current; 
            current->next->back = temp;
            current->next = temp;
        }
        ++count;
        return success;
    }

    // 删除第position个位置的元素，并将该元素的值保存在entry中

    // 若position < 0 或者 position >= count，则返回underflow

    Error_code remove(int position, List_entry &entry) {
        if (position < 0 || position >= count) return underflow;
        setPosition(position);
        entry = current->entry;
        Node<List_entry>* temp = current;
        if (position == 0) {
            current = current->next;
            if (current != NULL) current->back = NULL;
        } else if (current->next == NULL) {
            current = current->back;
            if (current != NULL) {
                current->next = NULL;
                curPosition--;
            }
        } else {
            current->back->next = current->next;
            current->next->back = current->back;
            current = current->next;
        }
        delete temp;
        --count;
        return success;
    }

    // 获取第position个位置的元素，保存在entry中

    // 若position < 0 或者 position >= count，则返回underflow

    Error_code retrieve(int position, List_entry &entry) const {
        if (position < 0 || position >= count) return underflow;
        setPosition(position);
        entry = current->entry;
        return success;
    }

    // 将第position个位置的元素替换为entry

    // 若position < 0 或者 position >= count，则返回underflow

    Error_code replace(int position, const List_entry &entry) {
        if (position < 0 || position >= count) return underflow;
        setPosition(position);
        current->entry = entry;
        return success;
    }

    // 用visit函数遍历list内所有的元素

    void traverse(void (*visit)(List_entry &)) {
        if (count == 0) return;
        setPosition(0);
        while (curPosition < count) {
            visit(current->entry);
            curPosition++;
            if (curPosition < count) current = current->next;
        }
        if (curPosition == count) curPosition--;
    }

protected:

    int count;                                                                          // 记录list内元素数量
    mutable int curPosition;                                   // current指针的位置编号
    mutable Node<List_entry> *current;                 // current指针
    // 设置current指针的位置，指向第position个位置
    void setPosition(int position) const {
        if (curPosition < position) {
            while (curPosition != position) {
                current = current->next;
                curPosition++;
            }
        } else if (curPosition > position) {
            while (curPosition != position) {
                current = current->back;
                curPosition--;
            }
        }
    }

};
