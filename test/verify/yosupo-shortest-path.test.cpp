#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include "../../template/template.cpp"

#include "../../graph/graph-template.cpp"

#include "../../graph/shortest-path/dijkstra.cpp"

int main() {
  int N, M, S, T;
  cin >> N >> M >> S >> T;
  Graph< int64 > g(N);
  g.read(M, 0, true, true);
  auto ret = dijkstra(g, S);
  if(ret.from[T] == -1) {
    cout << -1 << "\n";
  } else {
    cout << ret.dist[T] << " ";
    vector< pair< int, int > > es;
    while(S != T) {
      es.emplace_back(ret.from[T], T);
      T = ret.from[T];
    }
    reverse(begin(es), end(es));
    cout << es.size() << "\n";
    for(auto &p : es) cout << p.first << " " << p.second << "\n";
  }
}
