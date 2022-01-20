class Solution{
  public:
    string nextPalin(string str) { 
        //complete the function here
        int n = str.size();
        string firsthalf = str.substr(0,n/2);
        string ans = "-1";
        if(n<4)return ans;
        
        if(next_permutation(firsthalf.begin(),firsthalf.end()))
        {
            ans = firsthalf;
            if(n&1)ans+=str[n/2];
            reverse(firsthalf.begin(),firsthalf.end());
            ans+=firsthalf;
        }
        
        return ans;
    }
};
