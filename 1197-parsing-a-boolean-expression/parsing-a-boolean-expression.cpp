class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for (char ch : expression) {
            if (ch == ',' || ch == '(')
                continue;

            if (ch != ')') {
                st.push(ch);
            } 
            else {
                int t = 0, f = 0;

                while (st.top() != '!' && st.top() != '&' && st.top() != '|') {
                    if (st.top() == 't')
                        t++;
                    else
                        f++;
                    st.pop();
                }

                char op = st.top();
                st.pop();

                if (op == '!') {
                    if (t)
                        st.push('f');
                    else
                        st.push('t');
                }
                else if (op == '&') {
                    if (f)
                        st.push('f');
                    else
                        st.push('t');
                }
                else { 
                    if (t)
                        st.push('t');
                    else
                        st.push('f');
                }
            }
        }

        return st.top() == 't';
    }
};