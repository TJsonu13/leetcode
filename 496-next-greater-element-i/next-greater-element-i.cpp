class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
        vector<int>v(nums2.size());
        for(int i=nums2.size()-1;i>=0;i--)
        {
            while(s.size()&&s.top()<=nums2[i])
            s.pop();
            if(s.size())
            v[i]=s.top();
            else
            v[i]=-1;
            s.push(nums2[i]);
        }
        vector<int>ans;
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                if(nums1[i]==nums2[j])
                ans.push_back(v[j]);
            }
        }
        return ans;
    }
};