class Solution {
public:
vector<int>f;
void fun(int n)
{
vector<int>g;
  while(n>0)
  {
    if(n%2 == 1) g.push_back(1);
    else{
        g.push_back(0);
    }
    n = n/2;

  }
  int count = 0;
  for(int i=0;i<g.size();i++)
  {
    if(g[i] == 1) count++;
  }
  
  f.push_back(count);
  g.clear();
}

    vector<int> countBits(int n) {
        for(int i=0;i<=n;i++)
        {
           fun(i);
        }
         
     return f;

    }
};