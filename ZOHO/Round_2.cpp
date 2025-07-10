#include <iostream>
#include <bits/stdc++.h>
using namespace std;



int main() {
    // Write C++ code here
    // std::cout << "Try programiz.pro";
    
    


     #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

/////// second largest number
    
    
    //    int n;
    //    cin>>n;
    //    vector<int> arr(n);

    //    for(int &i:arr)
    //    cin>>i;

    //    int maxx=INT_MIN, second=INT_MIN;

    //    if(n==0 || n==1)
    //    {
    //     cout<<-1;
    //     return 0;
    //    }

    //    function<void(vector<int>)> solve = [&](vector<int>& arr)
    //    {

    //         for(int i:arr)
    //         {
    //             if(maxx < i)
    //             {
    //                 second = maxx;
    //                 maxx=i;
    //             }
    //             else if( second < i && i!=maxx)
    //             second = i;
    //         }
    //    };

    //    solve(arr);

    //    cout<<second;



    // third largest number in array


    //    int n;
    //    cin>>n;
    //    vector<int> arr(n);

    //    for(int &i:arr)
    //    cin>>i;

    //    int maxx=INT_MIN, second=INT_MIN,third=INT_MIN;

    //    if(n<=3)
    //    {
    //     cout<<-1;
    //     return 0;
    //    }

    //    for(int i : arr)
    //    {
    //         if(maxx < i)
    //         {
    //             third = second;
    //             second = maxx;
    //             maxx = i;
    //         }
    //         else if(i < maxx && i > second)
    //         {
    //             third = second;
    //             second = i;
    //         }
    //         else if(i < second && i > third)
    //         {
    //             third = i;
    //         }
    //    }

    //    cout<<third;



    // pallintrome or not


    // string s;
    // getline(cin,s);

    // int l=0,r=s.size()-1;

    // int flag=0;

    // while( l<r)
    // {
    //     if(!isalpha(s[l]))
    //     l++;

    //     else if(!isalpha(s[r]))
    //     r--;

    //     else if(s[l] != s[r])
    //     {
    //         cout<<"false";
    //         break;
    //         flag=1;
    //     }
    //     else 
    //     {
    //         l++;
    //         r--;
    //     }
    // }

    // if(flag==0)
    // cout<<"true";




    // first non repeating characters


    // string s;
    // cin>>s;

    // vector<int> mp(26,0);
    // queue<char> q;

    // for(char ch: s)
    // {
    //     mp[ch-'a']++;

    //     q.push(ch);

    //     while(!q.empty() && mp[q.front() - 'a'] > 1 )
    //     q.pop();
    // }

    // cout << (q.empty() ? '#' : (char)(q.front()));


////////  longest substring without repeating characters


    // string s;
    // cin>>s;

    // int n=s.size();
    // int left=0,maxx=0;
    // int stidx=0;
    // unordered_map<char,int> mp;

    // for(int right=0;right<n;right++)
    // {

    //     // if(!isalpha(s[right]))
    //     // {
    //     //     mp.clear();
    //     //     left=right+1;
    //     //     continue;
    //     // }


    //     if(mp.find(s[right]) != mp.end() && mp[s[right]] >= left)
    //     left=  mp[s[right]] + 1;

    //     mp[s[right]]=right;

    //     if(maxx < right - left + 1)
    //     {
    //         maxx= right-left+1;
    //         stidx=left;

    //     }
    // }
    // cout<<" Longest length of Substring Without Repeating Characters is : "<<s.substr(stidx , maxx) << " with size " << maxx ;




    
    

    // // Online C++ compiler to run C++ program online
// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     // Write C++ code here
//     // std::cout << "Try programiz.pro";
    
//     // int n,c;
//     // cin>>n;
//     // c=0;
    
//     // queue<string> q;
//     // q.push("3");
//     // q.push("4");
    
//     // vector<string> ans;
    
//     // while(!q.empty())
//     // {
//     //     string ch = q.front();
//     //     q.pop();
        
//     //     c++;
//     //     cout<<ch<<" ";
//     //     if(n==c)
//     //     {
//     //         cout<<"\n count " << ch;
//     //         return 0;
//     //     }
        
        
//     //     q.push(ch+"3");
//     //     q.push(ch+"4");
//     // }


    
//     string s;
//     cin>>s;
    
//     stack<char> st;
//     char prev=0;
    
//     auto is_operand = [&](char ch)->bool{
//         return isalpha(ch);
//     };
    
//     auto is_operator = [&](char ch)->bool{
//         return (ch=='+' || ch=='-' || ch=='*' || ch=='/');
//     };
    
//     auto solve = [&]()->bool{
//         for(int i=0;i<s.size();i++)
//             {
//                 char ch=s[i];
                
//                 if(ch=='(')
//                 st.push(ch);
//                 else if(ch==')'){
//                     if(st.empty())
//                     return false;
                    
//                     st.pop();
//                 }
                
//                 if(is_operator(ch))
//                 {
//                     if(i==0 || i==s.size()-1)
//                     return false;
                    
//                     if(is_operator(prev))
//                     return false;
                    
//                     if(prev=='(')
//                     return false;

//                 }
                
//                 if( ch== ')' && is_operator(prev))
//                 return false;
                
//                 if(is_operator(ch) && prev=='(')
//                 return false;
                
//                 if(is_operand(ch) && prev==')')
//                 return false;
                
//                 prev=ch;
//             }
//             return st.empty();
//     };
    
    
//     if(solve())
//     cout<<"true valid";
//     else
//     cout<<"no";
//     return 0;
// }




// Check for subsequence

    string a,b;
    cin>>a>>b;

    int i=0,j=0;

    while( i<a.size() && j<b.size())
    {
        if(a[i]==b[j])
        i++;

        j++;
    }

    if(a.size()==i)
    {
        cout<<"True";
        return 0;
    }

    cout<<"false";





    return 0;
}