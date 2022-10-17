class Solution {
public:
    bool checkIfPangram(string sentence) {
        int c[26]={0};
        for(char ch:sentence)
        {
            c[ch-'a']++;
        }
        for(int i:c)
        {
            if(i==0)
                return false;
        }
        return true;
    }
};