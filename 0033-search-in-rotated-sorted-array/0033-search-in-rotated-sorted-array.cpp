class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n= -1;
        int low=0;
        int high=arr.size()-1;
        while(low<=high){
            int mid= low+(high-low)/2;
            if(arr[mid]== target){
                return mid;
            }
            if(arr[low]<=arr[mid]){
                if(arr[mid]>target && target>=arr[low]){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }
            else{
                if(arr[high]>=target && target > arr[mid]){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
        }
        return n;
    }
};