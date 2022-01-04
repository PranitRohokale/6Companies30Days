
// https://practice.geeksforgeeks.org/problems/find-the-position-of-m-th-item1723/1#
class Solution {
  public:
    int findPosition(int N , int M , int K) {
        // code here
        switch((M+K-1)%N)
        {
            case 0:
                return N;
            default:
                return (M+K-1)%N;
        }
        return -1;
    }
};

