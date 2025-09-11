class Solution {
public:
    string sortVowels(string s) {
    vector<char> c1;
    for(char c: s){
        if(c=='a' || c=='e'|| c=='i' || c=='o' ||c=='u' ||c=='A' || c=='E' || c=='I' || c=='O' || c=='U'  ){
            c1.push_back(c);
        }
    }
    sort(c1.begin(),c1.end());
    string r="";
    long long i=0;
    for(char c:s){
    if(c=='a' || c=='e'|| c=='i' || c=='o' ||c=='u' ||c=='A' || c=='E' || c=='I' || c=='O' || c=='U'  ){
            r=r+c1[i];
            i++;
        }
        else{
            r=r+c;
        }    
    }
    return r;   
    }
};