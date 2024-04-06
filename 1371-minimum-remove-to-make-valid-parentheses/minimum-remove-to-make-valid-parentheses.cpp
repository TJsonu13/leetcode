class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else if(s[i]==')')
            if(st.size()&&s[st.top()]=='(')
            st.pop();
            else
            st.push(i);
        }
        string res;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(st.size()&&st.top()==i)
            {
                st.pop();
            }
            else
            res.push_back(s[i]);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};