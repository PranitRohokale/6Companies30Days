class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>map;
        
        for(auto s:strs)
        {
            string t = s;
            sort(t.begin(),t.end());
            map[t].push_back(s);
        }
        vector<vector<string>>ans;
        for(auto m:map)
            ans.push_back(m.second);
        return ans;
    }
};
