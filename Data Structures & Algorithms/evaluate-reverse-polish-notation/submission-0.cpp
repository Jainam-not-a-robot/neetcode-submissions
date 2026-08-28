class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> s = {"+", "-", "*", "/"};
        stack<int> st;
        for (string x : tokens) {
            if (s.find(x) == s.end()) st.push(stoi(x));
            else {
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                if (x == "+") st.push(op1 + op2);
                else if (x == "-") st.push(op1 - op2);
                else if (x == "*") st.push(op1 * op2);
                else st.push(op1/op2);
            }
        }
        return st.top();
    }
};
