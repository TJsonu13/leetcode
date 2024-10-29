class Solution {
    int dp[1001][1001];
public:
    int maxMoves(vector<vector<int>>& grid) {
        int prev=-1;
        memset(dp,-1,sizeof(dp));
        int res =0;
        for(int  i=0;i<grid.size();i++)
        {
            int ans =solve(i,0,grid,prev)-1;
            res = max(res,ans);
        }
        return res;
    }
    int solve(int i,int j, vector<vector<int>>& grid,int prev)
    {
        if(i>=grid.size()||j>=grid[0].size()||i<0||j<0)
        return 0;
        if(prev!=-1&&prev>=grid[i][j])
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        return dp[i][j]=1+max({solve(i+1,j+1,grid,grid[i][j]),solve(i-1,j+1,grid,grid[i][j]),solve(i,j+1,grid,grid[i][j])});
    }
};