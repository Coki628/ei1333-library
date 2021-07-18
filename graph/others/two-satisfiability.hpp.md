---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/connected-components/strongly-connected-components.hpp
    title: "Strongly Connected Components(\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\
      )"
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-two-sat.test.cpp
    title: test/verify/yosupo-two-sat.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/two-satisfiability.md
    document_title: 2-SAT
    links: []
  bundledCode: "#line 2 \"graph/others/two-satisfiability.hpp\"\n\n#line 2 \"graph/connected-components/strongly-connected-components.hpp\"\
    \n\n#line 2 \"graph/graph-template.hpp\"\n\ntemplate< typename T = int >\nstruct\
    \ Edge {\n  int from, to;\n  T cost;\n  int idx;\n\n  Edge() = default;\n\n  Edge(int\
    \ from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx)\
    \ {}\n\n  operator int() const { return to; }\n};\n\ntemplate< typename T = int\
    \ >\nstruct Graph {\n  vector< vector< Edge< T > > > g;\n  int es;\n\n  Graph()\
    \ = default;\n\n  explicit Graph(int n) : g(n), es(0) {}\n\n  size_t size() const\
    \ {\n    return g.size();\n  }\n\n  void add_directed_edge(int from, int to, T\
    \ cost = 1) {\n    g[from].emplace_back(from, to, cost, es++);\n  }\n\n  void\
    \ add_edge(int from, int to, T cost = 1) {\n    g[from].emplace_back(from, to,\
    \ cost, es);\n    g[to].emplace_back(to, from, cost, es++);\n  }\n\n  void read(int\
    \ M, int padding = -1, bool weighted = false, bool directed = false) {\n    for(int\
    \ i = 0; i < M; i++) {\n      int a, b;\n      cin >> a >> b;\n      a += padding;\n\
    \      b += padding;\n      T c = T(1);\n      if(weighted) cin >> c;\n      if(directed)\
    \ add_directed_edge(a, b, c);\n      else add_edge(a, b, c);\n    }\n  }\n};\n\
    \ntemplate< typename T = int >\nusing Edges = vector< Edge< T > >;\n#line 4 \"\
    graph/connected-components/strongly-connected-components.hpp\"\n\n/**\n * @brief\
    \ Strongly Connected Components(\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3)\n\
    \ * @docs docs/strongly-connected-components.md\n */\ntemplate< typename T = int\
    \ >\nstruct StronglyConnectedComponents : Graph< T > {\npublic:\n  using Graph<\
    \ T >::Graph;\n  using Graph< T >::g;\n  vector< int > comp;\n  Graph< T > dag;\n\
    \  vector< vector< int > > group;\n\n  void build() {\n    rg = Graph< T >(g.size());\n\
    \    for(size_t i = 0; i < g.size(); i++) {\n      for(auto &e : g[i]) {\n   \
    \     rg.add_directed_edge(e.to, e.from, e.cost);\n      }\n    }\n    comp.assign(g.size(),\
    \ -1);\n    used.assign(g.size(), 0);\n    for(size_t i = 0; i < g.size(); i++)\
    \ dfs(i);\n    reverse(begin(order), end(order));\n    int ptr = 0;\n    for(int\
    \ i : order) if(comp[i] == -1) rdfs(i, ptr), ptr++;\n    dag = Graph< T >(ptr);\n\
    \    for(size_t i = 0; i < g.size(); i++) {\n      for(auto &e : g[i]) {\n   \
    \     int x = comp[e.from], y = comp[e.to];\n        if(x == y) continue;\n  \
    \      dag.add_directed_edge(x, y, e.cost);\n      }\n    }\n    group.resize(ptr);\n\
    \    for(size_t i = 0; i < g.size(); i++) {\n      group[comp[i]].emplace_back(i);\n\
    \    }\n  }\n\n  int operator[](int k) const {\n    return comp[k];\n  }\n\nprivate:\n\
    \  vector< int > order, used;\n  Graph< T > rg;\n\n  void dfs(int idx) {\n   \
    \ if(exchange(used[idx], true)) return;\n    for(auto &to : g[idx]) dfs(to);\n\
    \    order.push_back(idx);\n  }\n\n  void rdfs(int idx, int cnt) {\n    if(comp[idx]\
    \ != -1) return;\n    comp[idx] = cnt;\n    for(auto &to : rg.g[idx]) rdfs(to,\
    \ cnt);\n  }\n};\n#line 4 \"graph/others/two-satisfiability.hpp\"\n\n/**\n * @brief\
    \ 2-SAT\n * @docs docs/two-satisfiability.md\n */\nstruct TwoSatisfiability :\
    \ StronglyConnectedComponents< bool > {\npublic:\n  using StronglyConnectedComponents<\
    \ bool >::g;\n  using StronglyConnectedComponents< bool >::comp;\n  using StronglyConnectedComponents<\
    \ bool >::add_edge;\n  size_t sz;\n\n  explicit TwoSatisfiability(size_t v) :\
    \ StronglyConnectedComponents< bool >(v + v), sz(v) {}\n\n  void add_if(int u,\
    \ int v) {\n    // u -> v <=> !v -> !u\n    add_directed_edge(u, v);\n    add_directed_edge(rev(v),\
    \ rev(u));\n  }\n\n  void add_or(int u, int v) {\n    // u or v <=> !u -> v\n\
    \    add_if(rev(u), v);\n  }\n\n  void add_nand(int u, int v) {\n    // u nand\
    \ v <=> u -> !v\n    add_if(u, rev(v));\n  }\n\n  void set_true(int u) {\n   \
    \ // u <=> !u -> u\n    add_directed_edge(rev(u), u);\n  }\n\n  void set_false(int\
    \ u) {\n    // !u <=> u -> !u\n    add_directed_edge(u, rev(u));\n  }\n\n  inline\
    \ int rev(int x) {\n    if(x >= (int)sz) return x - sz;\n    return x + sz;\n\
    \  }\n\n  vector< int > solve() {\n    StronglyConnectedComponents< bool >::build();\n\
    \    vector< int > ret(sz);\n    for(size_t i = 0; i < sz; i++) {\n      if(comp[i]\
    \ == comp[rev(i)]) return {};\n      ret[i] = comp[i] > comp[rev(i)];\n    }\n\
    \    return ret;\n  }\n};\n"
  code: "#pragma once\n\n#include \"../connected-components/strongly-connected-components.hpp\"\
    \n\n/**\n * @brief 2-SAT\n * @docs docs/two-satisfiability.md\n */\nstruct TwoSatisfiability\
    \ : StronglyConnectedComponents< bool > {\npublic:\n  using StronglyConnectedComponents<\
    \ bool >::g;\n  using StronglyConnectedComponents< bool >::comp;\n  using StronglyConnectedComponents<\
    \ bool >::add_edge;\n  size_t sz;\n\n  explicit TwoSatisfiability(size_t v) :\
    \ StronglyConnectedComponents< bool >(v + v), sz(v) {}\n\n  void add_if(int u,\
    \ int v) {\n    // u -> v <=> !v -> !u\n    add_directed_edge(u, v);\n    add_directed_edge(rev(v),\
    \ rev(u));\n  }\n\n  void add_or(int u, int v) {\n    // u or v <=> !u -> v\n\
    \    add_if(rev(u), v);\n  }\n\n  void add_nand(int u, int v) {\n    // u nand\
    \ v <=> u -> !v\n    add_if(u, rev(v));\n  }\n\n  void set_true(int u) {\n   \
    \ // u <=> !u -> u\n    add_directed_edge(rev(u), u);\n  }\n\n  void set_false(int\
    \ u) {\n    // !u <=> u -> !u\n    add_directed_edge(u, rev(u));\n  }\n\n  inline\
    \ int rev(int x) {\n    if(x >= (int)sz) return x - sz;\n    return x + sz;\n\
    \  }\n\n  vector< int > solve() {\n    StronglyConnectedComponents< bool >::build();\n\
    \    vector< int > ret(sz);\n    for(size_t i = 0; i < sz; i++) {\n      if(comp[i]\
    \ == comp[rev(i)]) return {};\n      ret[i] = comp[i] > comp[rev(i)];\n    }\n\
    \    return ret;\n  }\n};\n"
  dependsOn:
  - graph/connected-components/strongly-connected-components.hpp
  - graph/graph-template.hpp
  isVerificationFile: false
  path: graph/others/two-satisfiability.hpp
  requiredBy: []
  timestamp: '2021-07-18 20:06:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/yosupo-two-sat.test.cpp
