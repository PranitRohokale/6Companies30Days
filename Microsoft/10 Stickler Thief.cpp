// https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1/#
    //Function to find the maximum money the thief can get.
    
    //using recursion 
    //exponential (2^n)
    int helper(int arr[],int n)
    {
        if(n<0)return 0;
        
        int inclu = helper(arr,n-2) + arr[n];
        int exclu = helper(arr,n-1);
        
        return max(inclu,exclu);
    }
    //using dp tabular O(n)/O(1)
    int helper1(int arr[],int n)
    {
        int inclusive = arr[0] , exclusive = 0;
        
        for(int i=1;i<n;i++)
        {
            int temp = inclusive;
            inclusive = max(inclusive , exclusive+arr[i]);
            exclusive = temp;
        }
        return inclusive;
        
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        
        return helper(arr,n-1);
        return helper1(arr,n);
    }
