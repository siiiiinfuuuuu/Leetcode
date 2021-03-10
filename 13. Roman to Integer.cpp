class Solution {
public:
    int char2int(char c){
        if(c == 'I')
            return 1;
        else if(c == 'V')
            return 5;
        else if(c == 'X')
            return 10;
        else if(c == 'L')
            return 50;
        else if(c == 'C')
            return 100;
        else if(c == 'D')
            return 500;
        else if(c == 'M')
            return 1000;
        else
            return 0;
    }
    int romanToInt(string s) {
        int ans = 0;
        s+='@';
        for(int i = 0; i < s.size() -1 ; i++){
            if(char2int(s[i]) < char2int(s[i+1])){
                ans+= char2int(s[i+1]) - char2int(s[i]);
                i++;
            }
            else
                ans+=char2int(s[i]);
        }
        return ans;
    }
};