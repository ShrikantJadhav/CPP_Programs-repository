/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        //Idea is to use two pointers
        //Move first pointer ahead by n nodes
        if(head == NULL) return head;
        
        if(head->next == NULL){
            delete head;
            return NULL;
        }
        
        ListNode *slow;
        ListNode *fast;
        ListNode *prevFast;
        
        slow = head;
        fast = head;
        
        for(int i = 1 ; i < n ;i++){
            if(slow)
                slow = slow -> next;
        }
        
        if(slow == NULL || slow->next == NULL){
            head = head->next;
            delete fast;
            return head;
        }
       
        while(slow->next != NULL){
            prevFast = fast;
            fast = fast->next;
            slow = slow->next;
        }
        
        if(fast){
            prevFast->next = fast->next;
            delete fast;
        }
        
        return head;
    }
};
