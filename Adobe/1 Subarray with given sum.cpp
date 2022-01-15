//Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        int start = 0 ,end = 0 ;
        long long sum = 0;
        while(end<n)
        {
            sum+=arr[end];
            while(start<=end && sum>s)
                sum-=arr[start++];
            if(sum==s)
                return {start+1,end+1};
            end++;
        }
        return {-1};
    }

