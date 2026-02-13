class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
         vector<int> arr(baskets.size(),0);
     int count=0;
     for(int i=0;i<fruits.size();i++){
        for(int j=0;j<baskets.size();j++){
            if(fruits[i]<=baskets[j] && arr[j]!=1){
                arr[j]=1;
                break;
            }
            if(j==baskets.size()-1 && (baskets[baskets.size()-1]<fruits[i] || arr[baskets.size()-1]==1)){
                count++;
            }
        }
     }
     return count;       
    }
};