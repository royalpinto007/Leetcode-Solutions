class Solution {
public:
    string removeDuplicates(string S) {
        int nRemoved = 0;
        
        do{
            nRemoved = 0;
            for(int i = 0; i < S.size() - 1;){
                if(S[i] == S[i+1]){
                    //remove from i, length 2
                    // cout << S.size() << ", " << i << endl;
                    S.erase(i, 2);
                    i--;
                    nRemoved++;
                }else{
                    i++;
                }
            }
        }while(nRemoved > 0 && S.size() > 0);
        
        return S;
    }
};