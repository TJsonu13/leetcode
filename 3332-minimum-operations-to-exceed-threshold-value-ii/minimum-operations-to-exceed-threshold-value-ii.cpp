class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long ,vector<long long>,greater<long long>>pq;
        for(auto it:nums)
        {
            pq.push(it);
        }
        int c=0;
        while(pq.size()&&pq.top()<k)
        {
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            long long min = a;
            long long max = b;
            if(a<b)
            max = b;
            else
            min = b;
            pq.push(2*min+max);
            c++;
        }
        return c;
    }
};