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

    // string a,b;
    // cin>>a>>b;

    // int i=0,j=0;

    // while( i<a.size() && j<b.size())
    // {
    //     if(a[i]==b[j])
    //     i++;

    //     j++;
    // }

    // if(a.size()==i)
    // {
    //     cout<<"True";
    //     return 0;
    // }

    // cout<<"false";





    // first occurence in two string;

    // string s1="ZOHOCORPORATION", s2="PORT";

    // int n=s2.size(), minn=INT_MAX, maxx= INT_MIN;

    // for(int i=0;i<n;i++)
    // {
    //     int val = s1.find(s2[i]);

    //     if(val <= minn)
    //     minn=val;

    //     if(val >= maxx)
    //     maxx=val;
    // }

    // cout<<s1.substr(minn,maxx);



    

    // zigzag printing the grid

    // vector<vector<int>> arr={{1,2,3},{4,5,6},{7,8,9}};

    // int n=arr.size(),m=arr[0].size();

    // for(int d=0;d<n+m-1;d++)
    // {
    //     int row,col;

    //     if(d%2==0)
    //     {
    //         row=min(n-1,d);
    //         col=d-row;

    //         while(row>=0 && col < m)
    //         {
    //             cout<<arr[row][col]<<" ";
    //             row--;
    //             col++;
    //         }
    //     }
    //     else{
    //         col=min(m-1,d);
    //         row=d-col;

    //         while(col >= 0 && row < n)
    //         {
    //             cout<<arr[row][col]<<" ";
    //             row++;
    //             col--;
    //         }
    //     }


    // }


    // int n=61;
    // // cin>>n;

    // function<bool(int)> fun = [&](int num)->bool{

    //     for(int i=2;i<sqrt(num);i++)
    //     {
    //         if(num%i==0)
    //         return false;
    //     }
    //     return true;
    // };

    // string s=to_string(n);
    // reverse(s.begin(),s.end());
    // int rev= stoi(s);

    // cout<< (fun(n) && fun(rev) ? "true" : "false");







    // Next greater on left

    // vector<int> arr={16,2,4,3,5,17};

    // int n=arr.size();
    // int minn=INT_MIN;
    // int temp=arr[0];

    // for(int i=0;i<n;i++)
    // {
    //     temp=arr[i];

    //     if(i==0)
    //     {

    //         arr[i]=-1;
    //         minn=max(minn,temp);
    //         continue;
    //     }

    //     arr[i]=minn;
    //     minn=max(minn,temp);

    // }

    // for(int i:arr)
    // cout<<i<<" ";



    // diagonal sum/

    // vector<vector<int>> arr={{1,2,3},{4,5,6},{7,8,9}};
    // int r=arr.size(), c=arr[0].size();

    // int uppersum=0, lowersum=0;

    // for(int i=0;i<r;i++)
    // {
    //     for(int j=0;j<c;j++)
    //     {
    //         if( j <= (c - i - 1))
    //         uppersum+=arr[i][j];

    //         if( j >= (c - i - 1))
    //         lowersum+= arr[i][j];
    //     }
    // }

    // if(uppersum > lowersum)
    // cout<<"Upper is greater: "<<uppersum;
    // else
    // cout<<"Lower is greater: "<< lowersum;




    // int n=5;
    // int cnt=1,flag=1;

    // for(int i=1;i<=n;i++)
    // {
    //     cnt=flag;
    //     for(int j=1;j<=n;j++)
    //     {
    //         if(cnt > n)
    //         cnt= cnt-n;
            
    //         cout<<cnt<<" ";
    //         cnt++;
    //     }
    //     cout<<endl;
    //     flag++;
    // }

    //     1 2 3 4 5 
    //     2 3 4 5 1 
    //     3 4 5 1 2 
    //     4 5 1 2 3 
    //     5 1 2 3 4 



    // int n=5;
    // int c=1;

    // for(int i=1;i<=n;i++)
    // {

    //     for(int j=0;j<n-i;j++)
    //     cout<<" "; //space;

    //     int l= i * (i+1)/2;

    //     for(int j=0;j<2*i+1;j++)
    //     cout<<l-j; 

    //     cout<<endl;
    // }

    // c=1;
    // for(int i=n;i>=1;i--)
    // {
    //     for(int j=0;j<n-i;j++)
    //     cout<<" ";

    //     int l= i * (i+1)/2;


    //     for(int j=0;j<2*i+1;j++)
    //     cout<<l-j;

    //     cout<<endl;
    // }


    // vector<int> arr={100,4,200,1,3,2};

    // unordered_set<int> set(arr.begin(),arr.end());

    // int maxx=0;

    // for(int i:set)
    // {
    //     if( !set.count(i-1))
    //     {
    //         int len=1;

    //         while( set.count(i+len))
    //         {
    //             len++;
    //         }

    //         maxx=max(maxx,len);
    //     }
    // }

    // cout<<"Length of Longest concicutive subsequence is: " <<maxx;





    // Longest palindrome from the string.

    // string s="010";

    // string left="", right="";
    // char mid=0;

    // vector<int> freq(10,0);

    // for(char ch:s)
    // freq[ch-'0']++;

    // for(int i=9;i>=0;i--)
    // {
    //     if( freq[i]%2==1 && mid==0)
    //     {
    //         mid= '0'+i;
    //     }

    //     int pair = freq[i] / 2;

    //     left.append(pair, '0'+i);
    //     right.insert(0 ,pair, '0'+i);
    // }

    // string ans= left + ( mid ? string(1,mid) : "") + right;

    // if(ans[0] == '0')
    // cout<< string(1, *max_element(s.begin(),s.end()));
    // else
    // cout<< ans;





    //smallest element in rotated array;

    // vector<int> arr={4,5,6,7,0,2};
    

    // int left=0,right=arr.size()-1;

    // while (left < right)
    // {
    //     /* code */
    //     int mid= (left+right)/2;

    //     if(arr[mid] > arr[right])
    //     left=mid+1;

    //     else
    //     right=mid;
    // }

    // cout<<arr[left];





    //Search in rotated array

    // vector<int> arr={4,5,6,7,0,1,2};
    // int tar=2;

    // int idx=-1;
    // bool flag=false;

    // int left=0,right=arr.size()-1;

    // while(left <= right)
    // {
    //     int mid = (left+right)/2;

    //     if(tar == arr[mid])
    //     {
    //         idx=mid;
    //         break;
    //     }

    //     if(arr[mid] >= arr[left] )
    //     {
    //         if(tar > arr[mid] || tar < arr[left])
    //         left= mid+1;

    //         else
    //         right = mid-1;
    //     }
    //     else{
    //         if(tar < arr[mid] || tar > arr[right])
    //         {
    //             right= mid-1;
    //         }
    //         else{
    //             left= mid+1;
    //         }
    //     }
    // }

    // cout<<idx;





    // k size palindroma
    // string s="abababa";
    // int n=s.size();

    // int k=3;
    // int c=0;

    // function<bool(string)> palin = [&](string str)->bool{
    //     int left=0,right=str.size()-1;

    //     while(left < right)
    //     {
    //         if(str[left]!=str[right])
    //         return false;

    //         left++;
    //         right--;
    //     }
    //     return true;
    // };


    // for(int i=0;i<n-k;i++)
    // {
    //     string sub=s.substr(i,k);
    //     if(palin(sub))
    //     c++;
    // }

    // cout<<c;




    // subsequence with target sum 

    // function<bool(vector<int>&,int,int ,int)> solve = [&](vector<int>&arr, int tar,int st,int cursum){

    //     if(tar==cursum)
    //     {
    //         return true;
    //     }

    //     if(tar < cursum || st >= arr.size())
    //     return false;

    //     return solve(arr,tar,st+1,cursum+arr[st]) || solve(arr,tar,st+1,cursum);

        

    // };


    // vector<int> arr={1,2,3,4};
    // int n=arr.size();
    // int k=11;
    // cout<<solve(arr,k,0,0);



    vector<int>arr={1,2,3,1,3,1,4,1};
    unordered_map<int,int> mp;
    int ans=0;

    for(int i:arr)
    {
        mp[i]++;
    }

    for(auto [_,c]:mp)
    {
        if(c>1)
        ans+= c*(c-1)/2;
    }
    cout<<ans;


    


    



    




    

    
    return 0;
}