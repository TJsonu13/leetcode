class Solution {
public:
    string compressedString(string word) {
        char prev = word[0];
        int repeat =1;
        string comp ="";
        for(int i=1;i<word.size();i++)
        {
            if(prev==word[i]&&repeat!=9)
            {
                repeat++;
                continue;
            }
            comp+=to_string(repeat);
            comp+=prev;
            repeat=1;
            prev=word[i];
        }
            comp+=to_string(repeat);
            comp+=prev;
        return comp;
    }
};