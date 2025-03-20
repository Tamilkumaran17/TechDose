// #include <bits/stdtr1c++.h>
// using namespace std;

// bool isValid(vector<vector<int>>& adj, int n)
// {
//     unordered_set<int> visit;
//     queue<int> q;
//     visit.insert(0);
//     q.push(0);
   

//     while(!q.empty())
//     {
//         int node=q.front();
//         q.pop();
//         for(int i:adj[node])
//         {

//             if(visit.count(i))
//             {
//                 return false;
//             }

//             visit.insert(i);
//             q.push(node);

//         }
      
//     }
//     return visit.size()==n;
// }

// void solve()
// {
//     int n;
//     cin>>n;
//     vector<vector<int>> edges(n-1);
//     for(int i=0;i<n-1;i++)
//     {
//         int u,v;
//         cin>>u>>v;
//         edges[i].push_back(u);
//         edges[i].push_back(v);
//     }
    
//     vector<vector<int>> adj(n);

//     for(const auto&i: edges)
//     {
//         adj[i[0]].push_back(i[1]);
//         adj[i[1]].push_back(i[0]);
//     }
    
//     if(isValid(adj,n))
//     cout<<"true"<<endl;
//     else
//     cout<<"false"<<endl;



// }

// int main()
// {
//      #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     #endif

//     solve();

//     return 0;
// }

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <bits/stdc++.h>

bool isValid(const std::vector<std::vector<int>>& adj, int n) {
    std::unordered_set<int> visit;
    std::queue<int> q;
    visit.insert(0);
    q.push(0);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor : adj[node]) {
            if (visit.count(neighbor)) {
                return false;
            }
            
            visit.insert(neighbor);
            q.push(neighbor);
        }
    }
    return visit.size() == n;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (isValid(adj, n)) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }
}

int main() {
   
    solve();
    return 0;
}