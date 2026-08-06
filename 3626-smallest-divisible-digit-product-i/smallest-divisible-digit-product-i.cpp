class Solution {
public:
vector<int>f;
bool fun(int n,int t)
{
  while(n>0)
  {
     f.push_back(n%10);
     n = n/10;
  }
  int prod = 1;
  for(int i=0;i<f.size();i++)
  {
     prod*=f[i];
    }
  
  if(prod%t == 0) return true;
  return false;
}
    int smallestNumber(int n, int t) {
        for(int i = n;i<INT_MAX;i++)
        {
            f.clear();
            if(fun(i,t)) return i;
        }
        return -1;
    }
};