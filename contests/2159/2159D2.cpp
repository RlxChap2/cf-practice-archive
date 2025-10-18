#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 500000;

int caseCount, n;
int posStack[MAXN + 10];
ll valStack[MAXN + 10], totalSum;

void calculate(int index) {
    int cur = index - 1;
    int l, r, mid, bestPos;
    ll rightBound = 8e18, leftBound = valStack[index];
    ll segmentSum = posStack[index] - posStack[index - 1];
    int step = 1;

    totalSum += segmentSum;

    while (cur >= 1) {
        l = 1, r = cur - 1, bestPos = cur;
        step++;
        while (l <= r) {
            mid = (l + r) / 2;
            if (valStack[mid] * 2 >= leftBound || valStack[mid] * 3 >= rightBound)
                bestPos = min(bestPos, mid), r = mid - 1;
            else
                l = mid + 1;
        }
        rightBound = leftBound;
        leftBound = valStack[cur];
        totalSum += 1LL * step * (posStack[cur] - posStack[bestPos - 1]);
        cur = bestPos - 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> caseCount;
    while (caseCount--) {
        cin >> n;
        totalSum = 0;
        int top = 0;

        for (int i = 1; i <= n; i++) {
            ll x;
            cin >> x;

            while (top && valStack[top] >= x)
                top--;

            posStack[++top] = i;
            valStack[top] = x;

            calculate(top);
        }

        cout << totalSum << '\n';
    }
    return 0;
}
