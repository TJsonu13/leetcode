class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,vector<int>>m;
        vector<int>ans(arr.size(),0);
        for(int i=0;i<arr.size();i++)
        {
            m[arr[i]].push_back(i);
        }
        int c=1;
        for(auto it:m)
        {
            for(auto x:it.second)
            {
                ans[x]=c;
            }
            c++;
        }
        return ans;
    }
};