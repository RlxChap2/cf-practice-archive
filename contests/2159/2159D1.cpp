#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 400000;
int totalCases, sizeArr, refIndex[130];
long long inputArr[MAXN + 5], filtered[MAXN + 5];

void processCase() {
    scanf("%lld", &sizeArr);
    for (int i = 1; i <= sizeArr; i++)
        scanf("%lld", &inputArr[i]);

    int countValid = 0;
    filtered[countValid] = 2e18;

    for (int i = sizeArr; i >= 1; i--) {
        if (inputArr[i] < filtered[countValid])
            filtered[++countValid] = inputArr[i];
    }

    reverse(filtered + 1, filtered + countValid + 1);

    for (int i = 0; i <= 120; i++)
        refIndex[i] = 0;

    for (int i = 1; i <= countValid; i++) {
        long long best = 1e18;
        for (int j = 0; j <= 120; j++) {
            long long idx = refIndex[j] + 1;
            long long val = (filtered[i] + filtered[idx] - 1) / filtered[idx] + j;
            best = min(best, val);
        }
        refIndex[best] = i;

        if (i == countValid)
            printf("%lld\n", best);
    }
}

signed main() {
    scanf("%lld", &totalCases);
    while (totalCases--)
        processCase();
    return 0;
}
