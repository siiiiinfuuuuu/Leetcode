class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> numsMap;
        int ans = 0;
        for(int i = 0; i< nums.size();i++)
            numsMap[nums[i]]++;
        
        int last_count = 0;
        int last = (*numsMap.begin()).first;
        
        for(auto it = numsMap.begin();it!=numsMap.end();it++){
            if(((*it).first - last == 1)&& last_count + (*it).second > ans)
                ans = last_count + (*it).second;
            last = (*it).first;
            last_count = (*it).second;
        }
        return ans;
            
    }
};