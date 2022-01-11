
void rotate(vector<vector<int> >& matrix)
{
    // Your code goes here
    int n = matrix.size();
    
    for(int i=0;i<n;i++)
        reverse(matrix[i].begin(),matrix[i].end());
        
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        swap(matrix[i][j],matrix[j][i]);
    }
    
    //for clockwise 
        // 1. take transpose & then do reverse each row
    
    // for anticlockwise
        // 1. first reverse each row & then take transpose
    
    //intutiion
        // for every row is get replaced with the corresponding coloum thus
        // i used transform matrix bcoz in transformation also row & col get swapped
    
}
