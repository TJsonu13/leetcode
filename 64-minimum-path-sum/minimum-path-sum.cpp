class Solution {
public:
int dp[201][201];
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,grid.size(),grid[0].size(),grid);
    }
    int solve(int i, int j, int n,int m , vector<vector<int>>&grid)
    {
        if(i==n-1&&j==m-1)
        return grid[i][j];
        if(i>=n||j>=m)
        return 1e9;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int right= grid[i][j]+solve(i,j+1,n,m,grid);
        int down = grid[i][j]+solve(i+1,j,n,m,grid);
        return dp[i][j] = min(right,down);
    }
};