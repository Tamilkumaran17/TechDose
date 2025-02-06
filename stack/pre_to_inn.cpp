#include <bits/stdc++.h>
using namespace std;



bool isOp(char ch)
{
    return (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^' );
}        
        

string pre_to_inn(string &pre_exp)
{
   
        
        stack<string> st;
        string in;
        
        for(int i=pre_exp.size()-1;i>=0;i--)
        {
            char ch=pre_exp[i];
            
            if(isalnum(ch))
            {
                string op(1,ch);
                st.push(op);
            }
            else if(isOp(ch))
            {
                string op1= st.top();
                st.pop();
                
                string op2= st.top();
                st.pop();
                
                string ex= '(' + op1 + ch + op2 + ')';
                st.push(ex);
            }
            
        }
        
        return st.top();
    }



void st()
{
    

    string s;
    cin>>s;
    cout<< pre_to_inn(s)<<endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    st();
}