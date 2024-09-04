class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=1;
        for(int i=0;i<piles.size();i++)
        {
            high = max(high,piles[i]);
        }
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(valid(mid,piles,h))
            high=mid-1;
            else
            low= mid+1;
        }
        return low;
    }
    bool valid(int m,vector<int>&piles,int h){
        int c=0;
        for(int i=0;i<piles.size();i++)
        {
            if(piles[i]<=m)
            c++;
            else
            {
                c+=piles[i]/m;
                if(piles[i]%m!=0)
                c++;
            }
            if(c>h)
            return false;
        }
        return true;
    }
};