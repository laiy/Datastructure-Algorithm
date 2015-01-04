/*************************************************************************
	> File Name: 1000.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Sunday, January 04, 2015 AM09:35:53 CST
 ************************************************************************/

void List::remove(int pos) {
    ListNode *temp = head;
    if (head == NULL) return;
    while (--pos) {
        temp = temp->next;
        if (temp == NULL) return;
    }
    ListNode *to_delete = temp->next;
    temp->next = temp->next->next;
    delete to_delete;
}

