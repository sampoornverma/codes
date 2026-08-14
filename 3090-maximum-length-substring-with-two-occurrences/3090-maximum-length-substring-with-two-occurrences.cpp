class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.length();
        vector<int> arr(26,0);
        int i=0;
        int j=0;
        int maxi=0;
        while(j<n){
            arr[s[j]-'a']++;
            while(arr[s[j]-'a']>2){
                arr[s[i]-'a']--;
                i++;
            }
            
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};