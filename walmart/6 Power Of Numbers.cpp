long long power(int N,int R)
    {
       //Your code here
        if(R==0)return 1;
        
        long long ans = power(N,R/2)%mod;
        if(R&1)
            return ((ans*ans)%mod*N)%mod;
        return (ans*ans)%mod;
    }

https://practice.geeksforgeeks.org/problems/power-of-numbers-1587115620/1/?company[]=Walmart&company[]=Walmart&page=1&query=company[]Walmartpage1company[]Walmart#
