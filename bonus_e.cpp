#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, E;
    std::cin >> N >> K >> E;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    std::vector<std::vector<int>> dp(E + 1, std::vector<int>(N + 1, 0));

    // Llenar la primera fila de la matriz
    for (int i = 1; i <= N; i++) {
        dp[0][i] = i <= K ? K - i : 0;
    }

    // Calcular los valores de la matriz utilizando programación dinámica
    for (int i = 1; i <= E; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
        }
    }

    int emptySquares = dp[E][N];
    std::cout << emptySquares << std::endl;

    return 0;
}
