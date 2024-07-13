#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    while (curr != NULL) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}


int main() {
    int n, val;
    cout << "Enter the number of elements in the list: ";
    cin >> n;
    cout << "Enter the elements in the list: ";
    ListNode* head = NULL;
    ListNode* tail = NULL;
    for (int i = 0; i < n; ++i) {
        cin >> val;
        ListNode* newNode = new ListNode(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    head = reverseList(head);
    cout << "Reversed list: ";
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}

