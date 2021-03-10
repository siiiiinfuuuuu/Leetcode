class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i = nums.size()-1; i > 0; i--){
            if(nums[i] > nums[i-1]){
                int tmp = nums[i];
                nums[i] = nums[i-1];
                nums[i-1] = tmp;
                sort(nums.begin()+i, nums.end());
                return;
            }
        }
        sort(nums.begin(),nums.end());
    }
};