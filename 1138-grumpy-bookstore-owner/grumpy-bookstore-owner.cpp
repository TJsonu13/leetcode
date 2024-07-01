class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum =0;
        for(int i=0;i<customers.size();i++)
        if(grumpy[i]==0)
        sum+=customers[i];

        int ans = sum;
        int currsum =sum;
        for(int i=0;i<minutes;i++)
        currsum+=customers[i]*grumpy[i];
        ans = currsum;
        for(int i=minutes;i<customers.size();i++)
        {
            currsum+= customers[i]*grumpy[i];
            currsum-= customers[i-minutes]*grumpy[i-minutes];
            ans = max(currsum,ans);
        }
        return ans;
    }
};