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
    ListNode *detectCycle(ListNode *head) {
        struct ListNode *temp = NULL;
        struct ListNode *temp1 = NULL;
        bool loopExist = false;
        
        temp = head;
        temp1 = head;
        
        while(temp && temp1){
            temp1 = temp1->next;
            
            if(temp == temp1){
                loopExist = true;
                break;
            }
            if(temp1 == NULL){
                return NULL;
            }
            
            temp1 = temp1->next;
            if(temp == temp1){
                loopExist = true;
                break;
            }
            
            temp = temp->next;
        }
        
        if(loopExist){
            temp = head;
            while(temp != temp1){
                temp = temp->next;
                temp1 = temp1->next;
                if(temp1 == head){
                    return head;
                }
            }
            return temp;
        }
        else{
            return false;
        }
    }
};
