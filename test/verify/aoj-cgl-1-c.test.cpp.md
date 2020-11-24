---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geometry/base.cpp
    title: geometry/base.cpp
  - icon: ':heavy_check_mark:'
    path: geometry/ccw.cpp
    title: geometry/ccw.cpp
  - icon: ':question:'
    path: geometry/point.cpp
    title: geometry/point.cpp
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C
  bundledCode: "#line 1 \"test/verify/aoj-cgl-1-c.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C\"\
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
    \ MFP(F &&f) {\n  return FixPoint< F >{forward< F >(f)};\n}\n#line 4 \"test/verify/aoj-cgl-1-c.test.cpp\"\
    \n\n#line 2 \"geometry/base.cpp\"\n\nnamespace geometry {\n  using Real = double;\n\
    \  const Real EPS = 1e-8;\n  const Real PI = acos(static_cast< Real >(-1));\n\n\
    \  inline int sign(const Real &r) {\n    return r <= -EPS ? -1 : r >= EPS ? 1\
    \ : 0;\n  }\n\n  inline bool equals(const Real &a, const Real &b) {\n    return\
    \ sign(a - b) == 0;\n  }\n}\n#line 3 \"geometry/point.cpp\"\n\nnamespace geometry\
    \ {\n  using Point = complex< Real >;\n\n  istream &operator>>(istream &is, Point\
    \ &p) {\n    Real a, b;\n    is >> a >> b;\n    p = Point(a, b);\n    return is;\n\
    \  }\n\n  ostream &operator<<(ostream &os, const Point &p) {\n    return os <<\
    \ real(p) << \" \" << imag(p);\n  }\n\n  Point operator*(const Point &p, const\
    \ Real &d) {\n    return Point(real(p) * d, imag(p) * d);\n  }\n\n  // rotate\
    \ point p counterclockwise by theta rad\n  Point rotate(Real theta, const Point\
    \ &p) {\n    return Point(cos(theta) * real(p) - sin(theta) * imag(p), sin(theta)\
    \ * real(p) + cos(theta) * imag(p));\n  }\n\n  Real cross(const Point &a, const\
    \ Point &b) {\n    return real(a) * imag(b) - imag(a) * real(b);\n  }\n\n  Real\
    \ dot(const Point &a, const Point &b) {\n    return real(a) * real(b) + imag(a)\
    \ * imag(b);\n  }\n\n  using Points = vector< Point >;\n}\n#line 2 \"geometry/ccw.cpp\"\
    \n\nnamespace geometry {\n  // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C\n\
    \  int ccw(const Point &a, Point b, Point c) {\n    b = b - a, c = c - a;\n  \
    \  if(sign(cross(b, c)) == +1) return +1; // \"COUNTER_CLOCKWISE\"\n    if(sign(cross(b,\
    \ c)) == -1) return -1; // \"CLOCKWISE\"\n    if(sign(dot(b, c)) == -1) return\
    \ +2;   // \"ONLINE_BACK\" c-a-b\n    if(norm(b) < norm(c)) return -2;       //\
    \ \"ONLINE_FRONT\" a-b-c\n    return 0;                              // \"ON_SEGMENT\"\
    \ a-c-b\n  }\n}\n#line 6 \"test/verify/aoj-cgl-1-c.test.cpp\"\n\nusing namespace\
    \ geometry;\n\nint main() {\n  Point p1, p2;\n  cin >> p1 >> p2;\n  int Q;\n \
    \ cin >> Q;\n  while(Q--) {\n    Point p3;\n    cin >> p3;\n    auto t = ccw(p1,\
    \ p2, p3);\n    if(t == 1) cout << \"COUNTER_CLOCKWISE\\n\";\n    else if(t ==\
    \ -1) cout << \"CLOCKWISE\\n\";\n    else if(t == 2) cout << \"ONLINE_BACK\\n\"\
    ;\n    else if(t == -2) cout << \"ONLINE_FRONT\\n\";\n    else cout << \"ON_SEGMENT\\\
    n\";\n  }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C\"\
    \n\n#include \"../../template/template.cpp\"\n\n#include \"../../geometry/ccw.cpp\"\
    \n\nusing namespace geometry;\n\nint main() {\n  Point p1, p2;\n  cin >> p1 >>\
    \ p2;\n  int Q;\n  cin >> Q;\n  while(Q--) {\n    Point p3;\n    cin >> p3;\n\
    \    auto t = ccw(p1, p2, p3);\n    if(t == 1) cout << \"COUNTER_CLOCKWISE\\n\"\
    ;\n    else if(t == -1) cout << \"CLOCKWISE\\n\";\n    else if(t == 2) cout <<\
    \ \"ONLINE_BACK\\n\";\n    else if(t == -2) cout << \"ONLINE_FRONT\\n\";\n   \
    \ else cout << \"ON_SEGMENT\\n\";\n  }\n}\n"
  dependsOn:
  - template/template.cpp
  - geometry/ccw.cpp
  - geometry/point.cpp
  - geometry/base.cpp
  isVerificationFile: true
  path: test/verify/aoj-cgl-1-c.test.cpp
  requiredBy: []
  timestamp: '2020-11-24 18:23:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/aoj-cgl-1-c.test.cpp
layout: document
redirect_from:
- /verify/test/verify/aoj-cgl-1-c.test.cpp
- /verify/test/verify/aoj-cgl-1-c.test.cpp.html
title: test/verify/aoj-cgl-1-c.test.cpp
---