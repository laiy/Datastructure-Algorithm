enum Error_code {
    success,
    underflow,
    overflow
};

template <class List_entry>
struct Node {
    List_entry entry;
    Node<List_entry> *next;
};

template <class List_entry>
class MyList {
public:

    MyList();

    ~MyList();

    // 拷贝构造函数和赋值运算符重载，注意深拷贝与浅拷贝的差异

    MyList(const MyList<List_entry> &copy);

    void operator =(const MyList<List_entry> &copy);

    // 清空list

    void clear();

    // 判断list是否为空

    bool empty() const;

    // 判断list是否已满

    bool full() const;

    // 获取list的元素数量

    int size() const;

    // 在第position个位置插入值为entry的元素，如果position为0则插入在链表头，依次类推
    // 若position < 0 或者 position > count，则返回underflow

    Error_code insert(int position, const List_entry &entry);

    // 删除第position个位置的元素，并将该元素的值保存在entry中
    // 若position < 0 或者 position >= count，则返回underflow

    Error_code remove(int position, List_entry &entry);

    // 获取第position个位置的元素，保存在entry中
    // 若position < 0 或者 position >= count，则返回underflow

    Error_code retrieve(int position, List_entry &entry) const;

    // 将第position个位置的元素替换为entry
    // 若position < 0 或者 position >= count，则返回underflow

    Error_code replace(int position, const List_entry &entry);

    // 用visit函数遍历list内所有的元素

    void traverse(void (*visit)(List_entry &));

protected:

    int count;                                                                          // 记录list内元素数量
    Node<List_entry> *head;                                         // 链表头指针
    mutable int curPosition;                                   // current指针的位置编号
    mutable Node<List_entry> *current;                 // current指针
    // 设置current指针的位置，指向第position个位置
    void setPosition(int position) const;

};

