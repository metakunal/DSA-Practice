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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
     ListNode *temp1 = headA;
        int l1=0;
        while(temp1!=NULL)
        {
            l1++;
            temp1=temp1->next;
        }
        int l2=0;
     ListNode *temp2 = headB;
         while(temp2!=NULL)
        {
            l2++;
            temp2=temp2->next;
        }
        int c =  abs(l1-l2);
        temp1=headA;
        temp2=headB;
        if(l1>l2)
        {
            while(c)
            {
                temp1=temp1->next;
                c--;
            }
        }
        else
        {
            while(c)
            {
                temp2=temp2->next;
                c--;
            }   
        }
        while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1==temp2)
                return temp1;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return NULL;
    }
};