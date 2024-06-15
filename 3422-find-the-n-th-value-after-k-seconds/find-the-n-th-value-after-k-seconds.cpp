class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector<int>v(n,1);
        int mod = 1e9+7;
        for(int i=1;i<=k;i++)
        {
            int sum=1;
            for(int j=1;j<n;j++)
            {
                sum=(sum%mod+v[j]%mod)%mod;
                v[j]=sum%mod;
            }
        }
        return v[n-1]%mod;
    }
};