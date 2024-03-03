class Solution {
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int s) {
        int n = edges.size();
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0; i<n;i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<int>ans;
        for(int i=0;i<=n;i++)
        {
            int total =0;
            int running_count = 0;
            for(auto it:adj[i])
            {
                int count_subtree = dfs(i,it.first,it.second,adj,s);
                total+= count_subtree*running_count;
                running_count+= count_subtree;
            }
            ans.push_back(total);
        }
        return ans;
    }
    int dfs(int i,int node, int weight, vector<vector<pair<int,int>>>&adj, int s)
    {
        int c=0;
        if(weight%s==0)
        c++;
        for(auto it:adj[node])
        {
            if(it.first!=i)
            c+=dfs(node,it.first,it.second+weight,adj,s);
        }
        return c;
    }
};