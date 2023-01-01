class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string buf;
        stringstream str(s);
        vector<string> words;
        while (str >> buf)
            words.push_back(buf);
        
        if (words.size() != pattern.size())
            return false;

        unordered_map<char, string> phash;
        unordered_map<string, char> shash;
        for (int i = 0; i < words.size(); i++) {
            if (phash.find(pattern[i]) != phash.end() && phash[pattern[i]] != words[i] ||
                shash.find(words[i]) != shash.end() && shash[words[i]] != pattern[i])
                return false;
            phash[pattern[i]] = words[i];
            shash[words[i]] = pattern[i];
        }
        return true;
    }
};