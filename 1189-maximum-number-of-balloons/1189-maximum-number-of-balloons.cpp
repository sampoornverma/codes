class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> arr(26,0);
        for(char c:text){
            if(c =='a'){
                arr[c-'a']++;
            }
            else if(c== 'b'){
                arr[c-'a']++;
            }
            else if(c=='l'){
                arr[c-'a']++;
            }
            else if(c=='o'){
                arr[c-'a']++;
            }else if(c== 'n'){
                arr[c-'a']++;
            }
        }
        int mini=1e4;
        string g= "balon";
        int y=0;
        for(char x:g){
            if(x=='o' || x=='l'){
                y=arr[x-'a']/2;
            }else{
                y=arr[x-'a'];
            }
            mini=min(mini,y);
        } 
        return mini;   
    }
};