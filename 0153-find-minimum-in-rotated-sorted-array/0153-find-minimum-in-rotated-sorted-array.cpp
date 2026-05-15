class Solution {
public:
    int findMin(vector<int>& arr) {
        bool n= false;
        int low=0;
        int min= 10000;
        int high=arr.size()-1;
        while(low<=high){
            int mid= low+(high-low)/2;
            
            if(arr[low]<=arr[mid]){
                if(arr[low]<=arr[high]){
                    if(arr[low]<min){
                        min=arr[low];
                        }
                    high=mid-1;
                }else{
                    if(arr[mid]<min)min=arr[mid];
                    low=mid+1;
                }
            }
            else{
               if(arr[mid]<min)min=arr[mid];
               high=mid-1;     
            }
        }
        return min;
    }
};