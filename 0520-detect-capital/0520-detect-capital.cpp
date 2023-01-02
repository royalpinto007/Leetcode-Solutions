// Approach:
// Initialize count=0
// if count equals 0 means all are small chars
// if count equals size of word then all are capital
// if count equals 1 then check is it the first char which is capital
// if none of the conditions are true then return false

class Solution {
public:
    bool detectCapitalUse(string word) {
        int count=0;
        if(word.size()==1)
            return true;
        
        for(int i=0; i<word.size(); i++)
            if(isupper(word[i]))
                count++;
        
        if(count==1 && isupper(word[0]))
            return true;
        if(count==0 || count==word.size())
            return true;
        else
            return false;
    }
};