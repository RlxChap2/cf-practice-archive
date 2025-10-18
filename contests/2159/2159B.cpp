#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 10;
const int MAXM = 510;

int rows, cols;
vector<int> best[MAXM];
string grid[MAXN], rotated[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        cin >> rows >> cols;

        for (int i = 1; i <= rows; i++) {
            cin >> grid[i];
            grid[i] = " " + grid[i];
        }

        bool flipped = false;

        if (rows > cols) {
            flipped = true;
            swap(rows, cols);

            for (int i = 1; i <= rows; i++) {
                rotated[i] = " ";
                for (int j = 1; j <= cols; j++)
                    rotated[i] += grid[j][i];
            }

            for (int i = 1; i <= rows; i++)
                grid[i] = rotated[i];
        }

        for (int i = 1; i <= rows; i++) {
            best[i].assign(cols + 1, 0x3f3f3f3f);
        }

        for (int top = 1; top <= rows; top++) {
            for (int bottom = top + 1; bottom <= rows; bottom++) {
                int last = 0;
                for (int c = 1; c <= cols; c++) {
                    if (grid[top][c] == '1' && grid[bottom][c] == '1') {
                        if (last) {
                            int area = (bottom - top + 1) * (c - last + 1);
                            while (last <= c) {
                                best[bottom][last] = min(best[bottom][last], area);
                                last++;
                            }
                        }
                        last = c;
                    }
                }
            }

            for (int r = rows; r >= top + 1; r--) {
                for (int c = 1; c <= cols; c++) {
                    best[r - 1][c] = min(best[r - 1][c], best[r][c]);
                }
            }
        }

        if (flipped)
            swap(rows, cols);

        for (int i = 1; i <= rows; i++, cout << '\n') {
            for (int j = 1; j <= cols; j++) {
                int val = flipped ? best[j][i] : best[i][j];
                if (val == 0x3f3f3f3f) cout << 0 << ' ';
                else cout << val << ' ';
            }
        }
    }

    return 0;
}
