/*
150. Evaluate Reverse Polish Notation
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Note:

Division between two integers should truncate toward zero.
The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.
Example 1:

Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/

//Runtime: 32 ms, faster than 14.44% of C++ online submissions for Evaluate Reverse Polish Notation.
//Memory Usage: 12.1 MB, less than 5.26% of C++ online submissions for Evaluate Reverse Polish Notation.
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int s = tokens.size();
        for (int i = 0; i < s; i++){ 
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] !="*" && tokens[i] !="/") {
                stringstream ss;
                int token;
                ss << tokens[i];
                ss >> token;
                st.push(token);
            }
            else{
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                if (tokens[i] == "+"){
                    st.push(first+second);
                }
                else if (tokens[i] == "-"){
                    st.push(first-second);
                }
                else if (tokens[i] == "*"){
                    st.push(first*second);
                }
                else{
                    st.push(first/second);
                }
            }
        }
        return st.top();
    }
};


//same speed, but looks nicer
//stoi(it) : It is used to convert string to integer. stoi stands for string to int.
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int ans;
        for(auto it:tokens) {
            if(it=="+"||it=="-"||it=="*"||it=="/") {
                int num1=st.top();  st.pop();
                int num2=st.top();  st.pop();
                if(it=="+")        ans=num2+num1;
                else if(it=="-")   ans=num2-num1;
                else if(it=="*")   ans=num2*num1;
                else               ans=num2/num1;
                st.push(ans);
            }
            else  st.push(stoi(it));
        }
        return st.top();
    }
};