documentation_of: graph/others/two-satisfiability.hpp
layout: document
redirect_from:
- /library/graph/others/two-satisfiability.hpp
- /library/graph/others/two-satisfiability.hpp.html
title: 2-SAT
---
## 概要

SAT(充足可能性問題) とは, いくつかの論理変数及びその否定からなる論理式が与えられたときに, 各変数に `true` または `false` を割り当てることによって論理式を `true` にできるかを判定する問題である.

次のような形の論理式を乗法標準形とよぶ.

$(a \lor b \lor \dots) \land (c \lor d \lor \dots) \land \dots$

$a, b, \cdots$ をリテラルと呼び, 論理変数かその否定が入る. $(a \lor b \lor \dots)$ のように $\land$ で繋がれた部分をクロージャと呼び, 全てのクロージャ内のリテラル数が高々 $2$ である乗法標準形の論理式に対する SAT を 2-SAT と呼ぶ.

クロージャ ($a \lor b)$ を $\Rightarrow$ (含意) を用いて $(\lnot a \Rightarrow b \land \lnot b \Rightarrow a)$ に変換する. すると乗法標準形は $(a \Rightarrow b) \land (c \Rightarrow d) \land \dots$ のようにすべて $\land$ で結ばれた論理式で表すことができる. ここで $x$ と $\lnot x$ に対応する頂点をつくって, $\Rightarrow$ を辺とした有向グラフを作成する。このグラフを強連結成分分解して $x$ と $\lnot x$ が同じ強連結成分に含まれるものが存在するとき充足不能, 逆に存在しないときは $x$ の強連結成分のトポロジカル順序が $\lnot x$ を含む強連結成分より後ろかどうかを真偽値として充足可能となる解を求めることが出来る.

## 使い方

* `TwoSatisfiability(N)`: `N` 個のリテラルで初期化する.
* `add_if(u, v)`: 条件 `u` ならば `v` を追加する.
* `add_or(u, v)`: 条件 `u` または `v` が `true` を追加する.
* `add_nand(u, v)`: 条件 `u` または `v` が `false` を追加する.
* `set_true(u)`: 条件 `u` が `true` を追加する.
* `set_false(u)`: 条件 `u` が `false` を追加する.
* `rev(u)`: 変数 `u` の否定を返す.
* `solve()`: 充足可能か判定し, 可能なら各変数の割り当ての例を格納した配列, 不能なら空配列を返す.

## 計算量

$O(V+E)$