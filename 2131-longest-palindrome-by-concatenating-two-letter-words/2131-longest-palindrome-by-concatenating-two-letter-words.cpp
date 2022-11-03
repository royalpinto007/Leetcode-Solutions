class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        constexpr int alphabetSize = 26;
        vector count(alphabetSize, vector<int>(alphabetSize));
        for (const string& word : words) {
            count[word[0] - 'a'][word[1] - 'a']++;
        }
        int answer = 0;
        bool central = false;
        for (int i = 0; i < alphabetSize; i++) {
            if (count[i][i] % 2 == 0) {
                answer += count[i][i];
            } else {
                answer += count[i][i] - 1;
                central = true;
            }
            for (int j = i + 1; j < alphabetSize; j++) {
                answer += 2 * min(count[i][j], count[j][i]);
            }
        }
        if (central) {
            answer++;
        }
        return 2 * answer;
    }
};
// class Solution {
// public:
//     int longestPalindrome(vector<string>& words) {
//         unordered_map<string, int> count;
//         for (const string& word : words) {
//             count[word]++;
//         }

//         int answer = 0;
//         bool central = false;

//         for (const auto& [word, countOfTheWord] : count) {
//             // if the word is a palindrome
//             if (word[0] == word[1]) {
//                 if (countOfTheWord % 2 == 0) {
//                     answer += countOfTheWord;
//                 } else {
//                     answer += countOfTheWord - 1;
//                     central = true;
//                 }
//                 // consider a pair of non-palindrome words such that one is the
//                 // reverse of another ({word[1], word[0]} is the reversed word)
//             } else if (word[0] < word[1] && count.count({word[1], word[0]})) {
//                 answer += 2 * min(countOfTheWord, count[{word[1], word[0]}]);
//             }
//         }

//         if (central) {
//             answer++;
//         }
//         return 2 * answer;
//     }
// };