---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-0275.test.cpp
    title: test/verify/aoj-0275.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/topological-sort.md
    document_title: "Topological-Sort(\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\
      \u30C8)"
    links: []
  bundledCode: "#line 2 \"graph/others/topological-sort.hpp\"\n\n#line 2 \"graph/graph-template.hpp\"\
    \n\ntemplate< typename T = int >\nstruct Edge {\n  int from, to;\n  T cost;\n\
    \  int idx;\n\n  Edge() = default;\n\n  Edge(int from, int to, T cost = 1, int\
    \ idx = -1) : from(from), to(to), cost(cost), idx(idx) {}\n\n  operator int()\
    \ const { return to; }\n};\n\ntemplate< typename T = int >\nstruct Graph {\n \
    \ vector< vector< Edge< T > > > g;\n  int es;\n\n  Graph() = default;\n\n  explicit\
    \ Graph(int n) : g(n), es(0) {}\n\n  size_t size() const {\n    return g.size();\n\
    \  }\n\n  void add_directed_edge(int from, int to, T cost = 1) {\n    g[from].emplace_back(from,\
    \ to, cost, es++);\n  }\n\n  void add_edge(int from, int to, T cost = 1) {\n \
    \   g[from].emplace_back(from, to, cost, es);\n    g[to].emplace_back(to, from,\
    \ cost, es++);\n  }\n\n  void read(int M, int padding = -1, bool weighted = false,\
    \ bool directed = false) {\n    for(int i = 0; i < M; i++) {\n      int a, b;\n\
    \      cin >> a >> b;\n      a += padding;\n      b += padding;\n      T c = T(1);\n\
    \      if(weighted) cin >> c;\n      if(directed) add_directed_edge(a, b, c);\n\
    \      else add_edge(a, b, c);\n    }\n  }\n};\n\ntemplate< typename T = int >\n\
    using Edges = vector< Edge< T > >;\n#line 4 \"graph/others/topological-sort.hpp\"\
    \n\n/**\n * @brief Topological-Sort(\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\
    \u30FC\u30C8)\n * @docs docs/topological-sort.md\n */\ntemplate< typename T >\n\
    vector< int > topological_sort(const Graph< T > &g) {\n  const int N = (int) g.size();\n\
    \  vector< int > deg(N);\n  for(int i = 0; i < N; i++) {\n    for(auto &to : g.g[i])\
    \ ++deg[to];\n  }\n  stack< int > st;\n  for(int i = 0; i < N; i++) {\n    if(deg[i]\
    \ == 0) st.emplace(i);\n  }\n  vector< int > ord;\n  while(!st.empty()) {\n  \
    \  auto p = st.top();\n    st.pop();\n    ord.emplace_back(p);\n    for(auto &to\
    \ : g.g[p]) {\n      if(--deg[to] == 0) st.emplace(to);\n    }\n  }\n  return\
    \ ord;\n}\n"
  code: "#pragma once\n\n#include \"../graph-template.hpp\"\n\n/**\n * @brief Topological-Sort(\u30C8\
    \u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8)\n * @docs docs/topological-sort.md\n\
    \ */\ntemplate< typename T >\nvector< int > topological_sort(const Graph< T >\
    \ &g) {\n  const int N = (int) g.size();\n  vector< int > deg(N);\n  for(int i\
    \ = 0; i < N; i++) {\n    for(auto &to : g.g[i]) ++deg[to];\n  }\n  stack< int\
    \ > st;\n  for(int i = 0; i < N; i++) {\n    if(deg[i] == 0) st.emplace(i);\n\
    \  }\n  vector< int > ord;\n  while(!st.empty()) {\n    auto p = st.top();\n \
    \   st.pop();\n    ord.emplace_back(p);\n    for(auto &to : g.g[p]) {\n      if(--deg[to]\
    \ == 0) st.emplace(to);\n    }\n  }\n  return ord;\n}\n"
  dependsOn:
  - graph/graph-template.hpp
  isVerificationFile: false
  path: graph/others/topological-sort.hpp
  requiredBy: []
  timestamp: '2021-07-01 02:53:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/aoj-0275.test.cpp
documentation_of: graph/others/topological-sort.hpp
layout: document
redirect_from:
- /library/graph/others/topological-sort.hpp
- /library/graph/others/topological-sort.hpp.html
title: "Topological-Sort(\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8)"
---
## 概要

DAG(閉路のない有向グラフ) が与えられたとき, トポロジカルソートする.

入次数 $0$ の頂点から消すことを繰り返す.

## 使い方

* `topological_sort(g)`: DAG `g` をトポロジカルソートして, その頂点の順序を返す.

## 計算量

$O(E + V)$