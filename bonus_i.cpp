#include <bits/stdc++.h>
using namespace std;

const int MAX_R = 100;
const int MAX_C = 100;

int R, C;
std::vector<std::vector<int>> menu;
std::vector<std::vector<int>> dp;

int dfs(int row, int col) {
    if (dp[row][col] != -1) {
        return dp[row][col];
    }

    int result = 1;
    int currentDish = menu[row][col];

    // Movimientos posibles: arriba, abajo, izquierda, derecha
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int newRow = row + dr[i];
        int newCol = col + dc[i];

        if (newRow >= 0 && newRow < R && newCol >= 0 && newCol < C && menu[newRow][newCol] > currentDish) {
            result = std::max(result, 1 + dfs(newRow, newCol));
        }
    }

    dp[row][col] = result;
    return result;
}

int main() {
     ios_base::sync_with_stdio(false);
  cin.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
    std::cin >> R >> C;

    menu.resize(R, std::vector<int>(C));
    dp.resize(R, std::vector<int>(C, -1));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            std::cin >> menu[i][j];
        }
    }

    int maxDishes = 0;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            maxDishes = std::max(maxDishes, dfs(i, j));
        }
    }

    std::cout << maxDishes << std::endl;

    return 0;
}
