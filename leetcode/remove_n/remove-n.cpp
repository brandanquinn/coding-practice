#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * 
 */
class Solution {

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* reconnect = NULL;
        
        int remove_idx = get_size_of_list(head) - n;

        int count = 0;
        while(true) {
            if (curr == NULL) {
                break;
            }
            if (remove_idx == 0) {
                head = curr->next;
                break;
            }
            if (count == remove_idx) {
                reconnect = curr->next;
                prev->next = reconnect;
            }
            prev = curr;
            curr = curr->next;
            count++;
        }
        return head;   
    }
    
    int get_size_of_list(ListNode* head) {
        ListNode* curr = head;
        int size = 0;
        while (true) {
            if (curr == NULL)
                break;
            curr = curr->next;
            size++;
        }
        
        return size;
    }
};