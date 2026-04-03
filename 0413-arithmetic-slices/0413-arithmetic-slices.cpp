class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<=2)return 0;
    int count=0;
    int mini=1;
    int diff=nums[1]-nums[0];
    vector<pair<int,int>> v;
    int n=nums.size();
    for(int i=1;i<n;i++){
        if(diff==nums[i]-nums[i-1]  ){
            mini++;
        }else{
            v.push_back({diff,mini});
            diff=nums[i]-nums[i-1];
            mini=2;
        }
    }
    v.push_back({diff,mini});
    for(int i = 0; i < v.size(); i++){

            int L = v[i].second;

            if(L >= 3)
                count += (L-1)*(L-2)/2;
        }
    return count;
    }
};