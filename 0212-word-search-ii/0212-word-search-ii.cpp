class TrieNode{
public:
    vector<TrieNode*> children;
    string word;
    
    TrieNode(){
        children = vector<TrieNode*>(26, nullptr);
    }
};

class Trie{
public:
    TrieNode* root;
    
    Trie(){
        root = new TrieNode();
    }
    
    void add(string word){
        TrieNode* cur = root;
        for(char c : word){
            if(cur->children[c-'a'] == nullptr){
                cur->children[c-'a'] = new TrieNode();
            }
            cur = cur->children[c-'a'];
        }
        /*
        store the word at leaf,
        so we don't need to reconstruct it
        */
        cur->word = word;
    }
    
    bool find(string word){
        TrieNode* cur = root;
        for(char c : word){
            cur = cur->children[c-'a'];
            if(cur == nullptr){
                return false;
            }
        }
        
        return true;
    }
};

class Solution {
public:
    Trie* trie;
    
    void dfs(vector<vector<char>>& board, int m, int n, int ci, int cj, TrieNode* node, vector<string>& ans){
        //current building string "str" is replaced by "node"
        //visited is replaced by '#'
        char c = board[ci][cj];
        //visited
        if(c == '#') return;
        //cannot find int trie
        if(node->children[c-'a'] == nullptr) return;
        
        node = node->children[c-'a'];
        if(node->word != ""){
            ans.push_back(node->word);
            //de-duplicate
            //so that it won't be found again
            node->word = "";
        }
        
        //mark as visited
        board[ci][cj] = '#';
        
        if(ci > 0)   dfs(board, m, n, ci-1, cj,   node, ans);
        if(ci+1 < m) dfs(board, m, n, ci+1, cj,   node, ans);
        if(cj > 0)   dfs(board, m, n, ci,   cj-1, node, ans);
        if(cj+1 < n) dfs(board, m, n, ci,   cj+1, node, ans);
                
        board[ci][cj] = c;
    };
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        if(m == 0) return vector<string>();
        int n = board[0].size();
        
        trie = new Trie();
        
        for(string& word : words){
            trie->add(word);
        }
        
        vector<string> ans;
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                dfs(board, m, n, i, j, trie->root, ans);
            }
        }
        
        return ans;
    }
};

// class Solution {
// public:
//     static constexpr int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
//     vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
//         int wordLength = words.size();
//         int m = board.size();
//         int n = board[0].size();
//         vector<string> res;
//         for (int l = 0; l < wordLength; ++l) {
//             bool find = false;
//             for (int i = 0; i < m; ++i) {
//                 for (int j = 0; j < n; ++j) {
//                     if (board[i][j] == words[l][0] && DFS(board, i, j, m, n, 0, words[l])) {
//                         res.push_back(words[l]);
//                         find = true;
//                         break;
//                     }
//                 }
//                 if (find)
//                     break;
//             }
//         }
//         return res;
//     }
    
//     bool DFS(vector<vector<char>>& board, int r, int c, int rows, int cols, int ind, string& word) {
//         if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != word[ind])
//             return false;
//         if (ind == word.length() - 1)
//             return true;
//         bool isExist = false;
//         char orig = board[r][c];
//         board[r][c] = '*';
//         for (int i = 0; i < 4; ++i) {
//             int nr = r + dirs[i][0];
//             int nc = c + dirs[i][1];
//             isExist = isExist || DFS(board, nr, nc, rows, cols, ind + 1, word);
//         }
//         board[r][c] = orig;
//         return isExist;
//     }
// };

// class Solution {
// public:
// 	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
// 		Node* root = new Node();
// 		for (auto& word : words)
// 			insert(root, word);

// 		int m = board.size(), n = m ? board[0].size() : 0;
// 		vector<string> res;
// 		for (int i = 0; i < m; ++i)
// 		{
// 			for (int j = 0; j < n; ++j)
// 			{
// 				char c = board[i][j];
// 				if (root->children[c])
// 					backtrack(board, res, root->children[c], string(1, c), i, j);
// 			}
// 		}
// 		return res;
// 	}

