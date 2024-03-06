class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>m;
        for(auto it:tasks)
        m[it]++;
        vector<int>c;
        for(auto it:m)
        c.push_back(it.second);
        sort(c.rbegin(),c.rend());
        int ans = 0;
        int total = 0;
        for(int i=0;i<c.size();i++)
        {
            total+=c[i];
            ans =max(ans,i+(c[i]-1)*n+c[i]);
            if(ans<total)
            ans = total;
        }
        return ans;
    }
};