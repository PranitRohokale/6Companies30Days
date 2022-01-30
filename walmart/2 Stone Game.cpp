class Solution {
public:
    bool stoneGame(vector<int>& piles) {
       int evenpiles = 0 , oddpiles = 0 , n =piles.size();
        for(int i=0;i<n;i++)
            if(oddpiles&1)
                oddpiles+=piles[i];
            else
                evenpiles+=piles[i];
        
        return max(oddpiles,evenpiles);
    }
};
