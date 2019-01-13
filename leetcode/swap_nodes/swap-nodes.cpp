// INCOMPLETE


#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp;
        ListNode* curr;
        ListNode* prev;
        
        bool first_swap = true;
        
        curr = head;
        while (curr != NULL && curr->next != NULL) {
            if (first_swap) {
                head = curr->next;
                first_swap = false;
                curr = swap_nodes(curr, curr->next);
                prev = curr;
            }
            if (curr->next != NULL) {
                curr = swap_nodes(curr, curr->next);
                prev->next = curr;
                prev = curr;
            }
            
            

        }
        
        return head;
    }
        
    ListNode* swap_nodes(ListNode* one, ListNode* two) {
        cout << "Node 1 in pair before swap: " << one->val << endl;
        cout << "Node 2 in pair before swap: " << two->val << endl;
        ListNode* temp = one;
        ListNode* next_node = two->next;
        one = two;
        one->next = temp;
        two = temp;
        two->next = next_node;
    
        cout << "Node 1 in pair after swap: " << one->val << endl;
        cout << "Node 2 in pair after swap: " << two->val << endl;
        if (next_node == NULL)
            cout << "Next node is NULL, swapping complete." << endl;
        else
            cout << "Value of next_node: " << next_node->val << endl;
        
        return next_node;
    }
};

int main() {
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    a->next = b;
    ListNode* c = new ListNode(3);
    b->next = c;
    ListNode* d = new ListNode(4);
    c->next = d;

    ListNode* curr = a;
    cout << "List before reverse: ";
    while (curr != NULL) {
        cout << curr->val << " -> ";
        curr = curr->next;
    }
    cout << endl;

    Solution s;
    ListNode* reverse_head = s.swapPairs(a);
    curr = reverse_head;
    cout << "List after reverse: ";
    while (curr != NULL) {
        cout << curr->val << " -> ";
        curr = curr->next;
    }
    cout << endl;
    
    return 0;
}