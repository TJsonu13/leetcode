class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>m;
        for(int i=0;i<arr1.size();i++)
        {
            m[arr1[i]]++;
        }
        int j=0;
        for(int i=0;i<arr2.size();i++)
        {
            while(m[arr2[i]])
            {
                arr1[j++]=arr2[i];
                m[arr2[i]]--;
                if(m[arr2[i]]==0)
                m.erase(arr2[i]);
            }
        }
        for(auto it:m)
        {
            int x= it.second;
            while(x)
            {
                arr1[j++]=it.first;
                x--;
            }
        }
        return arr1;
    }
};