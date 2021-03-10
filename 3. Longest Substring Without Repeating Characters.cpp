class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int n = s.length();
        int i = 0, j = 0;
        int index_i,index_j;
        bool table[256] = {0};
        while(i < n && j < n){
            index_j = s[j]-'\0';
            if(table[index_j]){
                if(j-i > ans)
                    ans = j-i;
                while(s[i]!=s[j]){
                    index_i = s[i]-'\0';
                    table[index_i] = 0;
                    i++;
                }
                i++;
                j++;
            }
            else{
                table[index_j] = 1;
                j++;
            }
        }
        if(j-i > ans)
            ans = j-i;
        return ans;
    }
};