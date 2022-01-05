//using recursion
class Solution {
    int mod = 1e9+7;
	public:
		int CountWays(string str){
		    // Code here
		    int n = str.size();
		    if(n==0)return 1;
		    
		    int ways = CountWays(str.substr(1));

	        if(n>1 && str[0]=='1' || (str[0]=='2' && (str[1]-'0')<=6))
	            ways  = (ways + CountWays(str.substr(2)))%mod;

		    return ways;
		}

};

//using dp
class Solution {
    int parseint(char ch)
    {
        return (ch-'0');
    }
public:
    
    int numDecodings(string s) {
        int n = s.size()+1;
        vector<int>dp(n,0);
        
        dp[0] = 1 ;//empty string has 1 way
        if(s[0]=='0')
            return 0;
        else
            dp[1] = 1;
        
                
        for(int i=2;i<n;i++)
        {
            if(s[i-1]=='0') // current is 0
            {
                if(s[i-2]=='1' || s[i-2]=='2')
                    dp[i] = dp[i-2];
                else
                    return 0;
            }else{

                if(s[i-2]=='1' || (s[i-2]=='2' && parseint(s[i-1]) < 7))
                    dp[i] = dp[i-1] + dp[i-2];
                else
                    dp[i] = dp[i-1];
            }
        }
        // for(auto v:dp)
        //     cout<<v<<" ";
        return dp[n-1];
    }
    
};
