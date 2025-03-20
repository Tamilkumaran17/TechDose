#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

// Directions: Right, Left, Down, Up
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

struct State {
    int x, y, dir, jump_length, jumps;
};

int minJumpsToEnd(vector<string>& grid) {
    int n = grid.size(), m = grid[0].size();
    int sx = -1, sy = -1, ex = -1, ey = -1;

    // Find Start (S) and End (E)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'S') sx = i, sy = j;
            if (grid[i][j] == 'E') ex = i, ey = j;
        }
    }

    queue<State> q;
    vector<vector<vector<vector<bool>>>> visited(n, vector<vector<vector<bool>>>(m, vector<vector<bool>>(4, vector<bool>(m + n, false))));

    // Push all possible initial directions
    for (int d = 0; d < 4; d++) {
        q.push({sx, sy, d, 1, 0});
    }

    while (!q.empty()) {
        auto [x, y, dir, jump_length, jumps] = q.front();
        q.pop();

        // If reached the end
        if (x == ex && y == ey) return jumps;

        // If already visited with same direction and jump_length, continue
        if (visited[x][y][dir][jump_length]) continue;
        visited[x][y][dir][jump_length] = true;

        // Move in the same direction with the current jump length
        int nx = x + dx[dir] * jump_length;
        int ny = y + dy[dir] * jump_length;

        // Check boundaries and ensure destination is an empty cell
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#') {
            q.push({nx, ny, dir, jump_length + 1, jumps + 1});
        }

        // Last jump must be 1, allow changing direction
        if (jump_length == 1) {
            for (int new_dir = 0; new_dir < 4; new_dir++) {
                if (new_dir == dir) continue;
                int nx2 = x + dx[new_dir];
                int ny2 = y + dy[new_dir];

                if (nx2 >= 0 && nx2 < n && ny2 >= 0 && ny2 < m && grid[nx2][ny2] != '#') {
                    q.push({nx2, ny2, new_dir, 1, jumps + 1});
                }
            }
        }
    }

    return -1;  // No valid path found
}

int main() {
    vector<string> grid = {
        "S****#",
        "**#***",
        "*****#",
        "*#*#**",
        "#****E"
    };

    int result = minJumpsToEnd(grid);
    cout << result << endl;  // Output: Minimum jumps to reach E from S

    return 0;
}
