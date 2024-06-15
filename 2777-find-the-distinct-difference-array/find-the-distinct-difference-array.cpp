class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        unordered_map<int,int>m,m2;
        for(int i=0;i<nums.size();i++)
        m[nums[i]]++;
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            m2[nums[i]]++;
            m[nums[i]]--;
            if(m[nums[i]]==0)
            m.erase(nums[i]);
            ans.push_back(m2.size()-m.size());
        }
        return ans;
    }
};