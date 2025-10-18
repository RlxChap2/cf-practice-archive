#include <cstdio>

int n;
int width[5001], height[5001];
int nextBox[5001], memo[5001];

int longestSequence(int box) {
    if (memo[box]) return memo[box];

    memo[box] = 1;
    for (int i = 0; i <= n; i++) {
        if (width[i] > width[box] && height[i] > height[box]) {
            int candidate = longestSequence(i) + 1;
            if (candidate > memo[box]) {
                memo[box] = candidate;
                nextBox[box] = i;
            }
        }
    }
    return memo[box];
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i <= n; i++) {
        nextBox[i] = -1;
        scanf("%d%d", &width[i], &height[i]);
    }

    longestSequence(0);
    printf("%d\n", memo[0] - 1);

    for (int i = nextBox[0]; i != -1; i = nextBox[i])
        printf("%d ", i);
}
