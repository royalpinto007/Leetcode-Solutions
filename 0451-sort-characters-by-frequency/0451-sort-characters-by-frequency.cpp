class Solution 
{
public:
    string frequencySort(string s) 
    {
        int cnt[128] = {0};
        for (char c : s) ++cnt[c];
        
        auto cmp = [&](char a, char b)
        {
            return cnt[a] > cnt[b] || (cnt[a] == cnt[b] && a < b); 
        };

        sort(s.begin(), s.end(), cmp);
        
        return s;
    }
};