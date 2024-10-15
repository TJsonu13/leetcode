class Solution {
public:
    long long minimumSteps(string s) {
        
        long long last = 0;
        long long ans =0;
        for(long long i=0;i<s.size();i++)
        {
            if(s[i]=='0')
            {
                ans+=(i-last);
                last++;
            }
        }
        return ans;
    }
};