// private:
// 	struct Node
// 	{
// 		bool isWord;
// 		unordered_map<char, Node*> children;

// 		Node() : isWord(false)
// 		{

// 		}
// 	};

// 	void insert(Node* curr, string word)
// 	{
// 		int i = 0;
// 		while (i < word.size())
// 		{
// 			char c = word[i];
// 			if (!curr->children[c])
// 				curr->children[c] = new Node();
// 			curr = curr->children[c];
// 			++i;
// 		}
// 		curr->isWord = true;
// 	}

// 	void backtrack(vector<vector<char>>& board, vector<string>& res, Node* node, string curr, int x, int y)
// 	{
// 		int m = board.size(), n = m ? board[0].size() : 0;
// 		if (!node)return;
// 		if (node->isWord)
//         {
// 			res.push_back(curr);
//             node->isWord = false;
//         }

// 		vector<pair<int, int>> dirs = { { 1, 0 },{ -1, 0 },{ 0, 1 },{ 0, -1 } };
// 		char c = board[x][y];
// 		board[x][y] = '.';
// 		for (auto& dir : dirs)
// 		{
// 			int i = x + dir.first, j = y + dir.second;
// 			if (i >= 0 && i < m && j >= 0 && j < n && board[i][j] != '.' && node->children.find(board[i][j]) != node->children.end())
// 				backtrack(board, res, node->children[board[i][j]], curr + board[i][j], i, j);
// 		}
// 		board[x][y] = c;
// 	}
// };

// TLE
// class Solution {
// private:
//     struct TrieNode {
//         bool isString = false;
//         unordered_map<char, TrieNode *> leaves;
        
//         bool Insert(const string& s) {
//             auto* p = this;
//             for (const auto& c : s) {
//                 if (p->leaves.find(c) == p->leaves.cend()) {
//                     p->leaves[c] = new TrieNode;
//                 }
//                 p = p->leaves[c];
//             }
            
//             // s already existed in this trie.
//             if (p->isString) {
//                 return false;
//             } else {
//                 p->isString = true;
//                 return true;
//             }
//         }
        
//         ~TrieNode() {
//             for (auto& kv : leaves) {
//                 if (kv.second) {
//                     delete kv.second;
//                 }
//             }
//         }
//     };
    
// public:
//     /**
//      * @param board: A list of lists of character
//      * @param words: A list of string
//      * @return: A list of string
//      */
//     vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
//         unordered_set<string> ret;
//         vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
//         string cur;
//         TrieNode trie;
//         for (const auto& word : words) {
//             trie.Insert(word);
//         }
        
//         for (int i = 0; i < board.size(); ++i) {
//             for (int j = 0; j < board[0].size(); ++j) {
//                 findWordsDFS(board, visited, &trie, i, j, cur,  ret);
//             }
//         }
        
//         return vector<string>(ret.begin(), ret.end());
//     }
    
//     void findWordsDFS(vector<vector<char>> &grid,
//              vector<vector<bool>> &visited,
//              TrieNode *trie,
//              int i,
//              int j,
//              string cur,
//              unordered_set<string> &ret) {
//         // Invalid state.
//         if (!trie || i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
//             return;
//         }
        
//         // Not in trie or visited.
//         if (!trie->leaves[grid[i][j] ] || visited[i][j]) {
//             return;
//         }
        
//         // Get next trie nodes.
//         TrieNode *nextNode = trie->leaves[grid[i][j]];
        
//         // Update current string.
//         cur.push_back(grid[i][j]);
        
//         // Find the string, add to the answers.
//         if (nextNode->isString) {
//             ret.insert(cur);
//         }
        
//         // Marked as visited.
//         visited[i][j] = true;
        
//         // Try each direction.
//         const vector<pair<int, int>> directions{{0, -1}, {0, 1},
//                                                 {-1, 0}, {1, 0}};
//         for (const auto& d : directions) {
//             findWordsDFS(grid, visited, nextNode,
//                          i + d.first, j + d.second, cur, ret);
//         }
        
//         visited[i][j] = false;
//     }
// };