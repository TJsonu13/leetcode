class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int c=0;
        int i=0,j=tokens.size()-1;
        int ans=0;
        while(i<=j)
        {
            while(i<=j&&tokens[i]<=power)
            {
                power-=tokens[i];
                c++;
                ans = max(c,ans);
                i++;
            }
            if(c)
            {
                power+=tokens[j];
                c--;
                j--;
            }
            else 
            break;
        }
        return ans;
    }
};