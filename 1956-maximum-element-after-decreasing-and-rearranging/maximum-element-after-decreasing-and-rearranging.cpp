class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
       arr[0] = 1;
       vector<int>f;
      for(int i =1;i<n;i++)
      {
        if(arr[i]-arr[i-1]<=0)
        {
            continue;
        }
        else{  
           arr[i] = arr[i-1] +1;
          
        }
        
      }
      return *max_element(arr.begin(),arr.end());








        return *max_element(f.begin(),f.end());  
    }
};