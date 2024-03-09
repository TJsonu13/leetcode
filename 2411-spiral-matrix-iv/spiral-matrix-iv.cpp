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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>ans(m,vector<int>(n,-1));
        if(!head)
        return ans;
        int i=0,j=0;
        int leftcolumn=0,upperrow=0,rightcolumn=n-1,lowerrow=m-1;
        while(head)
        {
            while(j<=rightcolumn&&head)
            {
                ans[i][j++]=head->val;
                head= head->next;
            }
            upperrow++;
            i++;
            j--;
            while(i<=lowerrow&&head)
            {
                ans[i++][j]=head->val;
                head= head->next;
            }
            rightcolumn--;
            i--;
            j--;
            while(j>=leftcolumn&&head)
            {
                ans[i][j--]=head->val;
                head = head->next;
            }
            lowerrow--;
            i--;
            j++;
            while(i>=upperrow&&head)
            {
                ans[i--][j]=head->val;
                head = head->next;
            }
            leftcolumn++;
            i++;
            j++;
        }
        return ans;
    }
};