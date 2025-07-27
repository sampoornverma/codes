class Solution {
public:
    int maximumScore(int a, int b, int c) {
       priority_queue<int>  p;
       p.push(a);
       p.push(b);p.push(c);
       int count=0;
       while(p.size()>1){
       int x=p.top();
       p.pop();
       int d=p.top();
       p.pop();
       count++;
       x--,d--;
       if(x != 0)p.push(x);
       if(d != 0)p.push(d);
       }
       return count;
    }
};