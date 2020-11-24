---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.cpp
    title: graph/graph-template.cpp
  - icon: ':heavy_check_mark:'
    path: graph/tree/pmormq-lowest-common-ancestor.cpp
    title: "PMORMQ-Lowest-Common-Ancestor(\u6700\u5C0F\u5171\u901A\u7956\u5148)"
  - icon: ':heavy_check_mark:'
    path: other/printer.cpp
    title: "Printer(\u9AD8\u901F\u51FA\u529B)"
  - icon: ':heavy_check_mark:'
    path: other/scanner.cpp
    title: "Scanner(\u9AD8\u901F\u5165\u529B)"
  - icon: ':heavy_check_mark:'
    path: structure/others/plus-minus-one-rmq.cpp
    title: Plus-Minus-One-RMQ
  - icon: ':heavy_check_mark:'
    path: structure/others/sparse-table.cpp
    title: "Sparse-Table(\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB)"
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/verify/yosupo-lca.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\
    \n\n#line 1 \"template/template.cpp\"\n#include<bits/stdc++.h>\n\nusing namespace\
    \ std;\n\nusing int64 = long long;\nconst int mod = 1e9 + 7;\n\nconst int64 infll\
    \ = (1LL << 62) - 1;\nconst int inf = (1 << 30) - 1;\n\nstruct IoSetup {\n  IoSetup()\
    \ {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n    cout << fixed\
    \ << setprecision(10);\n    cerr << fixed << setprecision(10);\n  }\n} iosetup;\n\
    \n\ntemplate< typename T1, typename T2 >\nostream &operator<<(ostream &os, const\
    \ pair< T1, T2 >& p) {\n  os << p.first << \" \" << p.second;\n  return os;\n\
    }\n\ntemplate< typename T1, typename T2 >\nistream &operator>>(istream &is, pair<\
    \ T1, T2 > &p) {\n  is >> p.first >> p.second;\n  return is;\n}\n\ntemplate< typename\
    \ T >\nostream &operator<<(ostream &os, const vector< T > &v) {\n  for(int i =\
    \ 0; i < (int) v.size(); i++) {\n    os << v[i] << (i + 1 != v.size() ? \" \"\
    \ : \"\");\n  }\n  return os;\n}\n\ntemplate< typename T >\nistream &operator>>(istream\
    \ &is, vector< T > &v) {\n  for(T &in : v) is >> in;\n  return is;\n}\n\ntemplate<\
    \ typename T1, typename T2 >\ninline bool chmax(T1 &a, T2 b) { return a < b &&\
    \ (a = b, true); }\n\ntemplate< typename T1, typename T2 >\ninline bool chmin(T1\
    \ &a, T2 b) { return a > b && (a = b, true); }\n\ntemplate< typename T = int64\
    \ >\nvector< T > make_v(size_t a) {\n  return vector< T >(a);\n}\n\ntemplate<\
    \ typename T, typename... Ts >\nauto make_v(size_t a, Ts... ts) {\n  return vector<\
    \ decltype(make_v< T >(ts...)) >(a, make_v< T >(ts...));\n}\n\ntemplate< typename\
    \ T, typename V >\ntypename enable_if< is_class< T >::value == 0 >::type fill_v(T\
    \ &t, const V &v) {\n  t = v;\n}\n\ntemplate< typename T, typename V >\ntypename\
    \ enable_if< is_class< T >::value != 0 >::type fill_v(T &t, const V &v) {\n  for(auto\
    \ &e : t) fill_v(e, v);\n}\n\ntemplate< typename F >\nstruct FixPoint : F {\n\
    \  FixPoint(F &&f) : F(forward< F >(f)) {}\n \n  template< typename... Args >\n\
    \  decltype(auto) operator()(Args &&... args) const {\n    return F::operator()(*this,\
    \ forward< Args >(args)...);\n  }\n};\n \ntemplate< typename F >\ninline decltype(auto)\
    \ MFP(F &&f) {\n  return FixPoint< F >{forward< F >(f)};\n}\n#line 4 \"test/verify/yosupo-lca.test.cpp\"\
    \n\n#line 2 \"graph/graph-template.cpp\"\n\ntemplate< typename T = int >\nstruct\
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
    \ntemplate< typename T = int >\nusing Edges = vector< Edge< T > >;\n#line 6 \"\
    test/verify/yosupo-lca.test.cpp\"\n\n#line 1 \"structure/others/sparse-table.cpp\"\
    \n/**\n * @brief Sparse-Table(\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB\
    )\n * @docs docs/sparse-table.md\n */\ntemplate< typename T, typename F >\nstruct\
    \ SparseTable {\n  F f;\n  vector< vector< T > > st;\n  vector< int > lookup;\n\
    \n  SparseTable() = default;\n\n  explicit SparseTable(const vector< T > &v, const\
    \ F &f) : f(f) {\n    const int n = (int) v.size();\n    const int b = 32 - __builtin_clz(n);\n\
    \    st.assign(b, vector< T >(n));\n    for(int i = 0; i < v.size(); i++) {\n\
    \      st[0][i] = v[i];\n    }\n    for(int i = 1; i < b; i++) {\n      for(int\
    \ j = 0; j + (1 << i) <= n; j++) {\n        st[i][j] = f(st[i - 1][j], st[i -\
    \ 1][j + (1 << (i - 1))]);\n      }\n    }\n    lookup.resize(v.size() + 1);\n\
    \    for(int i = 2; i < lookup.size(); i++) {\n      lookup[i] = lookup[i >> 1]\
    \ + 1;\n    }\n  }\n\n  inline T fold(int l, int r) const {\n    int b = lookup[r\
    \ - l];\n    return f(st[b][l], st[b][r - (1 << b)]);\n  }\n};\n\ntemplate< typename\
    \ T, typename F >\nSparseTable< T, F > get_sparse_table(const vector< T > &v,\
    \ const F &f) {\n  return SparseTable< T, F >(v, f);\n}\n#line 2 \"structure/others/plus-minus-one-rmq.cpp\"\
    \n\n/**\n * @brief Plus-Minus-One-RMQ\n **/\ntemplate< typename T >\nstruct PlusMinusOneRMQ\
    \ {\n  using F = function< int(int, int) >;\n\n  int backet;\n  vector< T > vs;\n\
    \  vector< int > bidx, bbit;\n  SparseTable< int, F > st;\n  vector< vector< vector<\
    \ int > > > lookup;\n\n  explicit PlusMinusOneRMQ() = default;\n\n  explicit PlusMinusOneRMQ(const\
    \ vector< T > &vs) : vs(vs) {\n    int n = (int) vs.size();\n    backet = max(1,\
    \ (31 - __builtin_clz(n)) / 2);\n    int sz = (n + backet - 1) / backet;\n   \
    \ bidx.assign(sz, -1);\n    bbit.assign(sz, 0);\n    for(int i = 0; i < sz; i++)\
    \ {\n      int l = i * backet;\n      int r = min(l + backet, n);\n      bidx[i]\
    \ = l;\n      for(int j = l + 1; j < r; j++) {\n        if(vs[j] < vs[bidx[i]])\
    \ bidx[i] = j;\n        if(vs[j - 1] < vs[j]) bbit[i] |= 1 << (j - l - 1);\n \
    \     }\n    }\n    F f = [&](int a, int b) { return vs[a] < vs[b] ? a : b; };\n\
    \    st = get_sparse_table(bidx, f);\n    lookup.assign(1 << (backet - 1), vector<\
    \ vector< int > >(backet, vector< int >(backet + 1)));\n    for(int i = 0; i <\
    \ (1 << (backet - 1)); i++) {\n      for(int j = 0; j < backet; j++) {\n     \
    \   int sum = 0, ret = 0, pos = j;\n        for(int k = j + 1; k <= backet; k++)\
    \ {\n          lookup[i][j][k] = pos;\n          if(i & (1 << (k - 1))) ++sum;\n\
    \          else --sum;\n          if(sum < ret) {\n            pos = k;\n    \
    \        ret = sum;\n          }\n        }\n      }\n    }\n  }\n\n  pair< T,\
    \ int > fold(int l, int r) const {\n    int lb = l / backet;\n    int rb = r /\
    \ backet;\n    if(lb == rb) {\n      int pos = lb * backet + lookup[bbit[lb]][l\
    \ % backet][r % backet];\n      return {vs[pos], pos};\n    }\n    int pos = lb\
    \ * backet + lookup[bbit[lb]][l % backet][backet];\n    if(r % backet > 0) {\n\
    \      int sub = rb * backet + lookup[bbit[rb]][0][r % backet];\n      if(vs[sub]\
    \ < vs[pos]) pos = sub;\n    }\n    if(lb + 1 == rb) {\n      return {vs[pos],\
    \ pos};\n    } else {\n      int sub = st.fold(lb + 1, rb);\n      if(vs[sub]\
    \ < vs[pos]) pos = sub;\n      return {vs[pos], pos};\n    }\n  }\n};\n#line 2\
    \ \"graph/tree/pmormq-lowest-common-ancestor.cpp\"\n\n/**\n * @brief PMORMQ-Lowest-Common-Ancestor(\u6700\
    \u5C0F\u5171\u901A\u7956\u5148)\n * @docs docs/pmormq-lowest-common-ancestor.md\n\
    \ **/\ntemplate< typename T = int >\nstruct PMORMQLowestCommonAncestor : Graph<\
    \ T > {\npublic:\n  using Graph< T >::Graph;\n  using Graph< T >::g;\n  using\
    \ F = function< int(int, int) >;\n\n  void build(int root = 0) {\n    ord.reserve(g.size()\
    \ * 2 - 1);\n    dep.reserve(g.size() * 2 - 1);\n    in.resize(g.size());\n  \
    \  dfs(root, -1, 0);\n    vector< int > vs(g.size() * 2 - 1);\n    iota(begin(vs),\
    \ end(vs), 0);\n    st = PlusMinusOneRMQ< int >(dep);\n  }\n\n  int lca(int x,\
    \ int y) const {\n    if(in[x] > in[y]) swap(x, y);\n    return ord[st.fold(in[x],\
    \ in[y] + 1).second];\n  }\n\nprivate:\n  vector< int > ord, dep, in;\n  PlusMinusOneRMQ<\
    \ int > st;\n\n  void dfs(int idx, int par, int d) {\n    in[idx] = (int) ord.size();\n\
    \    ord.emplace_back(idx);\n    dep.emplace_back(d);\n    for(auto &to : g[idx])\
    \ {\n      if(to != par) {\n        dfs(to, idx, d + 1);\n        ord.emplace_back(idx);\n\
    \        dep.emplace_back(d);\n      }\n    }\n  }\n};\n#line 8 \"test/verify/yosupo-lca.test.cpp\"\
    \n\n#line 1 \"other/scanner.cpp\"\n/**\n * @brief Scanner(\u9AD8\u901F\u5165\u529B\
    )\n */\nstruct Scanner {\npublic:\n\n  explicit Scanner(FILE *fp) : fp(fp) {}\n\
    \n  template< typename T, typename... E >\n  void read(T &t, E &... e) {\n   \
    \ read_single(t);\n    read(e...);\n  }\n\nprivate:\n  static constexpr size_t\
    \ line_size = 1 << 16;\n  static constexpr size_t int_digits = 20;\n  char line[line_size\
    \ + 1] = {};\n  FILE *fp = nullptr;\n  char *st = line;\n  char *ed = line;\n\n\
    \  void read() {}\n\n  static inline bool is_space(char c) {\n    return c <=\
    \ ' ';\n  }\n\n  void reread() {\n    ptrdiff_t len = ed - st;\n    memmove(line,\
    \ st, len);\n    char *tmp = line + len;\n    ed = tmp + fread(tmp, 1, line_size\
    \ - len, fp);\n    *ed = 0;\n    st = line;\n  }\n\n  void skip_space() {\n  \
    \  while(true) {\n      if(st == ed) reread();\n      while(*st && is_space(*st))\
    \ ++st;\n      if(st != ed) return;\n    }\n  }\n\n  template< typename T, enable_if_t<\
    \ is_integral< T >::value, int > = 0 >\n  void read_single(T &s) {\n    skip_space();\n\
    \    if(st + int_digits >= ed) reread();\n    bool neg = false;\n    if(is_signed<\
    \ T >::value && *st == '-') {\n      neg = true;\n      ++st;\n    }\n    typename\
    \ make_unsigned< T >::type y = *st++ - '0';\n    while(*st >= '0') {\n      y\
    \ = 10 * y + *st++ - '0';\n    }\n    s = (neg ? -y : y);\n  }\n\n  template<\
    \ typename T, enable_if_t< is_same< T, string >::value, int > = 0 >\n  void read_single(T\
    \ &s) {\n    s = \"\";\n    skip_space();\n    while(true) {\n      char *base\
    \ = st;\n      while(*st && !is_space(*st)) ++st;\n      s += string(base, st);\n\
    \      if(st != ed) return;\n      reread();\n    }\n  }\n\n  template< typename\
    \ T >\n  void read_single(vector< T > &s) {\n    for(auto &d : s) read(d);\n \
    \ }\n};\n#line 1 \"other/printer.cpp\"\n/**\n * @brief Printer(\u9AD8\u901F\u51FA\
    \u529B)\n */\nstruct Printer {\npublic:\n  explicit Printer(FILE *fp) : fp(fp)\
    \ {}\n\n  ~Printer() { flush(); }\n\n  template< bool f = false, typename T, typename...\
    \ E >\n  void write(const T &t, const E &... e) {\n    if(f) write_single(' ');\n\
    \    write_single(t);\n    write< true >(e...);\n  }\n\n  template< typename...\
    \ T >\n  void writeln(const T &...t) {\n    write(t...);\n    write_single('\\\
    n');\n  }\n\n  void flush() {\n    fwrite(line, 1, st - line, fp);\n    st = line;\n\
    \  }\n\nprivate:\n  FILE *fp = nullptr;\n  static constexpr size_t line_size =\
    \ 1 << 16;\n  static constexpr size_t int_digits = 20;\n  char line[line_size\
    \ + 1] = {};\n  char small[32] = {};\n  char *st = line;\n\n  template< bool f\
    \ = false >\n  void write() {}\n\n  void write_single(const char &t) {\n    if(st\
    \ + 1 >= line + line_size) flush();\n    *st++ = t;\n  }\n\n  template< typename\
    \ T, enable_if_t< is_integral< T >::value, int > = 0 >\n  void write_single(T\
    \ s) {\n    if(st + int_digits >= line + line_size) flush();\n    if(s == 0) {\n\
    \      write_single('0');\n      return;\n    }\n    if(s < 0) {\n      write_single('-');\n\
    \      s = -s;\n    }\n    char *mp = small + sizeof(small);\n    typename make_unsigned<\
    \ T >::type y = s;\n    size_t len = 0;\n    while(y > 0) {\n      *--mp = y %\
    \ 10 + '0';\n      y /= 10;\n      ++len;\n    }\n    memmove(st, mp, len);\n\
    \    st += len;\n  }\n\n  void write_single(const string &s) {\n    for(auto &c\
    \ : s) write_single(c);\n  }\n\n  void write_single(const char *s) {\n    while(*s\
    \ != 0) write_single(*s++);\n  }\n\n  template< typename T >\n  void write_single(const\
    \ vector< T > &s) {\n    for(size_t i = 0; i < s.size(); i++) {\n      if(i) write_single('\
    \ ');\n      write_single(s[i]);\n    }\n  }\n};\n#line 11 \"test/verify/yosupo-lca.test.cpp\"\
    \n\n\nint main() {\n  Scanner in(stdin);\n  Printer out(stdout);\n  int N, Q;\n\
    \  in.read(N, Q);\n  PMORMQLowestCommonAncestor< int > g(N);\n  for(int i = 1;\
    \ i < N; i++) {\n    int x;\n    in.read(x);\n    g.add_directed_edge(x, i);\n\
    \  }\n  g.build();\n  for(int i = 0; i < Q; i++) {\n    int u, v;\n    in.read(u,\
    \ v);\n    out.writeln(g.lca(u, v));\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include \"../../template/template.cpp\"\
    \n\n#include \"../../graph/graph-template.cpp\"\n\n#include \"../../graph/tree/pmormq-lowest-common-ancestor.cpp\"\
    \n\n#include \"../../other/scanner.cpp\"\n#include \"../../other/printer.cpp\"\
    \n\n\nint main() {\n  Scanner in(stdin);\n  Printer out(stdout);\n  int N, Q;\n\
    \  in.read(N, Q);\n  PMORMQLowestCommonAncestor< int > g(N);\n  for(int i = 1;\
    \ i < N; i++) {\n    int x;\n    in.read(x);\n    g.add_directed_edge(x, i);\n\
    \  }\n  g.build();\n  for(int i = 0; i < Q; i++) {\n    int u, v;\n    in.read(u,\
    \ v);\n    out.writeln(g.lca(u, v));\n  }\n}\n"
  dependsOn:
  - template/template.cpp
  - graph/graph-template.cpp
  - graph/tree/pmormq-lowest-common-ancestor.cpp
  - structure/others/plus-minus-one-rmq.cpp
  - structure/others/sparse-table.cpp
  - other/scanner.cpp
  - other/printer.cpp
  isVerificationFile: true
  path: test/verify/yosupo-lca.test.cpp
  requiredBy: []
  timestamp: '2020-11-11 23:28:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/yosupo-lca.test.cpp
layout: document
redirect_from:
- /verify/test/verify/yosupo-lca.test.cpp
- /verify/test/verify/yosupo-lca.test.cpp.html
title: test/verify/yosupo-lca.test.cpp
---