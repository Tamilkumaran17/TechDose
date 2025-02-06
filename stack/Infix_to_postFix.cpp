#include <bits/stdc++.h>
using namespace std;


int precedence(char ch)
{
    if(ch=='+' || ch=='-')
    return 1;
    else if(ch=='*' || ch=='/')
    return 2;
    else if(ch=='^')
    return 3;
        
    return 0;
}
    
bool isOp(char ch)
{
    return (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^' );
}        
        

string infix_to_postfix(string &s)
{
    stack<char> st;
        string post;
        
        for(char ch:s)
        {
            if(isalnum(ch))
            post+=ch;
            
            else if(ch=='(')
            st.push(ch);
            
            else if(ch==')')
            {
                while(!st.empty() && st.top()!='(')
                {
                    post+=st.top();
                    st.pop();
                }
                st.pop();
            }
            
            else if(isOp(ch))
            {
                while(!st.empty() && precedence(ch) <= precedence(st.top()))
                
                {
                    post+=st.top();
                    st.pop();
                }
                st.push(ch);
            }
            
            
        }
        
        while(!st.empty())
        {
            post+=st.top();
            st.pop();
            
        }
        return post;

}

void st()
{
    

    string s;
    cin>>s;
    cout<<infix_to_postfix(s)<<endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    st();
}