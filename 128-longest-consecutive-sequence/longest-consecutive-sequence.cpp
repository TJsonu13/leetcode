class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size())
        return 0;
        map<int,int>m;
        for(auto it:nums)
        m[it]++;
        auto it=m.begin();
        int prev= it->first;
        int ans=1;
        int c=1;
        for(auto it:m)
        {
            if(prev==it.first)
            continue;
            if(it.first-1==prev)
            c++;
            else
            c=1;
            prev=it.first;
            ans= max(ans,c);
        }
        return ans;
    }
};