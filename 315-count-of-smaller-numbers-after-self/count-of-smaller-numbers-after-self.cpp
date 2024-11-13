class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++)
        arr.push_back({nums[i],i});
        vector<int>count(n,0);
        mergesort(0,n-1,arr,count);
        return count;
    }
    void mergesort(int left, int right, vector<pair<int,int>>&arr,vector<int>&count)
    {
        if(left>=right)
        return ;
        int mid = left+(right-left)/2;
        mergesort(left,mid,arr,count);
        mergesort(mid+1,right,arr,count);

        merge(left,mid,right,arr,count);
    }
    void merge(int left, int mid, int right, vector<pair<int,int>>&arr,vector<int>&count)
    {
        int i= left;
        int j= mid+1;
        vector<pair<int,int>>temp;
        while(i<=mid&&j<=right)
        {
            if(arr[i].first<=arr[j].first)
            {
                temp.push_back(arr[j++]);
            }
            else
            {
                count[arr[i].second]+=(right-j+1);
                temp.push_back(arr[i++]);
            }
        }
        while(i<=mid)
        {
            temp.push_back(arr[i++]);
        }
        while(j<=right)
        {
            temp.push_back(arr[j++]);
        }
        for(int i=0;i<temp.size();i++)
        {
            arr[left+i]=temp[i];
        }
    }
};