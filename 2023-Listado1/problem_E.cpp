#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
bool visited[MAXN];
int parent[MAXN];

bool dfs(int node, int root) {
    visited[node] = true;
    parent[node] = root;

    for(int i = 0; i < adj[node].size(); i++){
        int aux = adj[node][i];
        if(!visited[aux]){
            if(!dfs(aux,node)) return false;
            else if(node != parent[aux]) return false;
        }
    }
    return true;
}

bool Rooted(int n, int m){
    if (m != n-1) return false;
    int root = -1;
    for (int i = 0; i < n; i++) {
        if (adj[i].empty()) {
            if (root == -1) root = i;
            else return false;
        }
    }

    if (root == -1) return false;

    memset(visited, false, sizeof visited);
    memset(parent, 0, sizeof parent);

    if (!dfs(root, 0)) return false;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) return false;
    }

    return true;
}

int main() {
    int n, m, count = 1;
    unordered_map<int,int> mymap;
    int edges = 0;
    while(cin >> n >> m){
        if(n == -1 && m == -1) break;
        if(n == 0 && m == 0){
            cout << mymap.size() << " " << edges << endl;
            bool flag = Rooted(mymap.size(),edges);
            if (flag) cout << "Case " << count << " is a tree." << endl;
            else cout << "Case " << count << " is not a tree." << endl;
            count++;
            mymap.clear();
            edges = 0;
            for(int i = 0; i < MAXN; i++){
                adj[i].clear();
            }
        }else{
            adj[n].push_back(m);
            mymap[n]++;
            mymap[m]++;
            edges++;
        }
    }
    return 0;
}