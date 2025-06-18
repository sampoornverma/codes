class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        
        int low=0;
        int high=arr.size()-1;
        int h=high;
        int l=low;
        if (arr.size() == 1) return 0;
        while(low<=high){
            if((l+1 <= h && arr[l]>arr[l+1])  ){
                return l;
            }
            if(h-1>=l && arr[h]>arr[h-1]){
                return h;
            }
            int mid= low+(high-low)/2;
           if (mid > 0 && mid < arr.size() - 1 && arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]) {
                return mid;
            }
            else{
                if(mid+1<=h && arr[mid]<arr[mid+1] ){
                    low=mid+1;
                }else{
                    high= mid-1;
                }
            }
        }
        return -1;
    
    }
};