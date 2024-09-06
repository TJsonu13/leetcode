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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* curr=head;
        ListNode* prev=NULL;
        unordered_map<int,int>m;
        for(auto it:nums)
        m[it]++;
        while(head)
        {
            if(m[head->val])
            {
                head=head->next;
            }
            else
            {
                if(!prev)
                {
                    prev=head;
                    curr=prev;}
                else
                {
                    prev->next=head;
                    prev=prev->next;
                }
                head=head->next;
                
            }
        }
        prev->next=nullptr;
        return curr;
    }
};