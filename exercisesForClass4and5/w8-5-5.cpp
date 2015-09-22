/*************************************************************************
	> File Name: w8-5-5.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Friday, November 21, 2014 PM07:31:46 CST
 ************************************************************************/

#include <iostream>
using std::cout;
using std::endl;

template <class Record>
struct Node {
    Record entry;
    Node<Record> *next;
};

template <class Record>
class Sortable_list {

public:

    Sortable_list() : head(NULL) {}

    ~Sortable_list() {
        Node<Record> *temp = head;
        while (temp->next != NULL) {
            head = head->next;
            delete temp;
            temp = head;
        }
        delete head;
        head = NULL;
    }

    void insert(int position, const Record &entry) {
        Node<Record> *temp = new Node<Record>;
        temp->next = NULL;
        temp->entry = entry;
        if (position == 0) {
            temp->next = head;
            head = temp;
        } else {
            Node<Record> *ptr = head;
            while (--position) ptr = ptr->next;
            temp->next = ptr->next;
            ptr->next = temp;
        }
    }

    void print() {
        Node<Record> *ptr = head;
        while (ptr->next != NULL) {
            cout << ptr->entry << ' ';
            ptr = ptr->next;
        }
        cout << ptr->entry << endl;
    }

    void merge_sort() {
        recursive_merge_sort(head);
    }

    void recursive_merge_sort(Node<Record> *&sub_list) {
        if (sub_list == NULL || sub_list->next == NULL) return;
        Node<Record> *second_half = divide_from(sub_list);
        recursive_merge_sort(sub_list);
        recursive_merge_sort(second_half);
        sub_list = merge(sub_list, second_half);
    }

    Node<Record>* divide_from(Node<Record> *&sub_list) {
        Node<Record> *position, *midpoint = sub_list, *second_half;
        if (sub_list == NULL) return NULL;
        position = midpoint->next;
        while (position != NULL) {
            position = position->next;
            if (position != NULL) {
                midpoint = midpoint->next;
                position = position->next;
            }
        }
        second_half = midpoint->next;
        midpoint->next = NULL;
        return second_half;
    }

    Node<Record>* merge(Node<Record> *&first, Node<Record> *&second) {
        Node<Record> *last_sorted;
        Node<Record> *combined = new Node<Record>;
        last_sorted = combined;
        while (first != NULL && second != NULL) {
            if (first->entry <= second->entry) {
                last_sorted->next = first;
                last_sorted = first;
                first = first->next;
            } else {
                last_sorted->next = second;
                last_sorted = second;
                second = second->next;
            }
        }
        if (first == NULL) last_sorted->next = second;
        else last_sorted->next = first;
        return combined->next;
    }

private:

    Node<Record> *head;

};

