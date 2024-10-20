class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int j =0;
        int ans =0;
        int cost =0;
        int length=0;
        for(int i=0;i<s.size();i++)
        {
            cost+=abs(s[i]-t[i]);
            length++;
            while(j<=i&&cost>maxCost)
            {
                cost-=abs(s[j]-t[j]);
                j++;
                length--;
            }
            ans = max(length, ans);
        }
        return ans;
    }
};