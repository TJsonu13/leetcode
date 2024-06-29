class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int mini,maxi;
        map<int,int>m;
        int left=0,right=0;
        int ans = 1;
        while(right<nums.size())
        {
            m[nums[right]]++;
            mini = m.begin()->first;
            maxi = m.rbegin()->first;
            while(abs(maxi-mini)>limit)
            {
                m[nums[left]]--;
                if(m[nums[left]]==0)
                m.erase(nums[left]);
                mini=m.begin()->first;
                maxi = m.rbegin()->first;
                left++;
            }
            ans = max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};