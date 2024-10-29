class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int>m;
        int ans =-1;
        for(int i=0;i<nums.size();i++)
        {
            int root = sqrt(nums[i]);
            if(root*root == nums[i]&&m.find(root)!=m.end())
            {
                m[nums[i]]=m[root]+1;
                ans= max(ans,m[nums[i]]);
            }
            else
            m[nums[i]]=1;
        }
        return ans;
    }
};