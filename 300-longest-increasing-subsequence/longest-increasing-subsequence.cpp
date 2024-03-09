class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ans(nums.size(),1);
        int res = 1;
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                ans[i]= max(ans[i],1+ans[j]);
            }
            res = max(res,ans[i]);
        }
        return res;
    }
};