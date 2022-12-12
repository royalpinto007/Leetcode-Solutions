class Solution {
public:
    int climbStairs(int n) {
        int prev=1,next=1;
        while(--n){
            next = prev+next;
            prev=next-prev;
        }
        return next;
    }
};