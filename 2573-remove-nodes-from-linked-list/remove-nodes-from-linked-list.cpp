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
ListNode* reverse(ListNode* head)
{
    ListNode* temp=head;
    ListNode* prev=nullptr;
    while(head)
    {
        head=head->next;
        temp->next=prev;
        prev=temp;
        temp=head;
    }
    return prev;
}
    ListNode* removeNodes(ListNode* head) {
        ListNode* curr=reverse(head);
        ListNode* prev=NULL;
        ListNode* ans=prev;
        int maxi=curr->val;
        while(curr)
        {
            maxi=max(maxi,curr->val);
            if(curr->val<maxi)
            {
                curr=curr->next;
            }
            else
            {
                if(!prev)
                {
                    prev=curr;
                    ans=prev;
                }
                else
                {
                    prev->next=curr;
                    prev=prev->next;
                }
                curr=curr->next;
            }
        }
        prev->next=nullptr;
        return reverse(ans);
    }
};