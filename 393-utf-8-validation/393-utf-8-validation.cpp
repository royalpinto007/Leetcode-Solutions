#include <vector>

class Solution {
public:
    bool validUtf8(std::vector<int>& data) {
        int idx = 0;
        int count = 1;
        while (idx < data.size()) {
            int first_byte = data[idx];
            if ((first_byte & 0x80) == 0x00) {
                // use 1000 0000 as mask to see if start with 0
                count = 1;
            } else if ((first_byte & 0xe0) == 0xc0) {
                // use 1110 0000 as mask to see if start with 110
                count = 2;
            } else if ((first_byte & 0xf0) == 0xe0) {
                // use 1111 0000 as mask to see if start with 1110
                count = 3;
            } else if ((first_byte & 0xf8) == 0xf0) {
                // use 1111 1000 as mask to see if start with 11110
                count = 4;
            } else {
                return false;
            }

            while (count > 1) {
                idx++;
                count--;
                // thr following count - 1 byte should all start with 10
                if (idx == data.size() || (data[idx] & 0xc0) != 0x80)
                    return false;
            }
            idx++;
        }

        return count == 1;
    }
};

// class Solution {
// private:
//     int byteLength(int n)
//     {
//         if ((n >> 7) == 0b0)
//         {
//             return 1;
//         }
//         else if ((n >> 5) == 0b110)
//         {
//             return 2;
//         }
//         else if ((n >> 4) == 0b1110)
//         {
//             return 3;
//         }
//         else if ((n >> 3) == 0b11110)
//         {
//             return 4;
//         }
        
//         return 0;
//     }
// public:
//     bool validUtf8(vector<int>& data) {
        
//         if (data.size() == 0)
//         {
//             return false;
//         }
        
//         int i = 0;
        
//         while (i < data.size())
//         {
//             int n = data[i];
//             int len = byteLength(n);
            
//             if (len == 0 || i + len - 1 >= data.size())
//             {
//                 return false;
//             }
            
//             for (auto j = i + 1; j <= i + len - 1; ++j)
//             {
//                 if (data[j] >> 6 != 0b10)
//                 {
//                     return false;
//                 }
//             }
            
//             i = i + len;
//         }
        
//         return true;
//     }
// };