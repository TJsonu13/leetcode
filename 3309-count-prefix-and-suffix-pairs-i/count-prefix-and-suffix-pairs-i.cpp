class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans=0;
        for(int i=0;i<words.size();i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                if(words[i].size()>words[j].size())
                continue;
                int s= words[i].size();
                int s2= words[j].size();
                string prefix= words[j].substr(0,s);
                string suffix = words[j].substr(s2-s,s);
                if(prefix==words[i]&&suffix==words[i])
                ans++;
            }
        }
        return ans;
    }
};