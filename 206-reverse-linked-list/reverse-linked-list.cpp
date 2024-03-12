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
    ListNode* reverseList(ListNode* head) {
        if(!head)
        return head;
        ListNode* curr = head;
        ListNode* prev= NULL;
        if(head)
        head=head->next;
        while(head)
        {
            curr->next=prev;
            prev=curr;
            curr=head;
            head=head->next;
        }
        curr->next=prev;
        return  curr;
    }
};