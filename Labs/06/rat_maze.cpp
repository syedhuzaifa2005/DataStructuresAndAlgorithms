#include <iostream>
using namespace std;

const int MAX = 10;

bool isSafe(int x, int y, int mat[MAX][MAX], int visited[MAX][MAX], int n) {
    return (x >= 0 && x < n && y >= 0 && y < n && mat[x][y] == 1 && visited[x][y] == 0);
}

void findPaths(int x, int y, int mat[MAX][MAX], int n, string path, int visited[MAX][MAX]) {
    if (x == n - 1 && y == n - 1) {
        cout << path << endl;
        return;
    }

    visited[x][y] = 1;

    if (isSafe(x + 1, y, mat, visited, n)) {
        findPaths(x + 1, y, mat, n, path + 'D', visited);
    }

    if (isSafe(x, y - 1, mat, visited, n)) {
        findPaths(x, y - 1, mat, n, path + 'L', visited);
    }

    if (isSafe(x, y + 1, mat, visited, n)) {
        findPaths(x, y + 1, mat, n, path + 'R', visited);
    }

    if (isSafe(x - 1, y, mat, visited, n)) {
        findPaths(x - 1, y, mat, n, path + 'U', visited);
    }

    visited[x][y] = 0;
}

void ratInAMaze(int mat[MAX][MAX], int n) {
    int visited[MAX][MAX] = {0};

    if (mat[0][0] == 0 || mat[n - 1][n - 1] == 0) {
        cout << "No path found" << endl;
        return;
    }

    cout << "Possible paths:" << endl;
    findPaths(0, 0, mat, n, "", visited);
}

int main() {
    int mat[MAX][MAX] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    int n = 4;

    ratInAMaze(mat, n);
}
