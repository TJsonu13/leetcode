class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m= matrix[0].size();
        int ans =0;
        vector<vector<int>>vis(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans+=solve(i,j,n,m,matrix,vis);
            }
        }
        return ans;
    }
    int solve(int i,int j, int n, int m, vector<vector<int>>&matrix,vector<vector<int>>&vis)
    {
        if(i>=n||j>=m||i<0||j<0)
        return false;
        if(vis[i][j]!=-1)
        return vis[i][j];
        if(!matrix[i][j])
        return 0;
        int down = solve(i+1,j,n,m,matrix,vis);
        int diag = solve(i+1,j+1,n,m,matrix,vis);
        int right = solve(i,j+1,n,m,matrix,vis);
        return vis[i][j]=1+min({down,diag,right});
    }
};