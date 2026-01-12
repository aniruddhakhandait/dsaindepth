#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next || k == 0)
        return head;

    // Step 1: Find length and tail
    ListNode* curr = head;
    int len = 1;
    while (curr->next) {
        curr = curr->next;
        len++;
    }

    // Step 2: Make it circular
    curr->next = head;

    // Step 3: Normalize k
    k = k % len;
    int stepsToNewTail = len - k;

    // Step 4: Find new tail
    ListNode* newTail = head;
    for (int i = 1; i < stepsToNewTail; i++) {
        newTail = newTail->next;
    }

    // Step 5: Break the circle
    ListNode* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

// Helper function to print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example: 1->2->3->4->5, k=2
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;
    cout << "Original List: ";
    printList(head);

    head = rotateRight(head, k);

    cout << "Rotated List: ";
    printList(head);

    return 0;
}
