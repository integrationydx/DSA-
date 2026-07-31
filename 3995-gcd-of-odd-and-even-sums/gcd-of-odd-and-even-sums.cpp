class Solution {
public:
    int gcdOfOddEvenSums(int n) {
       vector<int>f;
       int i=0;
      while(f.size()!=n)
      {
        if(i%2 == 0)
        {
            f.push_back(i);
        }
        if(f.size() == n) break;
        i++;
      }
     
      vector<int>ans;
      int j = 0;
      while(ans.size()!=n)
      {
        if(j%2!=0)
        {
            ans.push_back(j);
        }
        if(ans.size() == n) break;
        j++;
      }
      int even = 0;
      int odd = 0;
      for(int i=0;i<f.size();i++)
      {
        even+= f[i];
      }
      for(int j=0;j<ans.size();j++)
      {
        odd+= ans[j];
      }
      int a = max(even,odd);
      int maxi = INT_MIN;
      for(int i=1;i<a;i++)
      {
        if(even%i == 0 && odd%i == 0)
        {
            maxi = max(maxi,i);
        }
      }
      if(maxi == INT_MIN) return 1;
      return maxi;


    }
};