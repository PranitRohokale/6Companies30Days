//Function to count number of subtrees having sum equal to given sum.
int countSubtreesWithSumXUtil(Node* root,int x,int &count)
{
    if(!root)return INT_MIN;
    
    int ll = countSubtreesWithSumXUtil(root->left,x,count);
    int rr = countSubtreesWithSumXUtil(root->right,x,count);
    int sum = 0;
    if(ll!=INT_MIN )
        sum += ll;
    if(rr!=INT_MIN)
        sum += rr;
    sum += root->data;
    if(sum==x)
        count++;
    return sum;
}
int countSubtreesWithSumX(Node* root, int X)
{
	// Code here
	int count = 0;
	countSubtreesWithSumXUtil(root,X,count);
	return count;
}
