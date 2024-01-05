#include <fstream>
#include <vector>
#include <queue>
#include <climits>

typedef std::pair<long long int, long long int> p;

long long int dijkstra(std::vector<std::vector<p>> &graph, long long int start, long long int end) {
    long long int n = graph.size();
    std::vector<long long int> distances(n, LLONG_MAX);
    distances[start - 1] = 0;

    std::priority_queue<p, std::vector<p>, std::greater<p>> pq;

    pq.push({0, start});

    while (!pq.empty()) {
        long long int current_distance = pq.top().first;
        long long int current_vertex = pq.top().second;
        pq.pop();

        if (current_vertex == end) {
            return current_distance;
        }

        for (const auto &neighbor: graph[current_vertex - 1]) {
            long long int neighbor_vertex = neighbor.second;
            long long int edge_weight = neighbor.first;

            if (distances[current_vertex - 1] + edge_weight < distances[neighbor_vertex - 1]) {
                distances[neighbor_vertex - 1] = distances[current_vertex - 1] + edge_weight;
                pq.push({distances[neighbor_vertex - 1], neighbor_vertex});
            }
        }
    }

    return -1;
}

int main() {
    std::ifstream in("input.txt");
    long long int n, m;
    in >> n;
    in >> m;

    std::vector<std::vector<p>> graph(n);

    for (long long int i = 0; i < m; ++i) {
        long long int u, v, w;
        in >> u;
        in >> v;
        in >> w;
        graph[u - 1].push_back({w, v});
        graph[v - 1].push_back({w, u});
    }
    in.close();
    long long int shortest_path_length = dijkstra(graph, 1, n);

    std::ofstream out("output.txt");
    out << shortest_path_length << '\n';
    out.close();

    return 0;
}
