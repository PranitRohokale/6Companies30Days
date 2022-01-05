
class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long mul = 1;
        int i=0,j=0,ans=0;
        
        while(j<n)
        {
            mul*=a[j];
            while(i<j && mul>=k)
                mul/=a[i++];
            if(mul<k)
                ans+=(j-i+1);
            j++;
        }
        return ans;
    }
};

