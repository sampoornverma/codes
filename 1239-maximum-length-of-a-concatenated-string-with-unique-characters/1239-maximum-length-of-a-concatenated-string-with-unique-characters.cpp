class Solution {
public:
    
    bool is_unique(string& str)
    {
        vector<int> mp(26,0);
        
        for(char c : str)
        {
            mp[c-'a']++;
            if(mp[c-'a'] > 1)
                return false;
        }
        
        return true;
    }

    unordered_map<string,int> mp;

    int f(vector<string>& arr, int i, int n, string curr)
    {
        if(!is_unique(curr))
            return 0;

        if(mp.find(curr) != mp.end())
            return mp[curr];

        if(i == n)
            return curr.length();

        int exclude = f(arr, i+1, n, curr);

        int include = f(arr, i+1, n, curr + arr[i]);

        return mp[curr] = max(include, exclude);
    }
    
    int maxLength(vector<string>& arr) 
    {
        int n = arr.size();
        return f(arr, 0, n, "");
    }
};