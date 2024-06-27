class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>v(n+2,0);
        for(int i=0;i<n;i++)
        {
            if(v[edges[i][0]]==1)
            return edges[i][0];
            if(v[edges[i][1]]==1)
            return edges[1][1];
            v[edges[i][0]]=1;
            v[edges[i][1]]=1;
        }
        return -1;
    }
};