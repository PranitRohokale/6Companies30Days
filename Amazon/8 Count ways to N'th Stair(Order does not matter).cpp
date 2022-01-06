class Solution
{
    public:
    //Function to count number of ways to reach the nth stair 
    //when order does not matter.
    long long countWays(int m)
    {
        /*
            one possible way is to use all 1's in path.
            
            second possible ways is to use only one 2 in path
            
            third possible ways is to use only two 2 in path
            
            four possible ways is to use only three 2 in path
            .....
            so basically we find the how many twos we add in a path + all one's path
            i.e total ways = the how many twos we add in a path + 1;
        */
        return ( 1 + int(m/2) );
    }
};
