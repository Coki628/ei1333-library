---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-dsl-2-b.test.cpp
    title: test/verify/aoj-dsl-2-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-point-add-rectangle-sum.test.cpp
    title: test/verify/yosupo-point-add-rectangle-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-static-range-inversions-query.test.cpp
    title: test/verify/yosupo-static-range-inversions-query.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/binary-indexed-tree.md
    document_title: Binary-Indexed-Tree(BIT)
    links: []
  bundledCode: "#line 1 \"structure/others/binary-indexed-tree.cpp\"\n/**\n * @brief\
    \ Binary-Indexed-Tree(BIT)\n * @docs docs/binary-indexed-tree.md\n */\ntemplate<\
    \ typename T >\nstruct BinaryIndexedTree {\n  vector< T > data;\n\n  BinaryIndexedTree()\
    \ = default;\n\n  explicit BinaryIndexedTree(size_t sz) : data(sz + 1, 0) {}\n\
    \n  explicit BinaryIndexedTree(const vector< T > &vs) : data(vs.size() + 1, 0)\
    \ {\n    for(size_t i = 0; i < vs.size(); i++) data[i + 1] = vs[i];\n    for(size_t\
    \ i = 1; i < data.size(); i++) {\n      size_t j = i + (i & -i);\n      if(j <\
    \ data.size()) data[j] += data[i];\n    }\n  }\n\n  void add(int k, const T &x)\
    \ {\n    for(++k; k < (int) data.size(); k += k & -k) data[k] += x;\n  }\n\n \
    \ T query(int k) const {\n    T ret = T();\n    for(++k; k > 0; k -= k & -k) ret\
    \ += data[k];\n    return ret;\n  }\n\n  int lower_bound(T x) const {\n    int\
    \ i = 0;\n    for(int k = 1 << (__lg(data.size() - 1) + 1); k > 0; k >>= 1) {\n\
    \      if(i + k < data.size() && data[i + k] < x) {\n        x -= data[i + k];\n\
    \        i += k;\n      }\n    }\n    return i;\n  }\n\n  int upper_bound(T x)\
    \ const {\n    int i = 0;\n    for(int k = 1 << (__lg(data.size() - 1) + 1); k\
    \ > 0; k >>= 1) {\n      if(i + k < data.size() && data[i + k] <= x) {\n     \
    \   x -= data[i + k];\n        i += k;\n      }\n    }\n    return i;\n  }\n};\n"
  code: "/**\n * @brief Binary-Indexed-Tree(BIT)\n * @docs docs/binary-indexed-tree.md\n\
    \ */\ntemplate< typename T >\nstruct BinaryIndexedTree {\n  vector< T > data;\n\
    \n  BinaryIndexedTree() = default;\n\n  explicit BinaryIndexedTree(size_t sz)\
    \ : data(sz + 1, 0) {}\n\n  explicit BinaryIndexedTree(const vector< T > &vs)\
    \ : data(vs.size() + 1, 0) {\n    for(size_t i = 0; i < vs.size(); i++) data[i\
    \ + 1] = vs[i];\n    for(size_t i = 1; i < data.size(); i++) {\n      size_t j\
    \ = i + (i & -i);\n      if(j < data.size()) data[j] += data[i];\n    }\n  }\n\
    \n  void add(int k, const T &x) {\n    for(++k; k < (int) data.size(); k += k\
    \ & -k) data[k] += x;\n  }\n\n  T query(int k) const {\n    T ret = T();\n   \
    \ for(++k; k > 0; k -= k & -k) ret += data[k];\n    return ret;\n  }\n\n  int\
    \ lower_bound(T x) const {\n    int i = 0;\n    for(int k = 1 << (__lg(data.size()\
    \ - 1) + 1); k > 0; k >>= 1) {\n      if(i + k < data.size() && data[i + k] <\
    \ x) {\n        x -= data[i + k];\n        i += k;\n      }\n    }\n    return\
    \ i;\n  }\n\n  int upper_bound(T x) const {\n    int i = 0;\n    for(int k = 1\
    \ << (__lg(data.size() - 1) + 1); k > 0; k >>= 1) {\n      if(i + k < data.size()\
    \ && data[i + k] <= x) {\n        x -= data[i + k];\n        i += k;\n      }\n\
    \    }\n    return i;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/others/binary-indexed-tree.cpp
  requiredBy: []
  timestamp: '2020-06-17 14:51:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/aoj-dsl-2-b.test.cpp
  - test/verify/yosupo-static-range-inversions-query.test.cpp
  - test/verify/yosupo-point-add-rectangle-sum.test.cpp
documentation_of: structure/others/binary-indexed-tree.cpp
layout: document
redirect_from:
- /library/structure/others/binary-indexed-tree.cpp
- /library/structure/others/binary-indexed-tree.cpp.html
title: Binary-Indexed-Tree(BIT)
---
## 概要

Fenwick Tree とも呼ばれる. 数列に対し, ある要素に値を加える操作と, 区間和を求める操作をそれぞれ対数時間で行うことが出来るデータ構造. セグメント木や平衡二分探索
木の機能を制限したものであるが, 実装が非常に単純で定数倍も軽いなどの利点がある.

* `BinaryIndexedTree(sz)`: 長さ `sz` の $0$ で初期化された配列で構築する.
* `BinaryIndexedTree(vs)`: 配列 `vs` で構築する.
* `add(k, x)`: 要素 `k` に値 `x` を加える.
* `query(k)`: 区間 $[0,k]$ の総和を求める(閉区間なので注意すること).
* `lower_bound(x)`: 区間 $[0,k]$ の総和が `x` 以上となる最小の $k$ を返す.
* `upper_bound(x)`: 区間 $[0,k]$ の総和が `x` を上回る最小の $k$ を返す.

## 計算量

* 構築: $O(N)$
* クエリ: $O(\log N)$