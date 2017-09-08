class Solution {
	int delta[4][2] = { {0, -1}, {1, 0}, {0, 1}, { -1, 0} };
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		vector<vector<int>> dist;
		queue<pair<int,int>> q;

		dist.resize(matrix.size());
		for (int y = 0; y < dist.size(); ++y) {
			dist[y].resize(matrix[y].size(), -1);
		}

		for (int y = 0; y < dist.size(); ++y) {
			for (int x = 0; x < dist[y].size(); ++x) {
				if (matrix[y][x] == 0) {
					dist[y][x] = 0;
					q.push(make_pair(y, x));
				}
			}
		}

		while (!q.empty()) {
			pair<int, int> cur = q.front();
			q.pop();

			for (int i = 0; i < 4; ++i) {
				pair<int, int> next = make_pair(cur.first + delta[i][0], cur.second + delta[i][1]);
				if (next.first < 0 || next.first >= matrix.size() ||
						next.second < 0 || next.second >= matrix[0].size() ) {
					continue;
				}
				if (dist[next.first][next.second] != -1)
					continue;
				dist[next.first][next.second] = dist[cur.first][cur.second] + 1;
				q.push(next);
			}
		}
		return dist;
	}
};
