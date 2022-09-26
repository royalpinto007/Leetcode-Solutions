class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind union_find(26);
        for (const auto& eqn : equations) {
            int x = eqn[0] - 'a';
            int y = eqn[3] - 'a';
            if (eqn[1] == '=') {
                union_find.union_set(x, y);
            }
        }
        for (const auto& eqn : equations) {
            int x = eqn[0] - 'a';
            int y = eqn[3] - 'a';
            if (eqn[1] == '!') {
                if (union_find.find_set(x) == union_find.find_set(y)) {
                    return false;
                }
            }
        }
        return true; 
    }
    

private:
    class UnionFind {
    public:
        UnionFind(const int n) : set_(n) {
            iota(set_.begin(), set_.end(), 0);
        }

        int find_set(const int x) {
           if (set_[x] != x) {
               set_[x] = find_set(set_[x]);  // Path compression.
           }
           return set_[x];
        }

        bool union_set(const int x, const int y) {
            int x_root = find_set(x), y_root = find_set(y);
            if (x_root == y_root) {
                return false;
            }
            set_[min(x_root, y_root)] = max(x_root, y_root);
            return true;
        }

    private:
        vector<int> set_;
    };
};