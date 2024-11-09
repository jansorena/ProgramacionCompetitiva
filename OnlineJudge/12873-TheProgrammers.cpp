#include <bits/stdc++.h>
using namespace std;
#define MAXN 550

int capacities[MAXN][MAXN];
int flowPassed[MAXN][MAXN];
vector<int> graph[MAXN];
int parentsList[MAXN];
int currentPathCapacity[MAXN];

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

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  int n; cin >> n;
  while(n--){
  	memset(capacities,0,sizeof(capacities));
    memset(flowPassed,0,sizeof(flowPassed));
  	int P,S,C,m; cin >> P >> S >> C >> m;
  	
  	// nodos extra para la red
  	int source = 0;
  	int sink = P + S + 1;

  	// conectar la fuente con los sitios concurso
  	for (int i = 1; i <= S; ++i){
  		capacities[source][i] = capacities[i][source] = C;
  		graph[source].push_back(i);
      	graph[i].push_back(source); 
  	}

  	// conectar participantes con el sumidero
  	for (int i = 1; i <= P; ++i){
  		capacities[S+i][sink] = capacities[sink][S+i] = 1;
  		graph[S+i].push_back(sink);
      	graph[sink].push_back(S+i); 
  	}

  	// concursantes y sitios
  	for (int i = 0; i < m; i++) {
        int contestant, site; cin >> contestant >> site;
  		capacities[site][S+contestant] = capacities[S+contestant][site] = 1;
  		graph[S+contestant].push_back(site);
      	graph[site].push_back(S+contestant); 
    }

    int maxFlow = edmondsKarp(source,sink);
    cout << maxFlow << endl;

  }

	return 0;
}