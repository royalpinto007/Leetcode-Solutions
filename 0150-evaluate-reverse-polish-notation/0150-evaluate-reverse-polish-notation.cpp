class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<long> st;
        unordered_set<string> op = {"+", "-", "*", "/"};
        long op1, op2;

        for (auto str: t){
            if(op.find(str) == op.end()) //If not operator then a number
                st.push(stoi(str));
            else{ //Operator pop two operand and apply operation and push to stack
                 op2 = st.top(), st.pop();
                 op1 = st.top(), st.pop();

                if (str == "+")  op2 = op1+op2;
                else if(str == "-") op2 = op1-op2;
                else if(str == "*") op2 = op1*op2;
                else if(str == "/") op2 = op1/op2;
                st.push(op2);
            }
        }

        return st.top();        
    }
};