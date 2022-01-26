class Solution {
    int dir[5] = {1,0,-1,0,1};
    bool dfs(string str,int i,int j,vector<vector<char>>& board)
    {
        if(str.size()==0)return true;
        
        int n=board.size(),m=board[0].size();
        if(i<0 || j<0 || i>=n || j>=m || str[0]!=board[i][j])return false;
        
        
        char ch = board[i][j];
        board[i][j]=' ';
        bool flag = false;
        for(int k=0;k<4;k++)
        {
            int x = i + dir[k] , y = j + dir[k+1];
            if(dfs(str.substr(1),x,y,board))
            {
                flag = true;
                break;
            }
        }
        board[i][j] = ch;
        return flag;
    }
public:
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int n=board.size(),m=board[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    if(dfs(word,i,j,board))
                        return 1;
                }
            }
        }
        return false;
    }
};
