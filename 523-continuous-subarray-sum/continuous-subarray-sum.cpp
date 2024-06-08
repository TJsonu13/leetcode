class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n= nums.size();
        if(n<2)
        return false;
        int sum=nums[0]+nums[1];
        if(sum%k==0)
        return true;
        int correct_sum;
        for(int i=2;i<n;i++)
        {
            if (nums[i] == nums[i - 1] && nums[i] == 0) {
                return true;
            }
            sum+=nums[i];
            if(sum%k==0)
            return true;
            int j=0;
            correct_sum = sum;
            while(j<i-1&&correct_sum>=k)
            {
                correct_sum-=nums[j];
                if(correct_sum%k==0)
                return true;
                j++;
            }
        }
        return false;
    }
};