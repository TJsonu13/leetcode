class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(auto it:nums)
        pq.push(it);
        long long ans =0;
        while(k)
        {
            int n = pq.top();
            pq.pop();
            ans+=(long long)n;
            pq.push(ceil(n));
            k--;
        }
        return ans;
    }
    int ceil(int n)
    {
        if(n%3)
        return n/3+1;
        return n/3;
    }
};