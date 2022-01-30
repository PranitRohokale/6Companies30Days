class Solution {
public:
    bool winnerOfGame(string colors) {
        int as=0,bs=0;
        
        int n  =colors.size();
        for(int i=1;i<n-1;i++)
        {
            if( colors[i]=='A' && colors[i]==colors[i-1] && colors[i]==colors[i+1] )as++;
            else if(colors[i]=='B' && colors[i]==colors[i-1] && colors[i]==colors[i+1])bs++;                
        }
        char turn = 'A';
        if(as>bs)return 1;
        return 0;
    }
};
