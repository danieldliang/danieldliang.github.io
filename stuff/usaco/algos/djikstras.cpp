// took and edited from GFGs
int main() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq; // bfs uses queue, dfs uses stack, djikstra's uses pq

	vector<int> dist(V, INT_MAX); // distance vector (maps node ID, given by vector index, to shortest distance between the source node to the node)

	pq.push(make_pair(0, src));
	dist[src] = 0;

	while (!pq.empty()) { // notice the pattern between djikstra's and bfs, dfs
		int u = pq.top().second;
		pq.pop();

		for (const auto& next: adj[u]) { // adj is a vector which maps node ID (as index) to pair<int (weight of edge which connects current node to said adjacent node), int (this is the next adjacent node ID)>
			int weight = next.first;
			int v = next.second;

			if (dist[v] > dist[u] + weight) {
				dist[v] = dist[u] + weight; // update new min distance for node v
				pq.push(make_pair(dist[v], v)); // you can think of djikstra's being a discrete/greedy BFS. It will focus on the current shortest path and greedily search adjacent paths.
			}
		}
	}
}
