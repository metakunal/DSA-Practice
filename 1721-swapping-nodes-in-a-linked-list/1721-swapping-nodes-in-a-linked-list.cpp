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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* left=head;
        ListNode* right=head;
        ListNode* curr=head;
        int counter=1;
        while(curr!=NULL)
        {
            //Left pointer:
//Iterate through the Linked list, and while the counter is less than k, increment the left pointer.
//After the counter greater than or equal to k, we do not want to move the left pointer anymore since it is in the desired position.
            if(counter<k)
            {
                left = left->next;
            }
            
            // Right pointer:
// The right pointer should not start moving until our counter exceeds k, this way the right pointer 'lags' behind the current pointer by k nodes.
// After counter exceeds k, we increment it each iteration together with the current pointer, keeping the k node lag
            if(counter>k)
            {
                right=right->next;
            }
            curr=curr->next;
            counter++;
        }
        int temp= right->val;
        right->val=left->val;
        left->val=temp;
        
        return head;
    }
};