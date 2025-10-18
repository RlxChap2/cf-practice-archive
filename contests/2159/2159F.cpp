#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define readc() getchar()

const int MAXN = 505;

int testCount;
int n, m;
int grid[MAXN][MAXN];
int tempVal;
int timeStamp[MAXN * MAXN];
int queryResult;

inline int queryCell(int row, int col) {
    printf("? %d %d\n", row, col);
    fflush(stdout);
    scanf("%d", &queryResult);
    return queryResult;
}

struct Entry {
    int row, pos, target;
    int val;
} heapArr[MAXN * MAXN * 2];

int heapSize;

inline bool cmpEntry(const Entry &a, const Entry &b) {
    return a.val < b.val;
}

inline void pushEntry(const Entry &e) {
    heapArr[++heapSize] = e;
    int cur = heapSize;
    while (cur > 1 && cmpEntry(heapArr[cur], heapArr[cur / 2])) {
        swap(heapArr[cur], heapArr[cur / 2]);
        cur /= 2;
    }
}

inline void popEntry() {
    heapArr[1] = heapArr[heapSize--];
    int cur = 1;
    while ((cur * 2 <= heapSize && cmpEntry(heapArr[cur * 2], heapArr[cur])) ||
           (cur * 2 + 1 <= heapSize && cmpEntry(heapArr[cur * 2 + 1], heapArr[cur]))) {
        int nxt = cur * 2;
        if (nxt + 1 <= heapSize && cmpEntry(heapArr[nxt + 1], heapArr[nxt])) nxt++;
        swap(heapArr[cur], heapArr[nxt]);
        cur = nxt;
    }
}

int finalAns[MAXN * MAXN * 2];

void processCase() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &grid[i][j]);
            timeStamp[grid[i][j]] = (i + j - 1);
        }
    }

    for (int j = 1; j <= n; j++) {
        timeStamp[grid[1][j]] = 1;
    }

    heapSize = 0;

    for (int id = 1; id <= n; id++) {
        for (int start = 1; start <= 2 * n - 1; start += id) {
            int end = min(start + id - 1, 2 * n - 1);
            int left = start, right = end, mid = 0;

            while (left + 1 < right) {
                mid = (left + right) / 2;
                if (timeStamp[queryCell(id, mid)] > start)
                    right = mid;
                else
                    left = mid;
            }

            pushEntry({id, right, end, queryCell(id, right)});
            if (left != right)
                pushEntry({id, left, start, queryCell(id, left)});
        }
    }

    for (int i = 1; i <= m; i++) {
        int id = heapArr[1].row;
        int now = heapArr[1].pos;
        int end = heapArr[1].target;
        finalAns[i] = heapArr[1].val;
        popEntry();

        if (now == end) continue;
        if (now < end)
            pushEntry({id, now + 1, end, queryCell(id, now + 1)});
        else
            pushEntry({id, now - 1, end, queryCell(id, now - 1)});
    }

    printf("! ");
    for (int i = 1; i <= m; i++) printf("%d ", finalAns[i]);
    printf("\n");
    fflush(stdout);
}

int main() {
    scanf("%d", &testCount);
    while (testCount--) processCase();
    return 0;
}
