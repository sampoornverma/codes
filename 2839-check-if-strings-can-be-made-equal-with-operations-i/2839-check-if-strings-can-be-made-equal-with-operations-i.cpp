class Solution {
public:
    bool canBeEqual(string s1, string s2) {


        string eve1="";
        string eve2="";
        string odd1="";
        string odd2="";
        int n=s1.size();
        int i=0;
        while(i<n){
            eve1=eve1+s1[i];
            eve2=eve2+s2[i];
            i+=2;
        }
        i=1;
        while(i<n){
            odd1=odd1+s1[i];
            odd2=odd2+s2[i];
            i+=2;
        }
        sort(eve1.begin(),eve1.end());
        sort(eve2.begin(),eve2.end());
        sort(odd1.begin(),odd1.end());
        sort(odd2.begin(),odd2.end());
        if(eve1==eve2 && odd1==odd2){
            return true;
        }
        return false;
    }
};