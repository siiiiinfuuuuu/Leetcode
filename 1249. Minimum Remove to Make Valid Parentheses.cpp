class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(')
                count++;
            if(s[i] == ')')
                if(count > 0)
                    count--;
                else
                    s.erase(s.begin()+i--);
        }
        count = 0;
        for(int i = s.size() - 1 ; i >= 0; i--){
            if(s[i] == ')')
                count++;
            if(s[i] == '(')
                if(count > 0)
                    count--;
                else
                    s.erase(s.begin()+i);
        }
        return s;
    }
};