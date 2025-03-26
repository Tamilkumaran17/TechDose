#include <bits/stdc++.h>
using namespace std;


//79

vector<vector<int>> visited;

vector<int> dx={1,0,-1,0}, dy={0,1,0,-1};

bool backtrack(int row, int col, int idx, vector<vector<char>>& board,  string& word)
{
    int m=board.size(), n=board[0].size();
    bool ans=false;

    if(idx==word.size())
    ans=true;
    else{

        visited[row][col]=1;
        
        for(int i=0; i<4 && !ans; i++)
        {
            int nx= row+dx[i];
            int ny= col+dy[i];

            if(nx>=0 && ny>=0 && nx<m && ny<n && !visited[nx][ny] && board[nx][ny]==word[idx])
            ans= backtrack(nx,ny,idx+1, board,word);
        }

        visited[row][col]=0;
    }
    return ans;
}


void solve()
{
    int m,n;
    cin>>m>>n;

    vector<vector<char>> board(m,vector<char>(n));

    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    cin>>board[i][j];

    string word;
    cin>>word;

    visited.resize(m,vector<int>(n,0));

    bool ans=false;

    for(int i=0;i<m && !ans; i++)
    {
        for(int j=0;j<n && !ans; j++)
        {
            if(board[i][j]==word[0])
            ans = backtrack(i,j,1, board,word);
        }
    }

    cout<< (ans ? "Word can be exsisted." : "Word cannot be exsisted.");


   
}

int main()
{
     #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

    return 0;

}