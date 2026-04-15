class Solution {
public:
    int closestTarget(vector<string>& words, string target, int s) {
      int n=words.size();
      int i= -1;
      for(int j=0;j<n;j++){
        if(words[(s+j)%n]==target){
            i=j;
            break;
        }
      }
      for(int j=0;j<n;j++){
        if(words[abs(s-j+n)%n]==target){
            i=min(i,j);
            
        }
      }

      return i;  
    }
};