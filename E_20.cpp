/*
20. Valid Parentheses
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/
//Runtime: 8 ms, faster than 19.20% of C++ online submissions for Valid Parentheses.
//Memory Usage: 6.2 MB, less than 100.00% of C++ online submissions for Valid Parentheses.
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int l = s.size();
        char pair;
        for (int i = 0; i < l; i++){
            if(s[i] == ')') pair = '(';
            else if (s[i] == '}') pair = '{';
            else if (s[i] == ']') pair = '[';
            else {
                st.push(s[i]);
                continue;
            }
            
            if(!st.empty() && st.top() == pair){
                st.pop();
            }
            else st.push(s[i]);
        }
        return st.empty();
    }
};


//perfect solution 
//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
//Memory Usage: 6.5 MB, less than 100.00% of C++ online submissions for Valid Parentheses.
class Solution {
public:
    bool isValid(string s)
    {
        int n = s.size();
        
        if(n == 0)
            return true;
        
        stack<char> check;
        
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                check.push(s[i]);
            
            else
            {
                if(!check.empty())
                {
                    char ch = check.top();
                    check.pop();
                    
                    if(ch == '(' && s[i] != ')')
                        return false;
                    
                    if(ch == '{' && s[i] != '}')
                        return false;
                    
                    if(ch == '[' && s[i] != ']')
                        return false;
                }
                
                else
                    return false;
            }
        }
        
        if(!check.empty())
            return false;
        
        return true;
    }
};
