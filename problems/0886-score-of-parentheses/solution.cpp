class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for (int i=0;i<s.size();i++){
            if (s[i]=='('){
                st.push(0);
            }else{
                int top=st.top();
                st.pop();
                if (top==0){
                    int temp=st.top()+1;
                    st.pop();
                    st.push(temp);
                }else{
                    int temp=2*top+st.top();
                    st.pop();
                    st.push(temp);
                }
            }
        }
        return st.top();
    }
};
