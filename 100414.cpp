#include <vector>
#include <queue>

using namespace std;

class Solution {
  public:
  bool findSafeWalk(vector<vector<int>>& grid, int health) {
    int m = grid.size();
    int n = grid[0].size();

    // Directions for moving in the grid (right, down, left, up)
    vector<vector<int>> visited(m, vector<int>(n, -1));
    queue<pair<pair<int, int>, int>> q;

    q.push({{0, 0}, health - grid[0][0]});
    visited[0][0] = health - grid[0][0];
    int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    while (!q.empty()) {
      auto [pos, currhealth] = q.front();
      q.pop();

      int x = pos.first;
      int y = pos.second;

      if (x == m - 1 && y == n - 1 && currhealth > 0)
        return true;
      for (int i = 0; i < 4; i++) {
        int newx = x + direction[i][0];
        int newy = y + direction[i][1];

        if (newx >= 0 && newy >= 0 && newy < n && newx < m) {
          int newhealth = currhealth - grid[newx][newy];

          if (newhealth > 0 && newhealth > visited[newx][newy]) {
            visited[newx][newy] = newhealth;
            q.push({{newx, newy}, newhealth});
          }
        }
      }
    }
    return false;
  }
};
