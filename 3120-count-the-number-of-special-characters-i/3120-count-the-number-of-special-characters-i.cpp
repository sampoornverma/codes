class Solution {
public:
    int numberOfSpecialChars(string word) {
    
        vector<int> arr(26,0);
        int n=word.size();
        for(int i=0;i<n;i++){
            if(word[i]-65<=25){
               arr[word[i]-65]=1;
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(word[i]-97>=0 && word[i]-97<= 25 && arr[word[i]-97 ]==1){
                count++;
                arr[word[i]-97 ]=2;
            }
        }
        return count;
    }
};