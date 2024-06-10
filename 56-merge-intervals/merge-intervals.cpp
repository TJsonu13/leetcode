class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int i=0;
        int j=1;
        while(i<intervals.size())
        {
            int num = intervals[i][1];
            int a = intervals[i][0];
            while(i<intervals.size()&&num>=intervals[i][0])
            {
                num = max(num,intervals[i][1]);
                i++;
            }
            ans.push_back({a,num});

        }
        return ans;
    }
};