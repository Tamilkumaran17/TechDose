#include <bits/stdc++.h>
using namespace std;

int main()
{

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

   
    // int i, j, var = 'A';
    // for (i = 5; i >= 1; i--) {
    //     for (j = 0; j < i; j++)
    //         printf("%c ", (var + j));
    //     printf("\n");
    // }

    // cout<<endl;

    int a=10, b=21;

    int need=4;
    int tot=a+b;
    int farmost= tot/need;

    if(tot < need)
    cout<<0;

    int flag=0;

    while(farmost!=0 && (a/farmost !=0 || b/farmost !=0))
    {
        int as= a/farmost, bs= b/farmost;

        if(as+bs == need)
        {
            cout<<farmost;
            flag=1;
            break;
        }
        else{
            farmost--;
        }
    }

    if(flag==0)
    cout<<0;






    


    























    return 0;
}