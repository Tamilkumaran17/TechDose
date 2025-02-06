#include <bits/stdc++.h>
using namespace std;



bool isOp(char ch)
{
    return (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^' );
}        
        

string post_to_pre(string &pre_exp)
{
   
        
        stack<string> st;
        string in;
        
        for(char ch:pre_exp)
        {
            if(isalnum(ch))
            {
                st.push(string(1,ch));
            }

            else if(isOp(ch))
            {
                string op2= st.top(); st.pop();
                string op1= st.top(); st.pop();

                string ex= ch + op1 + op2;

                st.push(ex);
            }
            
        }
        
        return st.top();
    }



void st()
{
    

    string s;
    cin>>s;
    cout<< post_to_pre(s)<<endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    st();
}