class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int low = 0;
       int rows = matrix.size();
       int columns = matrix[0].size();
       int high = rows*columns - 1;

       while(low<=high)
       {
        int mid = low + (high-low)/2;
         int row = mid / matrix[0].size();
        int cols = mid % matrix[0].size();

        if(matrix[row][cols] == target)
        {
            return true;
        }
        else if (matrix[row][cols] < target){ 
             low = mid +1;
        }
        else{
            high = mid - 1;
        }
       }
       return false;
    }
};