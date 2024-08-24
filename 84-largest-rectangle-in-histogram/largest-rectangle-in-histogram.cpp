class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>min_right_i(heights.size()),min_left_i(heights.size());
        min_right_i[heights.size()-1]=heights.size();
        stack<int>st;
        for(int i=heights.size()-1;i>=0;i--)
        {
            while(st.size()&&heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(st.size())
            min_right_i[i]=st.top();
            else
            min_right_i[i]=heights.size();
            st.push(i);
        }
        stack<int>s;
        for(int i=0;i<heights.size();i++)
        {
            while(s.size()&&heights[s.top()]>=heights[i])
            s.pop();
            if(s.size())
            min_left_i[i]=s.top();
            else
            min_left_i[i]=-1;
            s.push(i);
        }
        int ans =0;
        for(int i=0;i<heights.size();i++)
        {
            ans = max(ans,(min_right_i[i]-min_left_i[i]-1)*heights[i]);
        }
        return ans;
    }
};