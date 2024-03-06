class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        int ind=(n/2);
        for(int i=ind;i>=0;i--)
        heapify(nums,n,i);
        for(int i=n-1;i>=0;i--)
        {
            swap(nums[i],nums[0]);
            heapify(nums,i,0);
        }
        return nums;
    }
    void heapify(vector<int>&nums ,int n,int ind)
    {
        int leftchild=2*ind+1;
        int rightchild=2*ind+2;
        int parent=ind;
        if(leftchild<n&&nums[leftchild]>nums[parent])
        parent=leftchild;
        if(rightchild<n&&nums[rightchild]>nums[parent])
        parent =rightchild;
        if(parent!=ind)
        {
            swap(nums[ind],nums[parent]);
            heapify(nums,n,parent);
        }
    }
};