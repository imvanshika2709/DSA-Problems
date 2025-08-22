#include <bits/stdc++.h>
using namespace std;

// "()[{}()]"

bool balancedparantheses(string &str){
    stack<char> st;

    for(auto it: str){
        if(it=='(' || it=='{' || it=='[') st.push(it);
        else{
            if(st.empty()) return false;
            char ch=st.top();
            st.pop();

            if((ch=='(' and it==')') or (ch=='{' and it=='}') or (ch=='[' and it==']')) continue;
            else return false;
        }

    }
    return st.empty();
}

int main() {

    string str1="()[{}()]";
    bool ans=balancedparantheses(str1);
    cout<<ans;
    
    return 0;
}