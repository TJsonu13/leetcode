class Solution {
public:
    int numberOfChild(int n, int k) {
        int x= k/(n-1);
        if(x%2==0)
        return k%(n-1);
        return n-k%(n-1)-1;
    }
};