class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
    map<int,int> mp;
    vector<int> arr;
    for(int i=0;i<bulbs.size();i++){
        mp[bulbs[i]]++;
    }
    int count=0;
    for(auto &a:mp){
        if(a.second%2==1)arr.push_back(a.first);
    }
    return arr;
     
    }
};