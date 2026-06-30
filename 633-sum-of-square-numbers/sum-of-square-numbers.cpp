class Solution {
public:
    bool judgeSquareSum(int c) {
       int low = 0;
       int high = sqrt(c);
      
       while(low<=high)
       {
        long long x  = 1LL*high*high;
        long long y = 1LL*low*low;
       if(x+ y == c)
       {
        return true;
       }
       else if (x+ y< c)
       {
        low++;
       }
       else{
             high--;
       }

        }
       
return false;
    }
};