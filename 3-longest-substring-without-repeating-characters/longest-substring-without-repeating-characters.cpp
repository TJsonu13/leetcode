class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>m;
        int j=0;
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
            while(j<i&&m[s[i]]>1)
            {
                m[s[j]]--;
                if(m[s[j]]==0)
                m.erase(s[j]);
                j++;
            }
            ans= max(ans,i-j+1);
        }
        return ans;
    }
};