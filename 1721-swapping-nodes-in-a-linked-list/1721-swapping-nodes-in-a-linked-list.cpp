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
        ListNode *curr = head;
        int i=0,front,last;
        while(curr!=NULL)
        {
            i++;
            
            if(i==k)
            {
                front = curr->val;
            }
            curr=curr->next;
        }
        curr=head;
        for(int j=0;j<(i-k);j++)
        {
            curr=curr->next;
        }
        last=curr->val;
        curr->val=front;
        curr=head;
        k--;
        while(k--)
        {
            curr=curr->next;
        }
        curr->val=last;
        cout<<front<<last;
        return head;
    }
};