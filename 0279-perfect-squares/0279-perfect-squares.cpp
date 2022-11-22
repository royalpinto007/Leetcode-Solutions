class Solution {
public:
    int numSquares(int n) {
        /*
        if n = 4^a*(8b+7),
        n is a sum of 4 squares
        */
        while(n % 4 == 0){
            n /= 4;
        }
        
        if(n%8 == 7) return 4;
        
        for(int a = 0; a*a <= n; ++a){
            int b = sqrt(n-a*a);
            if(a*a + b*b == n){
                //!!a: (a != 0)
                return 1 + !!a;
            }
        }
        
        return 3;
    }
};