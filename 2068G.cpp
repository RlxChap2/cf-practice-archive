#include <bits/stdc++.h>
using namespace std;

typedef __int128 int128;
const double SCALE = 1e20;
const int128 BIG = 1e18;

int gridSize;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int height[22][22];
int startX[42], startY[42];
int cost[42][884][444];

struct Node {
    int x, y, c;
    bool operator<(const Node& other) const {
        return c > other.c;
    }
};

priority_queue<Node> pq;

int moveCost(int x0, int y0, int x1, int y1) {
    x0 %= gridSize;
    y0 %= gridSize;
    x1 %= gridSize;
    y1 %= gridSize;
    return 1 + abs(height[x0][y0] - height[x1][y1]);
}

void updateCost(int idx, int nx, int ny, int c) {
    if (cost[idx][nx][ny] <= c) return;
    cost[idx][nx][ny] = c;
    pq.push({ nx, ny, c });
}

struct Point {
    int128 x, y;
    bool operator<(const Point& p) const {
        return y == p.y ? x < p.x : y < p.y;
    }
};

vector<Point> pointsVec;

int128 ccw(const Point& a, const Point& b, const Point& c) {
    return a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
}

double distanceSquared(const Point& a, const Point& b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool angleCmp(const Point& a, const Point& b) {
    int128 c = ccw(pointsVec[0], a, b);
    if (c == 0) return distanceSquared(pointsVec[0], a) < distanceSquared(pointsVec[0], b);
    return c > 0;
}

vector<Point> convexHull;

int32_t main() {
    scanf("%d", &gridSize);

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            scanf("%d", &height[i][j]);
        }
    }

    startX[0] = gridSize * gridSize;
    for (int i = 1; i < gridSize; i++) {
        startX[i] = i + gridSize * gridSize;
        startX[i + gridSize - 1] = gridSize - 1 + gridSize * gridSize;
        startY[i + gridSize - 1] = i;
    }

    memset(cost, 0x77, sizeof(cost));
    int maxX = 2 * gridSize * gridSize + gridSize;
    int maxY = gridSize * gridSize + gridSize;

    for (int i = 0; i < 2 * gridSize - 1; i++) {
        cost[i][startX[i]][startY[i]] = 0;
        pq.push({ startX[i], startY[i], 0 });

        while (!pq.empty()) {
            Node cur = pq.top();
            pq.pop();
            for (int j = 0; j < 4; j++) {
                int nx = cur.x + dx[j];
                int ny = cur.y + dy[j];
                if (nx < 0 || ny < 0 || nx > maxX || ny > maxY) continue;
                updateCost(i, nx, ny, cur.c + moveCost(cur.x, cur.y, nx, ny));
            }
        }

        for (int dxn = -gridSize; dxn <= gridSize; dxn++) {
            for (int dyn = 0; dyn <= gridSize; dyn++) {
                if (dxn * dxn + dyn * dyn == 0) continue;
                int nx = dxn * gridSize;
                int ny = dyn * gridSize;
                int d = cost[i][startX[i] + nx][startY[i] + ny];
                pointsVec.push_back({ BIG * nx / d, BIG * ny / d });
                pointsVec.push_back({ -BIG * nx / d, -BIG * ny / d });
            }
        }
    }

    sort(pointsVec.begin(), pointsVec.end());
    sort(pointsVec.begin() + 1, pointsVec.end(), angleCmp);

    convexHull.push_back(pointsVec[0]);
    convexHull.push_back(pointsVec[1]);
    for (int i = 2; i < pointsVec.size(); i++) {
        while (convexHull.size() >= 2 &&
               ccw(pointsVec[i], convexHull[convexHull.size() - 2], convexHull.back()) <= 0) {
            convexHull.pop_back();
        }
        convexHull.push_back(pointsVec[i]);
    }

    int128 area = convexHull.back().x * convexHull[0].y - convexHull.back().y * convexHull[0].x;
    for (int i = 1; i < convexHull.size(); i++) {
        area += convexHull[i - 1].x * convexHull[i].y - convexHull[i - 1].y * convexHull[i].x;
    }

    double finalArea = area * (SCALE / BIG) * (SCALE / BIG) / 2;
    printf("%.10e", finalArea);

    return 0;
}
