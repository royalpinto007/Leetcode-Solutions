class Solution {
public:
    int calculate(string s) {
        stack<int> opds;
        stack<int> signs;
        
        int opd = 0;
        int res = 0;
        int sign = 1;
        
        for(char c : s){
            if(c >= '0' && c <= '9'){
                opd = opd * 10 + (c-'0');
            }else if(c == '+'){
                // cout << res << " + " << sign << " * " << opd << endl;
                res += sign * opd;
                opd = 0;
                sign = 1;
            }else if(c == '-'){
                // cout << res << " + " << sign << " * " << opd << endl;
                // res "+" sign * opd here !!!
                res += sign * opd;
                opd = 0;
                sign = -1;
            }else if(c == '('){
                /*
                current res and sign is later used when we meet ')'
                */
                opds.push(res);
                signs.push(sign);
                // cout << "push " << res << " and " << sign << endl;
                // cout << "opd: " << opd << endl;
                
                /*
                reset operand and result, 
                as if new evaluation begins for the new sub-expression
                */
                // opd = 0; //opd is already reset when we meet '+' or '-' before the '('
                res = 0; //since res is already pushed into stack
                sign = 1; //since sign is already pushed into stack
            }else if(c == ')'){
                // cout << res << " + " << sign << " * " << opd << endl;
                res += sign * opd;
                res *= signs.top(); signs.pop();
                res += opds.top(); opds.pop();
                // cout << "res: " << res << ", sign: " << sign << endl;
                opd = 0; //already used
                /*
                after ')', we must meet '+' or '-', 
                and sign*opd is always 0, so res won't change
                
                and we known that after '+' or '-', 
                opd and sign will be reset again,
                so here we don't need to reset sign
                */
                // sign = 1; 
            }
        }
        
        // cout << res << " + " << sign << " * " << opd << endl;
        return res + sign * opd;
    }
};
