vector<int> spirallyTraverse(vector<vector<int> > m, int r, int c) 
    {
        // code here
        int top=0,bottom=r-1,left=0,right=c-1;
        int n = ceil(r/2);
        int gap = 0;
        
        while(top<=bottom && left<=right)
        {
            for(int j=left;j<=right;j++)
                cout<<m[top][j]<< " ";
                top++;
                if(top>bottom)break;
                
            for(int i=top;i<=bottom;i++)
                cout<<m[i][right]<<" ";
                right--;
                if(right<left)break;
                
            for(int j=right;j>=left;j--)
                cout<<m[bottom][j]<<" ";
                bottom--;
                if(bottom<top)break;
                
            for(int i=bottom;i>=top;i--)
                cout<<m[i][left]<<" ";
                left++;
                if(left>right)break;
        }
        vector<int>v;
        return v;
    }

