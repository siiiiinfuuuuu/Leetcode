class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = nums.size();
        if(l==0||l==1){
            return l;
        }
        int j = 1;
        int temp = nums[0];
        for(int i = 1; i < l; i++){
            if(nums[i] != temp){
                nums[j++] = nums[i];
                temp = nums[i];
            }
        }
        return j;
    }
};