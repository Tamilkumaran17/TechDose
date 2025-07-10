for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        cout<<"*";

        for(int j=0;j<space;j++)
        cout<<" ";

        for(int j=i;j>=0;j--)
        cout<<"*";

        space-=2;

        cout<<endl;
    }