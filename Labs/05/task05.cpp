
#include <iostream>
#include <vector>

using namespace std;

class NQueens {
public:
    NQueens(int n) : N(n) {
        board.resize(N, vector<int>(N, 0));
    }

    void solve() {
        if (placeQueens(0)) {
            printBoard();
        } else {
            cout << "No solution exists." << endl;
        }
    }

private:
    int N;
    vector<vector<int>> board;

    bool placeQueens(int row) {
        if (row >= N) {
            return true;
        }

        for (int col = 0; col < N; col++) {
            if (isSafe(row, col)) {
                board[row][col] = 1;
                if (placeQueens(row + 1)) {
                    return true;
                }
                board[row][col] = 0;
            }
        }
        return false;
    }

    bool isSafe(int row, int col) {
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 1) {
                return false;
            }
        }

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 1) {
                return false;
            }
        }

        for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
            if (board[i][j] == 1) {
                return false;
            }
        }

        return true;
    }

    void printBoard() {
        cout << "One of the solutions is:" << endl;
        for (const auto& row : board) {
            for (int cell : row) {
                cout << (cell ? "Q " : ". ");
            }
            cout << endl;
        }
    }
};

int main() {
    int N;
    cout << "Enter the number of queens (N): ";
    cin >> N;

    NQueens nQueens(N);
    nQueens.solve();

    return 0;
}
