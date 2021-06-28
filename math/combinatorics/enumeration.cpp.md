---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/combinatorics/bell-number.cpp
    title: "Bell-Number(\u30D9\u30EB\u6570)"
  - icon: ':heavy_check_mark:'
    path: math/combinatorics/stirling-number-second.cpp
    title: "Stirling-Number-Second(\u7B2C2\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\
      \u6570)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-dpl-5-g.test.cpp
    title: test/verify/aoj-dpl-5-g.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-dpl-5-i.test.cpp
    title: test/verify/aoj-dpl-5-i.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/combinatorics/enumeration.cpp\"\ntemplate< typename\
    \ T >\nstruct Enumeration {\nprivate:\n  static vector< T > _fact, _finv, _inv;\n\
    \n  inline static void expand(size_t sz) {\n    if(_fact.size() < sz + 1) {\n\
    \      int pre_sz = max(1, (int) _fact.size());\n      _fact.resize(sz + 1, T(1));\n\
    \      _finv.resize(sz + 1, T(1));\n      _inv.resize(sz + 1, T(1));\n      for(int\
    \ i = pre_sz; i <= (int) sz; i++) {\n        _fact[i] = _fact[i - 1] * T(i);\n\
    \      }\n      _finv[sz] = T(1) / _fact[sz];\n      for(int i = (int) sz - 1;\
    \ i >= pre_sz; i--) {\n        _finv[i] = _finv[i + 1] * T(i + 1);\n      }\n\
    \      for(int i = pre_sz; i <= (int) sz; i++) {\n        _inv[i] = _finv[i] *\
    \ _fact[i - 1];\n      }\n    }\n  }\n\npublic:\n  explicit Enumeration(size_t\
    \ sz = 0) { expand(sz); }\n\n  static inline T fact(int k) {\n    expand(k);\n\
    \    return _fact[k];\n  }\n\n  static inline T finv(int k) {\n    expand(k);\n\
    \    return _finv[k];\n  }\n\n  static inline T inv(int k) {\n    expand(k);\n\
    \    return _inv[k];\n  }\n\n  static T P(int n, int r) {\n    if(r < 0 || n <\
    \ r) return 0;\n    return fact(n) * finv(n - r);\n  }\n\n  static T C(int p,\
    \ int q) {\n    if(q < 0 || p < q) return 0;\n    return fact(p) * finv(q) * finv(p\
    \ - q);\n  }\n\n  static T H(int n, int r) {\n    if(n < 0 || r < 0) return 0;\n\
    \    return r == 0 ? 1 : C(n + r - 1, r);\n  }\n};\n\ntemplate< typename T >\n\
    vector< T > Enumeration< T >::_fact = vector< T >();\ntemplate< typename T >\n\
    vector< T > Enumeration< T >::_finv = vector< T >();\ntemplate< typename T >\n\
    vector< T > Enumeration< T >::_inv = vector< T >();\n"
  code: "template< typename T >\nstruct Enumeration {\nprivate:\n  static vector<\
    \ T > _fact, _finv, _inv;\n\n  inline static void expand(size_t sz) {\n    if(_fact.size()\
    \ < sz + 1) {\n      int pre_sz = max(1, (int) _fact.size());\n      _fact.resize(sz\
    \ + 1, T(1));\n      _finv.resize(sz + 1, T(1));\n      _inv.resize(sz + 1, T(1));\n\
    \      for(int i = pre_sz; i <= (int) sz; i++) {\n        _fact[i] = _fact[i -\
    \ 1] * T(i);\n      }\n      _finv[sz] = T(1) / _fact[sz];\n      for(int i =\
    \ (int) sz - 1; i >= pre_sz; i--) {\n        _finv[i] = _finv[i + 1] * T(i + 1);\n\
    \      }\n      for(int i = pre_sz; i <= (int) sz; i++) {\n        _inv[i] = _finv[i]\
    \ * _fact[i - 1];\n      }\n    }\n  }\n\npublic:\n  explicit Enumeration(size_t\
    \ sz = 0) { expand(sz); }\n\n  static inline T fact(int k) {\n    expand(k);\n\
    \    return _fact[k];\n  }\n\n  static inline T finv(int k) {\n    expand(k);\n\
    \    return _finv[k];\n  }\n\n  static inline T inv(int k) {\n    expand(k);\n\
    \    return _inv[k];\n  }\n\n  static T P(int n, int r) {\n    if(r < 0 || n <\
    \ r) return 0;\n    return fact(n) * finv(n - r);\n  }\n\n  static T C(int p,\
    \ int q) {\n    if(q < 0 || p < q) return 0;\n    return fact(p) * finv(q) * finv(p\
    \ - q);\n  }\n\n  static T H(int n, int r) {\n    if(n < 0 || r < 0) return 0;\n\
    \    return r == 0 ? 1 : C(n + r - 1, r);\n  }\n};\n\ntemplate< typename T >\n\
    vector< T > Enumeration< T >::_fact = vector< T >();\ntemplate< typename T >\n\
    vector< T > Enumeration< T >::_finv = vector< T >();\ntemplate< typename T >\n\
    vector< T > Enumeration< T >::_inv = vector< T >();\n"
  dependsOn: []
  isVerificationFile: false
  path: math/combinatorics/enumeration.cpp
  requiredBy:
  - math/combinatorics/bell-number.cpp
  - math/combinatorics/stirling-number-second.cpp
  timestamp: '2021-06-28 00:13:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/aoj-dpl-5-g.test.cpp
  - test/verify/aoj-dpl-5-i.test.cpp
documentation_of: math/combinatorics/enumeration.cpp
layout: document
redirect_from:
- /library/math/combinatorics/enumeration.cpp
- /library/math/combinatorics/enumeration.cpp.html
title: math/combinatorics/enumeration.cpp
---
