---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/connected-components/incremental-bridge-connectivity.cpp
    title: Incremental-Bridge-Connectivity
  - icon: ':heavy_check_mark:'
    path: graph/connected-components/three-edge-connected-components.cpp
    title: "Three-Edge-Connected-Components(\u4E09\u91CD\u8FBA\u9023\u7D50\u6210\u5206\
      \u5206\u89E3)"
  - icon: ':heavy_check_mark:'
    path: graph/mst/boruvka.cpp
    title: "Boruvka(\u6700\u5C0F\u5168\u57DF\u6728)"
  - icon: ':heavy_check_mark:'
    path: graph/mst/kruskal.cpp
    title: "Kruskal(\u6700\u5C0F\u5168\u57DF\u6728)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-2821.test.cpp
    title: test/verify/aoj-2821.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-3139.test.cpp
    title: test/verify/aoj-3139.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-dsl-1-a.test.cpp
    title: test/verify/aoj-dsl-1-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-grl-2-a-2.test.cpp
    title: test/verify/aoj-grl-2-a-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-grl-2-a-3.test.cpp
    title: test/verify/aoj-grl-2-a-3.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-grl-2-b.test.cpp
    title: test/verify/aoj-grl-2-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-bipartite-edge-coloring.test.cpp
    title: test/verify/yosupo-bipartite-edge-coloring.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-three-edge-connected-components.test.cpp
    title: test/verify/yosupo-three-edge-connected-components.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-tree-decomposition-width-2.test.cpp
    title: test/verify/yosupo-tree-decomposition-width-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-two-edge-connected-components-2.test.cpp
    title: test/verify/yosupo-two-edge-connected-components-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yukicoder-583.test.cpp
    title: test/verify/yukicoder-583.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/union-find.md
    document_title: Union-Find
    links: []
  bundledCode: "#line 1 \"structure/union-find/union-find.cpp\"\n/**\n * @brief Union-Find\n\
    \ * @docs docs/union-find.md\n */\nstruct UnionFind {\n  vector< int > data;\n\
    \n  UnionFind() = default;\n\n  explicit UnionFind(size_t sz) : data(sz, -1) {}\n\
    \n  bool unite(int x, int y) {\n    x = find(x), y = find(y);\n    if(x == y)\
    \ return false;\n    if(data[x] > data[y]) swap(x, y);\n    data[x] += data[y];\n\
    \    data[y] = x;\n    return true;\n  }\n\n  int find(int k) {\n    if(data[k]\
    \ < 0) return (k);\n    return data[k] = find(data[k]);\n  }\n\n  int size(int\
    \ k) {\n    return -data[find(k)];\n  }\n\n  bool same(int x, int y) {\n    return\
    \ find(x) == find(y);\n  }\n};\n"
  code: "/**\n * @brief Union-Find\n * @docs docs/union-find.md\n */\nstruct UnionFind\
    \ {\n  vector< int > data;\n\n  UnionFind() = default;\n\n  explicit UnionFind(size_t\
    \ sz) : data(sz, -1) {}\n\n  bool unite(int x, int y) {\n    x = find(x), y =\
    \ find(y);\n    if(x == y) return false;\n    if(data[x] > data[y]) swap(x, y);\n\
    \    data[x] += data[y];\n    data[y] = x;\n    return true;\n  }\n\n  int find(int\
    \ k) {\n    if(data[k] < 0) return (k);\n    return data[k] = find(data[k]);\n\
    \  }\n\n  int size(int k) {\n    return -data[find(k)];\n  }\n\n  bool same(int\
    \ x, int y) {\n    return find(x) == find(y);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/union-find/union-find.cpp
  requiredBy:
  - graph/mst/boruvka.cpp
  - graph/mst/kruskal.cpp
  - graph/connected-components/incremental-bridge-connectivity.cpp
  - graph/connected-components/three-edge-connected-components.cpp
  timestamp: '2020-02-19 21:42:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/aoj-grl-2-a-2.test.cpp
  - test/verify/yosupo-two-edge-connected-components-2.test.cpp
  - test/verify/aoj-dsl-1-a.test.cpp
  - test/verify/yukicoder-583.test.cpp
  - test/verify/yosupo-bipartite-edge-coloring.test.cpp
  - test/verify/yosupo-three-edge-connected-components.test.cpp
  - test/verify/aoj-grl-2-b.test.cpp
  - test/verify/aoj-3139.test.cpp
  - test/verify/yosupo-tree-decomposition-width-2.test.cpp
  - test/verify/aoj-2821.test.cpp
  - test/verify/aoj-grl-2-a-3.test.cpp
documentation_of: structure/union-find/union-find.cpp
layout: document
redirect_from:
- /library/structure/union-find/union-find.cpp
- /library/structure/union-find/union-find.cpp.html
title: Union-Find
---
## 概要

集合を高速に扱うためのデータ構造. 集合を合併する操作(unite), ある要素がどの集合に属しているか(find) を問い合わせる操作を行うことが出来る.

* `unite(x, y)`: 集合 `x` と `y` を併合する. 併合済のとき `false`, 未併合のとき `true` が返される.
* `find(k)`: 要素 `k` が属する集合を求める.
* `size(k)`: 要素 `k` が属する集合の要素の数を求める.
* `same(x, y)`: 要素 `x`, `y` が同じ集合に属するか判定する.

## 計算量

* クエリ: ならし $O(\alpha(N))$ ($\alpha$ はアッカーマンの逆関数) 