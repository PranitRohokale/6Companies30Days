

class node{
    bool flag;
    node *arr[26];

    public:
        node(){
            flag = false;
        }
        bool isEnd()
        {
            return flag;
        }
        bool containsKey(char ch)
        {
            return arr[ch-'a']!=NULL;
        }
        node* get(char ch)
        {
            return arr[ch-'a'];
        }
        void setEnd()
        {
            flag = true;
        }
        void put(char ch,node *temp)
        {
            arr[ch-'a'] = temp;
        }
};


class Solution{
    void insert(string str,node *root)
    {
        node *temp = root;
        for(int i=0;i<str.size();i++)
        {
            if(!temp->containsKey(str[i]))
                temp->put(str[i],new node());
            temp = temp->get(str[i]);
        }
        temp->setEnd();
    }
    void displayContactsUtil(node* temp,string contact,vector<string>&matchContact)
    {
        if(temp==NULL)return;
        else if(temp->isEnd())
        {
            matchContact.push_back(contact);
            return;
        }else{
            for(char ch='a';ch<='z';ch++)
                if(temp->containsKey(ch))
                    displayContactsUtil(temp->get(ch),contact+ch,matchContact);
        }
    }
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        int possiblePrefix = s.size();
        vector<vector<string>>ans;
        
        node *trie = new node();
        for(int i=0;i<n;i++)
            insert(contact[i],trie);
        
        
        string prefix = "";
        node *prevnode = trie;
        for(int i=0;i<possiblePrefix;i++)
        {
            prefix+=s[i];
            if(prevnode==NULL){
                ans.push_back({"0"});
                continue;
            }
            
            node* currnode = prevnode->get(s[i]);
            
            vector<string>matchContact;
            displayContactsUtil(currnode, prefix,matchContact);
            
            if(matchContact.size())
                ans.push_back(matchContact);
            else
                ans.push_back({"0"});
            
            prevnode = currnode;
        }
        
        return ans;
    }
    
};

