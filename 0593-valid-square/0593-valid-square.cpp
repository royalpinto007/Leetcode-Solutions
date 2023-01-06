// using set
class Solution {
public:

    int find_dist(vector<int>& p1, vector<int>& p2) {
        return pow((p2[0]-p1[0]), 2) + pow((p2[1]-p1[1]), 2);
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int d12 = find_dist(p1, p2),
            d23 = find_dist(p2, p3),
            d34 = find_dist(p3, p4),
            d41 = find_dist(p4, p1),
            d13 = find_dist(p1, p3),
            d24 = find_dist(p2, p4);

        unordered_set <int> s;
        s.insert({d12, d23, d34, d41, d13, d24});

        return !s.count(0) && s.size() == 2;

    }
};