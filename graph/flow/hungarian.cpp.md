---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/matrix/matrix.cpp
    title: math/matrix/matrix.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-1163.test.cpp
    title: test/verify/aoj-1163.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-assignment.test.cpp
    title: test/verify/yosupo-assignment.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Hungarian(\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5C0F\u91CD\
      \u307F\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0)"
    links: []
  bundledCode: "#line 1 \"math/matrix/matrix.cpp\"\ntemplate< class T >\nstruct Matrix\
    \ {\n  vector< vector< T > > A;\n\n  Matrix() {}\n\n  Matrix(size_t n, size_t\
    \ m) : A(n, vector< T >(m, 0)) {}\n\n  Matrix(size_t n) : A(n, vector< T >(n,\
    \ 0)) {};\n\n  size_t height() const {\n    return (A.size());\n  }\n\n  size_t\
    \ width() const {\n    return (A[0].size());\n  }\n\n  inline const vector< T\
    \ > &operator[](int k) const {\n    return (A.at(k));\n  }\n\n  inline vector<\
    \ T > &operator[](int k) {\n    return (A.at(k));\n  }\n\n  static Matrix I(size_t\
    \ n) {\n    Matrix mat(n);\n    for(int i = 0; i < n; i++) mat[i][i] = 1;\n  \
    \  return (mat);\n  }\n\n  Matrix &operator+=(const Matrix &B) {\n    size_t n\
    \ = height(), m = width();\n    assert(n == B.height() && m == B.width());\n \
    \   for(int i = 0; i < n; i++)\n      for(int j = 0; j < m; j++)\n        (*this)[i][j]\
    \ += B[i][j];\n    return (*this);\n  }\n\n  Matrix &operator-=(const Matrix &B)\
    \ {\n    size_t n = height(), m = width();\n    assert(n == B.height() && m ==\
    \ B.width());\n    for(int i = 0; i < n; i++)\n      for(int j = 0; j < m; j++)\n\
    \        (*this)[i][j] -= B[i][j];\n    return (*this);\n  }\n\n  Matrix &operator*=(const\
    \ Matrix &B) {\n    size_t n = height(), m = B.width(), p = width();\n    assert(p\
    \ == B.height());\n    vector< vector< T > > C(n, vector< T >(m, 0));\n    for(int\
    \ i = 0; i < n; i++)\n      for(int j = 0; j < m; j++)\n        for(int k = 0;\
    \ k < p; k++)\n          C[i][j] = (C[i][j] + (*this)[i][k] * B[k][j]);\n    A.swap(C);\n\
    \    return (*this);\n  }\n\n  Matrix &operator^=(long long k) {\n    Matrix B\
    \ = Matrix::I(height());\n    while(k > 0) {\n      if(k & 1) B *= *this;\n  \
    \    *this *= *this;\n      k >>= 1LL;\n    }\n    A.swap(B.A);\n    return (*this);\n\
    \  }\n\n  Matrix operator+(const Matrix &B) const {\n    return (Matrix(*this)\
    \ += B);\n  }\n\n  Matrix operator-(const Matrix &B) const {\n    return (Matrix(*this)\
    \ -= B);\n  }\n\n  Matrix operator*(const Matrix &B) const {\n    return (Matrix(*this)\
    \ *= B);\n  }\n\n  Matrix operator^(const long long k) const {\n    return (Matrix(*this)\
    \ ^= k);\n  }\n\n  friend ostream &operator<<(ostream &os, Matrix &p) {\n    size_t\
    \ n = p.height(), m = p.width();\n    for(int i = 0; i < n; i++) {\n      os <<\
    \ \"[\";\n      for(int j = 0; j < m; j++) {\n        os << p[i][j] << (j + 1\
    \ == m ? \"]\\n\" : \",\");\n      }\n    }\n    return (os);\n  }\n\n\n  T determinant()\
    \ {\n    Matrix B(*this);\n    assert(width() == height());\n    T ret = 1;\n\
    \    for(int i = 0; i < width(); i++) {\n      int idx = -1;\n      for(int j\
    \ = i; j < width(); j++) {\n        if(B[j][i] != 0) idx = j;\n      }\n     \
    \ if(idx == -1) return (0);\n      if(i != idx) {\n        ret *= -1;\n      \
    \  swap(B[i], B[idx]);\n      }\n      ret *= B[i][i];\n      T vv = B[i][i];\n\
    \      for(int j = 0; j < width(); j++) {\n        B[i][j] /= vv;\n      }\n \
    \     for(int j = i + 1; j < width(); j++) {\n        T a = B[j][i];\n       \
    \ for(int k = 0; k < width(); k++) {\n          B[j][k] -= B[i][k] * a;\n    \
    \    }\n      }\n    }\n    return (ret);\n  }\n};\n#line 2 \"graph/flow/hungarian.cpp\"\
    \n\n/**\n * @brief Hungarian(\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5C0F\u91CD\
    \u307F\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0)\n */\ntemplate< typename T >\n\
    pair< T, vector< int > > hungarian(Matrix< T > &A) {\n  const T infty = numeric_limits<\
    \ T >::max();\n  const int N = (int) A.height();\n  const int M = (int) A.width();\n\
    \  vector< int > P(M), way(M);\n  vector< T > U(N, 0), V(M, 0), minV;\n  vector<\
    \ bool > used;\n\n  for(int i = 1; i < N; i++) {\n    P[0] = i;\n    minV.assign(M,\
    \ infty);\n    used.assign(M, false);\n    int j0 = 0;\n    while(P[j0] != 0)\
    \ {\n      int i0 = P[j0], j1 = 0;\n      used[j0] = true;\n      T delta = infty;\n\
    \      for(int j = 1; j < M; j++) {\n        if(used[j]) continue;\n        T\
    \ curr = A[i0][j] - U[i0] - V[j];\n        if(curr < minV[j]) minV[j] = curr,\
    \ way[j] = j0;\n        if(minV[j] < delta) delta = minV[j], j1 = j;\n      }\n\
    \      for(int j = 0; j < M; j++) {\n        if(used[j]) U[P[j]] += delta, V[j]\
    \ -= delta;\n        else minV[j] -= delta;\n      }\n      j0 = j1;\n    }\n\
    \    do {\n      P[j0] = P[way[j0]];\n      j0 = way[j0];\n    } while(j0 != 0);\n\
    \  }\n  return {-V[0], P};\n}\n"
  code: "#include \"../../math/matrix/matrix.cpp\"\n\n/**\n * @brief Hungarian(\u4E8C\
    \u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5C0F\u91CD\u307F\u6700\u5927\u30DE\u30C3\
    \u30C1\u30F3\u30B0)\n */\ntemplate< typename T >\npair< T, vector< int > > hungarian(Matrix<\
    \ T > &A) {\n  const T infty = numeric_limits< T >::max();\n  const int N = (int)\
    \ A.height();\n  const int M = (int) A.width();\n  vector< int > P(M), way(M);\n\
    \  vector< T > U(N, 0), V(M, 0), minV;\n  vector< bool > used;\n\n  for(int i\
    \ = 1; i < N; i++) {\n    P[0] = i;\n    minV.assign(M, infty);\n    used.assign(M,\
    \ false);\n    int j0 = 0;\n    while(P[j0] != 0) {\n      int i0 = P[j0], j1\
    \ = 0;\n      used[j0] = true;\n      T delta = infty;\n      for(int j = 1; j\
    \ < M; j++) {\n        if(used[j]) continue;\n        T curr = A[i0][j] - U[i0]\
    \ - V[j];\n        if(curr < minV[j]) minV[j] = curr, way[j] = j0;\n        if(minV[j]\
    \ < delta) delta = minV[j], j1 = j;\n      }\n      for(int j = 0; j < M; j++)\
    \ {\n        if(used[j]) U[P[j]] += delta, V[j] -= delta;\n        else minV[j]\
    \ -= delta;\n      }\n      j0 = j1;\n    }\n    do {\n      P[j0] = P[way[j0]];\n\
    \      j0 = way[j0];\n    } while(j0 != 0);\n  }\n  return {-V[0], P};\n}\n"
  dependsOn:
  - math/matrix/matrix.cpp
  isVerificationFile: false
  path: graph/flow/hungarian.cpp
  requiredBy: []
  timestamp: '2020-12-16 21:17:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/aoj-1163.test.cpp
  - test/verify/yosupo-assignment.test.cpp
documentation_of: graph/flow/hungarian.cpp
layout: document
redirect_from:
- /library/graph/flow/hungarian.cpp
- /library/graph/flow/hungarian.cpp.html
title: "Hungarian(\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5C0F\u91CD\u307F\u6700\
  \u5927\u30DE\u30C3\u30C1\u30F3\u30B0)"
---