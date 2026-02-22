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
    ListNode* deleteMiddle(ListNode* head) {

        // brute force - using count variable
        // O(N) + O(N/2)
        // O(1)
        // optimal solution
        // TC - O(N/2)
        // SC - O(1)
        if(head == NULL || head->next == NULL) return NULL;

        ListNode* fast = head->next->next;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode* midNode = slow->next;
        slow->next = slow->next->next;
        delete midNode;
        return head;
    }
};
