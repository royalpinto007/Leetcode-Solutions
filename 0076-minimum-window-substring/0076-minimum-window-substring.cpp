class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int, int> count;
        for (const auto& c : t) {
            ++count[c];
        }
        int remain = t.length();
        int left = -1, right = -1;
        for (int i = 0, j = 0; j < s.length(); ++j) {
            remain -= count[s[j]]-- > 0;
            if (remain) {
                continue;
            }
            while (count[s[i]] < 0) {
                ++count[s[i++]];
            }
            if (right == -1 || j - i + 1 < right - left + 1) {
                left = i;
                right = j;
            }
        }
        return left >= 0 ? s.substr(left, right - left + 1) : "";
    }
};