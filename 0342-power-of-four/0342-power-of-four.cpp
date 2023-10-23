class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1)
            return true;
        if(n<=0)
            return false;

        double ans=log(n)/log(4);
    return (ans == (int)ans);
    }
};