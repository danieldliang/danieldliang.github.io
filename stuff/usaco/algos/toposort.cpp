// took this one directly off of USACO Guide

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n);
	vector<int> indegree(n, 0);
	queue<int> q;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a - 1].push_back(b - 1);
		indegree[b - 1]++;
	}
	for (int i = 0; i < n; i++) {
		// locate the nodes with indegree 0 and push them into the queue
		if (indegree[i] == 0) { q.push(i); }
	}
	vector<int> order;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		// add the current node to the order
		order.push_back(curr);
		for (int next : graph[curr]) {
			// remove the current node from the graph
			indegree[next]--;
			// push any new nodes with indegree 0 into the queue
			if (indegree[next] == 0) { q.push(next); }
		}
	}
	// if there isn't a valid topological sorting
	if (order.size() != n) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	cout << order[0] + 1;
	for (int i = 1; i < n; i++) { cout << " " << order[i] + 1; }
	cout << endl;
	return 0;
}
