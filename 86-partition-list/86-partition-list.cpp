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
    ListNode* partition(ListNode* head, int x) {
        ListNode* head1=new ListNode(1);
        ListNode* head2=new ListNode(2);
        ListNode* before=head1;
        ListNode* after=head2;
        ListNode* curr=head;
        while(curr!=NULL)
        {
            if(curr->val<x)
            {
                ListNode* temp=new ListNode(curr->val);
                before->next=temp;
                before=before->next;
            }
            else
            {
                ListNode* temp=new ListNode(curr->val);
                after->next=temp;
                after=after->next;   
            }
            curr=curr->next;
        }
       head2=head2->next;
        before->next=head2;
        return head1->next;
    }
};