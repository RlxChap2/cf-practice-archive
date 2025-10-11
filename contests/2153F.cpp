#include <bits/stdc++.h>
using namespace std;

constexpr int BLOCK = 400;
int testCount, arrSize, paddedSize, blockCount, queryCount;
int arr[512000];
long long currentValue;
long long precomputed[1280][1280];
bitset<512000> currentBits, blockBits[1280];

void toggleSegment(int left, int right) {
    for (int i = left; i < right; ++i) {
        if (currentBits[arr[i]]) {
            currentValue -= arr[i];
            currentBits[arr[i]] = false;
        } else {
            currentValue += arr[i];
            currentBits[arr[i]] = true;
        }
    }
}

void resetRange(int left, int right, int b1, int b2) {
    if (b1 == b2) {
        for (int i = left; i < right; ++i)
            currentBits[arr[i]] = false;
    } else {
        for (int i = left; i < right; ++i)
            currentBits[arr[i]] = blockBits[b1][arr[i]] ^ blockBits[b2][arr[i]];
    }
}

long long processQuery(int left, int right) {
    int leftBlock = left / BLOCK;
    int rightBlock = right / BLOCK;

    if (leftBlock == rightBlock) {
        currentValue = 0;
        resetRange(left, right, 0, 0);
        toggleSegment(left, right);
    } else {
        int leftBlockEnd = leftBlock * BLOCK + BLOCK;
        int rightBlockStart = rightBlock * BLOCK;
        currentValue = precomputed[leftBlock + 1][rightBlock];
        resetRange(left, leftBlockEnd, leftBlock, rightBlock - 1);
        resetRange(rightBlockStart, right, leftBlock, rightBlock - 1);
        toggleSegment(left, leftBlockEnd);
        toggleSegment(rightBlockStart, right);
    }
    return currentValue;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> testCount;
    while (testCount--) {
        cin >> arrSize >> queryCount;
        blockCount = (arrSize - 1) / BLOCK + 1;
        paddedSize = blockCount * BLOCK;

        for (int i = 0; i < arrSize; ++i)
            cin >> arr[i];
        for (int i = arrSize; i < paddedSize; ++i)
            arr[i] = 1;

        currentBits.reset();

        for (int i = 0; i < blockCount; ++i) {
            int start = i * BLOCK, end = start + BLOCK;
            for (int j = start; j < end; ++j)
                currentBits[arr[j]] = !currentBits[arr[j]];
            blockBits[i] = currentBits;
        }

        currentValue = 0;
        currentBits.reset();
        for (int i = 0; i < blockCount; ++i) {
            if (i % 2 == 0) {
                for (int j = i + 1; j <= blockCount; ++j) {
                    toggleSegment(j * BLOCK - BLOCK, j * BLOCK);
                    precomputed[i][j] = currentValue;
                }
            } else {
                toggleSegment(i * BLOCK - BLOCK, i * BLOCK);
                for (int j = blockCount; j > i; --j) {
                    precomputed[i][j] = currentValue;
                    toggleSegment(j * BLOCK - BLOCK, j * BLOCK);
                }
            }
        }

        long long lastAnswer = 0;
        while (queryCount--) {
            int l, r;
            cin >> l >> r;

            l = (l - 1 + lastAnswer) % arrSize + 1;
            r = (r - 1 + lastAnswer) % arrSize + 1;

            if (l > r) swap(l, r);
            --l;

            lastAnswer = processQuery(l, r);
            cout << lastAnswer << " ";
        }
        cout << "\n";
    }

    return 0;
}