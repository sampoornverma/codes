class Solution {
public:
    bool check(unordered_map<char,int> mp){
    int value = mp.begin()->second;

    for (auto &p : mp) {
        if (p.second != value)
            return false;
    }
    return true; 
    

    }
    int longestBalanced(string s) {
    if(s.size()==1)return 1;
    int count=0;
    
    for(int i=0;i<s.size();i++){
        unordered_map<char,int> mp;
        for(int j=i;j<s.size();j++){
        mp[s[j]]++;
        if(check(mp)){
            count=max(count,j-i+1);
        }
        }
    }
    return count;

    }
};