#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check rows
        for(int i=0;i<9;i++){
            map<char,int> m;
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(m[board[i][j]]==0){
                        m[board[i][j]]++;
                    }else{
                        return false;
                    }
                }
            }
        }
        // check cols
        for(int i=0;i<9;i++){
            map<char,int> m;
            for(int j=0;j<9;j++){
                if(board[j][i]!='.'){
                    if(m[board[j][i]]==0){
                        m[board[j][i]]++;
                    }else{
                        return false;
                    }
                }
            }
        }
        // check boxes 3x3
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                map<char,int> m;
                for(int x=i;x<i+3;x++){
                    for(int y=j;y<j+3;y++){
                        if(board[x][y]!='.'){
                            if(m[board[x][y]]==0){
                                m[board[x][y]]++;
                            }else{
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};