---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-0275.test.cpp
    title: test/verify/aoj-0275.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Topological-Sort(\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\
      \u30C8)"
    links: []
  bundledCode: "#line 1 \"graph/others/topological-sort.cpp\"\n/**\n * @brief Topological-Sort(\u30C8\
    \u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8)\n */\ntemplate< typename T >\n\
    vector< int > topological_sort(const Graph< T > &g) {\n  const int N = (int) g.size();\n\
    \  vector< int > deg(N);\n  for(int i = 0; i < N; i++) {\n    for(auto &to : g.g[i])\
    \ ++deg[to];\n  }\n  stack< int > st;\n  for(int i = 0; i < N; i++) {\n    if(deg[i]\
    \ == 0) st.emplace(i);\n  }\n  vector< int > ord;\n  while(!st.empty()) {\n  \
    \  auto p = st.top();\n    st.pop();\n    ord.emplace_back(p);\n    for(auto &to\
    \ : g.g[p]) {\n      if(--deg[to] == 0) st.emplace(to);\n    }\n  }\n  return\
    \ ord;\n}\n"
  code: "/**\n * @brief Topological-Sort(\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\
    \u30FC\u30C8)\n */\ntemplate< typename T >\nvector< int > topological_sort(const\
    \ Graph< T > &g) {\n  const int N = (int) g.size();\n  vector< int > deg(N);\n\
    \  for(int i = 0; i < N; i++) {\n    for(auto &to : g.g[i]) ++deg[to];\n  }\n\
    \  stack< int > st;\n  for(int i = 0; i < N; i++) {\n    if(deg[i] == 0) st.emplace(i);\n\
    \  }\n  vector< int > ord;\n  while(!st.empty()) {\n    auto p = st.top();\n \
    \   st.pop();\n    ord.emplace_back(p);\n    for(auto &to : g.g[p]) {\n      if(--deg[to]\
    \ == 0) st.emplace(to);\n    }\n  }\n  return ord;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/others/topological-sort.cpp
  requiredBy: []
  timestamp: '2020-03-26 01:02:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/aoj-0275.test.cpp
documentation_of: graph/others/topological-sort.cpp
layout: document
redirect_from:
- /library/graph/others/topological-sort.cpp
- /library/graph/others/topological-sort.cpp.html
title: "Topological-Sort(\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8)"
---