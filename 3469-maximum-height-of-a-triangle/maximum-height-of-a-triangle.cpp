class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        return max(solve(red,blue),solve(blue,red));
    }
    int solve(int first, int second)
    {
        int height=0;
        int line=1;
        while(first>=0&&second>=0)
        {
            if(line%2==1)
            first-=line;
            else
            second-=line;
            if(first<0||second<0)
            return height;
            line++;
            height++;
        }
        return height;
    }
};