class Solution{
public:
    int height(int x){
        // code here
        // n(n+1)/2 <= x
        // n^2+n-2x=0
        // then find factors
        return (-1 + sqrt(1+8*x))/2;
    }
};
