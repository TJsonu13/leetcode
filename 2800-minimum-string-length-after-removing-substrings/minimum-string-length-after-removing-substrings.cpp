class Solution {
public:
    int minLength(string s) {
        int ans =0;
        stack<char>st;
        char prev;
        for(int i=0;i<s.size();i++)
        {
            if(!st.size())
            {
                prev= s[i];
                st.push(s[i]);
                continue;
            }
            char c= s[i];
            if((prev=='A'&&c=='B')||(prev=='C'&&c=='D'))
            {
                st.pop();
                if(st.size())
                prev=st.top();
            }
            else
            {st.push(c);
            prev=c;}
        }
        return st.size();
    }
};