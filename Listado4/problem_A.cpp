#include <bits/stdc++.h>
using namespace std;

#define MAXN 101

int capacities[MAXN][MAXN];
int flowPassed[MAXN][MAXN];
vector<int> graph[MAXN];
int parentsList[MAXN];
int currentPathCapacity[MAXN];
bool visited[MAXN];

// template edmonds karp : https://www.sanfoundry.com/cpp-program-implement-edmonds-karp-algorithm/

// bfs para maxflow
int bfs(int startNode, int endNode) {
  memset(parentsList, -1, sizeof(parentsList));
  memset(currentPathCapacity, 0, sizeof(currentPathCapacity));

  queue<int> q;
  q.push(startNode);

  parentsList[startNode] = -2;
  currentPathCapacity[startNode] = INT_MAX;

  while (!q.empty()) {
    int currentNode = q.front();
    q.pop();

    for (int i = 0; i < graph[currentNode].size(); i++) {
      int to = graph[currentNode][i];
      if (parentsList[to] == -1) {
        if (capacities[currentNode][to] - flowPassed[currentNode][to] > 0) {
          parentsList[to] = currentNode;
          currentPathCapacity[to] =
              min(currentPathCapacity[currentNode],
                  capacities[currentNode][to] - flowPassed[currentNode][to]);
          if (to == endNode) {
            return currentPathCapacity[endNode];
          }
          q.push(to);
        }
      }
    }
  }
  return 0;
}

// bfs en el grafo residual
void minCutbfs(int startNode) {
  memset(visited, false, sizeof(visited));
  queue<int> q;
  q.push(startNode);
  visited[startNode] = true;

  while (!q.empty()) {
    int currentNode = q.front();
    q.pop();

    for (int i = 0; i < graph[currentNode].size(); i++) {
      int to = graph[currentNode][i];
      if (!visited[to] && capacities[currentNode][to] - flowPassed[currentNode][to] > 0) {
        visited[to] = true;
        q.push(to);
      }
    }
  }
}

// algoritmo edmonds karp
int edmondsKarp(int startNode, int endNode) {
  int maxFlow = 0;
  while (true) {
    int flow = bfs(startNode, endNode);
    if (flow == 0) break;
    maxFlow += flow;
    int currentNode = endNode;
    while (currentNode != startNode) {
      int previousNode = parentsList[currentNode];
      flowPassed[previousNode][currentNode] += flow;
      flowPassed[currentNode][previousNode] -= flow;
      currentNode = previousNode;
    }
  }

  return maxFlow;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n, m;

  while (cin >> n >> m) {
    memset(capacities,0,sizeof(capacities));
    memset(flowPassed,0,sizeof(flowPassed));
    if (n == 0 && m == 0) break;
    while (m--) {
      int u, v, w;
      cin >> u >> v >> w;
      capacities[u][v] = capacities[v][u] = w;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    int maxFlow = edmondsKarp(1,2);
    //cout << maxFlow << endl;
    
    minCutbfs(1);

    for (int u = 1; u <= n; u++) {
      for (int v = 1; v <= n; v++) {
        if (visited[u] && !visited[v] && capacities[u][v] > 0 && capacities[u][v] - flowPassed[u][v] == 0) {
          cout << u << " " << v << endl;
        }
      } 
    }
    cout << endl;
  }
  return 0;
}