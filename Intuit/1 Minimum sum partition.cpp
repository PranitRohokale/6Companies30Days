class Solution{
        bool subsetSumPossible(int idx,int currSum,vector<vector<bool>>&dp,int arr[])
        {
            if(currSum==0)return true;
            if(idx<0 )return false;
            
            if(dp[idx][currSum])return 1;
            
            if(currSum<arr[idx])
            return dp[idx][currSum] = subsetSumPossible(idx-1,currSum,dp,arr);
                
            
            return dp[idx][currSum] = subsetSumPossible(idx-1,currSum,dp,arr) ||
                                subsetSumPossible(idx-2,currSum-arr[idx],dp,arr);
        }
      public:
    	int minDifference(int arr[], int n)  { 
    	    // Your code goes here
    	    
    	    int sum = accumulate(arr,arr+n,0);
    	    
    	    // we only have to check maximum sum possible upto total_sum/2
    	    int requiredSum = (sum+1)/2;
    	    
    	    vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
    	    
    	   // subsetSumPossible(n-1,requiredSum,dp,arr);
    	   
    	   for(int i=0;i<=sum;i++)
    	        dp[0][i] = false;
    	   for(int i=0;i<=n;i++)
    	        dp[i][0] = true;
    	        
    	   for(int i=1;i<=n;i++)
    	   {
    	       for(int j=1;j<=sum;j++)
    	       {
    	           if(arr[i-1]>j)
    	                dp[i][j] = dp[i-1][j];
    	           else
    	                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
    	       }
    	   }
    
    	    
    	    for(int i=sum/2;i>=0;i--)
    	    {
    	       // cout<<i<<" "<<dp[n-1][i]<<"\n";
    
    	        if(dp[n][i])
    	        {
    	            return abs(sum-i*2);
    	        }
    	    }
    	    return -1;
    	} 
    };
