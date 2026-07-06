class NumArray {
public:
    vector<int> f;
    vector<int> prefix;

    NumArray(vector<int>& nums) {

       
        for (int i = 0; i < nums.size(); i++) {
            f.push_back(nums[i]);
        }

        
        prefix.resize(f.size());

       
        prefix[0] = f[0];

        for (int i = 1; i < f.size(); i++) {
            prefix[i] = prefix[i - 1] + f[i];
        }
    }

    int sumRange(int left, int right) {

        if (left == 0)
            return prefix[right];

        return prefix[right] - prefix[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */