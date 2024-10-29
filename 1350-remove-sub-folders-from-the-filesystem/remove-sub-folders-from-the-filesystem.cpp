class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string>ans;
        unordered_map<string,int>m;
        for(auto it:folder)
        m[it]++;
        for(int i=0;i<folder.size();i++)
        {
            string t="";
            for(int j=0;j<folder[i].size();j++)
            {
                if(folder[i][j]=='/'&&m.find(t)!=m.end())
                {
                    m.erase(folder[i]);
                    break;
                }
                else
                t+=folder[i][j];
            }
        }
        for(auto it:m)
        {
            ans.push_back(it.first);
        }
        return ans;
    }
};