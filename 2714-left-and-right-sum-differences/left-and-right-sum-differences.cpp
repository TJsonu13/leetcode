class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sum =0;
        for(int i=0;i<nums.size();i++)
        sum+=nums[i];
        vector<int>ans;
        int leftsum=0;
        for(int i=0;i<nums.size();i++)
        {
            ans.push_back(abs(leftsum-(sum-leftsum-nums[i])));
            leftsum+=nums[i];
        }
        return ans;
    }
};