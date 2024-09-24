class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_map<string,int>m;
        for(int i=0;i<message.size();i++)
        m[message[i]]++;
        int c=0;
        for(auto it:bannedWords)
        {
            if(m.count(it))
            {
                c+=m[it];
                m[it]--;
                if(m[it]==0)
                m.erase(it);
            }
            if(c>=2)
            return true;
        }
        return false;
    }
};