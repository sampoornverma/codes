#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int hcf(int a, int b) {
        return b == 0 ? a : hcf(b, a % b);
    }

    long long lcm(long long a, long long b) {
        return (a / hcf(a, b)) * b; 
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<long long> st;

        for (int x : nums) {
            st.push(x);

            while (st.size() > 1) {
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();

                long long g = hcf(a, b);
                if (g == 1) {  
                    st.push(a);
                    st.push(b);
                    break;
                }
                else {
                    st.push(lcm(a, b));
                }
            }
        }

        vector<int> result(st.size());
        for (int i = (int)st.size() - 1; i >= 0; --i) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};
