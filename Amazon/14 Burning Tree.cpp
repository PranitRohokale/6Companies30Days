
// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  int ans = 0;
    // pair<int,bool> gettime(Node* root,int target)
    Node* tar = NULL;
    unordered_map<Node*,Node*>map;
    void dfs(Node* root,Node* parent,int target)
    {
        if(!root)return;
        if(root->data==target)
        {
            tar = root;
        }
        map[root] = parent;
        dfs(root->left,root,target);
        dfs(root->right,root,target);
    }
    // {
    //     if(root==NULL)return {0,false};
    //     if(root->data == target)
    //         return {1,true};
            
    //     pair<int,bool> ls = gettime(root->left,target);
    //     pair<int,bool> rs = gettime(root->right,target);
        
    //     if(ls.second==true)
    //     {
    //         ans = max(ans,rs.first + ls.first);
    //         return {ls.first+1,true};
    //     }
    //     else if(rs.second==true)
    //     {
    //         ans = max(ans,rs.first + ls.first);
    //         return {rs.first+1,true};
    //     }
        
    //     return { max(ls.first,rs.first)+1,ls.second && rs.second };
        
    // }
    public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        // pair<int,bool> temp = gettime(root,target);
        Node* parent = NULL;
        dfs(root,parent,target);
        int rtime = 0;
        queue<Node*>q;
        unordered_set<Node*>vis;
        q.push(tar);
        vis.insert(tar);
        
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                Node* temp  = q.front();q.pop();
                if(temp->left && vis.count(temp->left)==0)
                {
                    vis.insert(temp->left);
                    q.push(temp->left);
                }
                if(temp->right && vis.count(temp->right)==0)
                {
                    vis.insert(temp->right);
                    q.push(temp->right);
                }
                if(map.find(temp)!=map.end() && vis.count(map[temp])==0 && map[temp]!=NULL)
                {
                    vis.insert(map[temp]);
                    q.push(map[temp]);
                }
                
            }
            rtime++;
        }
        return rtime-1;

    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends
