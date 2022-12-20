class Solution {
public:
    bool isPalindrome(int x) {
        
        int n=x;
        long int rev=0;
        
        if(n<0) return false;
        
        while(n){
            int rem=n%10;
            rev=rev*10+rem;
            n=n/10;
        }
        
        if(rev == x) return true;
        
        else return false;
    }
};