/*************************************************************************
	> File Name: 1001.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Sunday, January 04, 2015 AM09:51:00 CST
 ************************************************************************/

void List::insert(int toadd, int pos) {
    ListNode *temp = head;
    if (head == NULL) return;
    while (--pos) {
        temp = temp->next;
        if (temp == NULL) return;
    }
    ListNode *to_add = new ListNode;
    to_add->data = toadd;
    to_add->next = temp->next;
    temp->next = to_add;
}
