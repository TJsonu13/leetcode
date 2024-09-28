class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        priority_queue<pair<long long, pair<long long,long long>>,vector<pair<long long,pair<long long,long long>>>,greater<pair<long long,pair<long long,long long>>>>pq;
        for(int i=0;i<workerTimes.size();i++)
        pq.push({workerTimes[i],{workerTimes[i],1}});
        long long ans=0;
        for(int i=0;i<mountainHeight;i++)
        {
            long long time = pq.top().first;
            long long original = pq.top().second.first;
            long long h = pq.top().second.second;
            ans = time;
            pq.pop();
            pq.push({time+(long long)original*(h+1),{original,h+1}});
        }
        return ans;
    }
};