class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
    double i=poured;
    double j=(double)1;
    double total=(double)0;
    double count=(double)0;
    while(poured--){
        total= total + 1/j;
        if(total>=1){
            total=total-1;
            j++;
        }
       count++;
        
    }
    if(query_row>count-1 || query_glass>query_row){
        return 0.00000;
    }
    if(query_row<count-1 )return 1.00000;
    return total;
    }
};