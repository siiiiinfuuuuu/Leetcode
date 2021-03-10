class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int count = 0;
        bool first = false;
        for(int i= 0;i<nums.size();i++){
            if(nums[i]==1){
                if(first == false)
                    first = true;
                else{
                    if(count<k)
                        return false;
                    count = 0;
                }
                
            }
            else{
                if(first == false)
                    continue;
                count++;
            }
        }
        return true;
    }
};