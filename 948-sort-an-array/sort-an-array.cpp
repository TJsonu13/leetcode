class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return nums;
    }
    void mergesort(vector<int>&nums, int left, int right)
    {
        if(left>=right)
        return ;
        int mid= left+(right-left)/2;
        mergesort(nums,left,mid);
        mergesort(nums,mid+1,right);
        merge(nums,left,mid,right);
    }
    void merge(vector<int>&nums,int low, int mid, int high)
    {
        int left =low;
        int right = mid+1;
        vector<int>temp;
        while(left<=mid&&right<=high)
        {
            if(nums[left]>nums[right])
            temp.push_back(nums[right++]);
            else
            temp.push_back(nums[left++]);
        }
        while(left<=mid)
        temp.push_back(nums[left++]);
        while(right<=high)
        temp.push_back(nums[right++]);

        for(int i= low;i<=high;i++)
        {
            nums[i] = temp[i-low];
        }
    }
};