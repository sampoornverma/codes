class Solution {
public:
    
    int digits(int x){
        int cnt=0;
        while(x){
            cnt++;
            x/=10;
        }
        return cnt;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        unordered_set<int> st;

        // store prefixes of arr1
        for(int x:arr1){

            while(x>0){
                st.insert(x);
                x/=10;
            }
        }

        int ans=0;

        // check prefixes in arr2
        for(int x:arr2){

            while(x>0){

                if(st.find(x)!=st.end()){

                    ans=max(ans,digits(x));
                    break;
                }

                x/=10;
            }
        }

        return ans;
    }
};