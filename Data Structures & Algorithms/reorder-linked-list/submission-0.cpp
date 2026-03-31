/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        //double ptr
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != nullptr && fast->next !=nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }

        //reverse linked list from slow
        ListNode* curr = slow->next;
        ListNode* prev = slow->next = nullptr;
        while(curr != nullptr){
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        
        //Linked List Reordering
        ListNode* first = head;
        ListNode* second = prev;
        while (second != nullptr) {
            ListNode* tmp = first->next;
            first->next = second;
            first = tmp;
            tmp = second->next;
            second->next = first;
            second = tmp;
        }
        
    }
};
