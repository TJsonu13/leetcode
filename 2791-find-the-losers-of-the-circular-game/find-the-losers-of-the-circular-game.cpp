class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int>v(n+1,0);
        int x=1;
        v[1]=1;
        int prev =1;
        while(true)
        {
            int mark = prev+x*k;
            mark=mark%n;
            if(mark==0)
            mark=n;
            if(v[mark])
            break;
            v[mark]=1;
            prev= mark;
            x++;
        }
        vector<int>ans;
        for(int i=1;i<v.size();i++)
        if(!v[i])
        ans.push_back(i);
        return ans;
    }
};