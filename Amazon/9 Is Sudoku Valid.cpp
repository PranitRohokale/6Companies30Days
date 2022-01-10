
class Solution{
public:
    int isValid(vector<vector<int>> mat){
        // code here
        // 2ways
            // 1. hash the each cell in specific format for recognizing  dublicancy
            // 2. using seperation matrix for row,col,boxes
        
        vector<vector<bool>>rowhash(9,vector<bool>(9,false));
        vector<vector<bool>>colhash(9,vector<bool>(9,false));
        vector<vector<bool>>boxhash(9,vector<bool>(9,false));
        
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(mat[i][j]==0)continue;
                
                int position = mat[i][j]-1;
                
                if(rowhash[i][position])return 0;
                else rowhash[i][position] = true;
                
                if(colhash[i][position])return 0;
                else colhash[i][position] = true;
                
                int x = (i/3)*3 + (j/3);
                if(boxhash[x][position])return 0;
                else boxhash[x][position] = true;
            }
        }
        return 1;
    }
};
