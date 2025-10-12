#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const long long MAXVAL = 4e18;

void run_case() {
    int rows_input, cols_input;
    cin >> rows_input >> cols_input;
    vector<string> base_grid(rows_input);
    for (int i = 0; i < rows_input; ++i) {
        cin >> base_grid[i];
    }

    bool flipped = false;
    int rows = rows_input, cols = cols_input;
    vector<string> grid = base_grid;

    if (rows > cols) {
        flipped = true;
        swap(rows, cols);
        grid.assign(rows, string(cols, '0'));
        for (int i = 0; i < rows_input; ++i) {
            for (int j = 0; j < cols_input; ++j) {
                grid[j][i] = base_grid[i][j];
            }
        }
    }

    vector<vector<long long>> best(rows, vector<long long>(cols, MAXVAL));

    for (int top = 0; top < rows; ++top) {
        vector<vector<long long>> rect(rows, vector<long long>(cols, MAXVAL));

        for (int bottom = top + 1; bottom < rows; ++bottom) {
            vector<int> active_cols;
            for (int j = 0; j < cols; ++j) {
                if (grid[top][j] == '1' && grid[bottom][j] == '1') {
                    active_cols.push_back(j);
                }
            }

            if (active_cols.size() < 2) continue;

            for (size_t idx = 0; idx + 1 < active_cols.size(); ++idx) {
                int left = active_cols[idx];
                int right = active_cols[idx + 1];
                long long area = 1LL * (bottom - top + 1) * (right - left + 1);
                for (int k = left; k <= right; ++k) {
                    rect[bottom][k] = min(rect[bottom][k], area);
                }
            }
        }

        for (int j = 0; j < cols; ++j) {
            for (int bottom = rows - 2; bottom >= top; --bottom) {
                rect[bottom][j] = min(rect[bottom][j], rect[bottom + 1][j]);
            }
            for (int bottom = top; bottom < rows; ++bottom) {
                best[bottom][j] = min(best[bottom][j], rect[bottom][j]);
            }
        }
    }

    if (flipped) {
        vector<vector<long long>> restored(cols, vector<long long>(rows));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                restored[j][i] = best[i][j];
            }
        }
        best = restored;
        swap(rows, cols);
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << (best[i][j] >= MAXVAL ? 0 : best[i][j]) << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cases;
    cin >> cases;
    while (cases--) run_case();
    return 0;
}