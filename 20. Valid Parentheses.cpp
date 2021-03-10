class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;
        int stringLength = s.length();
        for(int i = 0; i < stringLength; i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                myStack.push(s[i]);
            }
            else{
                if(myStack.empty())
                    return false;
                char temp = myStack.top();
                myStack.pop();
                if(s[i] == ')'){
                    if(temp!='(')
                        return false;
                }
                if(s[i] == ']'){
                    if(temp!='[')
                        return false;
                }
                if(s[i] == '}'){
                    if(temp!='{')
                        return false;
                }
            }
        }
        if(!myStack.empty())
            return false;
        return true;
    }
};