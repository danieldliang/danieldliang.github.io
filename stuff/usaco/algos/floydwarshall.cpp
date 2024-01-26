// Taken and edited from USACO Guide. Honestly a very simple implementation, so not sure if this file is really even needed.
int main() {
  vector<vector<long long>> min_dist(n, vector<long long>(n, INT_MAX));

  int a, b, c;
  for (int i = 0; i < m; i++) {
		cin >> a >> b >> c; // a and b are node IDs, c is the edge weight between nodes a and b
		if (c < min_dist[a][b]) { min_dist[a][b] = min_dist[b][a] = c; }
	}
  
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        long long new_dist = min_dist[i][k] + min_dist[k][j];
        if (new_dist < min_dist[i][j]) {
          min_dist[i][j] = min_dist[j][i] = new_dist;
        }
      }
    }
  }
}
