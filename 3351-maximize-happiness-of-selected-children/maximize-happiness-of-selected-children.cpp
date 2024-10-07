class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<long long>pq;
        for(int i=0;i<happiness.size();i++)
        pq.push(happiness[i]);
        int i=0;
        long long ans =0;
        while(pq.size()&&i<k)
        {
            int x= pq.top()-i;
            if(x<0)
            x=0;
            ans+=(long long)x;
            pq.pop();
            i++;
        }
        return ans;
    }
};