class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& a) {
        int n=s.size(),z=count(s.begin(),s.end(),'0');
        vector<int> p;
        for(int i=0;i<n;i++) if(s[i]=='0') p.push_back(i);
        vector<bool> ans;
        for(string t:a){
            int q=count(t.begin(),t.end(),'?');
            int c=count(t.begin(),t.end(),'0');
            if(c>z||c+q<z){ans.push_back(false);continue;}
            int need=z-c;
            for(char &x:t) if(x=='?'){
                if(need)x='0',need--;
                else x='1';
            }
            vector<int> v;
            for(int i=0;i<n;i++) if(t[i]=='0') v.push_back(i);
            bool ok=true;
            for(int i=0;i<z;i++)
                if(p[i]<v[i]) ok=false;
            ans.push_back(ok);
        }
        return ans;
    }
};