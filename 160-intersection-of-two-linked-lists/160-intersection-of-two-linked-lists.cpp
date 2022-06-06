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
        ListNode *tmp1=headA;
        ListNode *tmp2=headB;
        while(tmp1!=tmp2)
        {
            if(tmp1==NULL)
                tmp1=headA;
            else
                tmp1=tmp1->next;
            if(tmp2==NULL)
                tmp2=headB;
            else
                tmp2=tmp2->next;
        }
        return tmp1;
    }
};