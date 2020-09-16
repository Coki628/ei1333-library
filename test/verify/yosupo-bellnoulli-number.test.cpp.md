---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: template/template.cpp
  - icon: ':heavy_check_mark:'
    path: math/combinatorics/mod-int.cpp
    title: math/combinatorics/mod-int.cpp
  - icon: ':heavy_check_mark:'
    path: math/fft/number-theoretic-transform-friendly-mod-int.cpp
    title: math/fft/number-theoretic-transform-friendly-mod-int.cpp
  - icon: ':heavy_check_mark:'
    path: math/fps/formal-power-series.cpp
    title: math/fps/formal-power-series.cpp
  - icon: ':heavy_check_mark:'
    path: math/fps/formal-power-series-seq.cpp
    title: math/fps/formal-power-series-seq.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bernoulli_number
    links:
    - https://judge.yosupo.jp/problem/bernoulli_number
  bundledCode: "#line 1 \"test/verify/yosupo-bellnoulli-number.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/bernoulli_number\"\n\n#line 1 \"template/template.cpp\"\
    \n#include<bits/stdc++.h>\n\nusing namespace std;\n\nusing int64 = long long;\n\
    const int mod = 1e9 + 7;\n\nconst int64 infll = (1LL << 62) - 1;\nconst int inf\
    \ = (1 << 30) - 1;\n\nstruct IoSetup {\n  IoSetup() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n    cout << fixed << setprecision(10);\n  \
    \  cerr << fixed << setprecision(10);\n  }\n} iosetup;\n\n\ntemplate< typename\
    \ T1, typename T2 >\nostream &operator<<(ostream &os, const pair< T1, T2 >& p)\
    \ {\n  os << p.first << \" \" << p.second;\n  return os;\n}\n\ntemplate< typename\
    \ T1, typename T2 >\nistream &operator>>(istream &is, pair< T1, T2 > &p) {\n \
    \ is >> p.first >> p.second;\n  return is;\n}\n\ntemplate< typename T >\nostream\
    \ &operator<<(ostream &os, const vector< T > &v) {\n  for(int i = 0; i < (int)\
    \ v.size(); i++) {\n    os << v[i] << (i + 1 != v.size() ? \" \" : \"\");\n  }\n\
    \  return os;\n}\n\ntemplate< typename T >\nistream &operator>>(istream &is, vector<\
    \ T > &v) {\n  for(T &in : v) is >> in;\n  return is;\n}\n\ntemplate< typename\
    \ T1, typename T2 >\ninline bool chmax(T1 &a, T2 b) { return a < b && (a = b,\
    \ true); }\n\ntemplate< typename T1, typename T2 >\ninline bool chmin(T1 &a, T2\
    \ b) { return a > b && (a = b, true); }\n\ntemplate< typename T = int64 >\nvector<\
    \ T > make_v(size_t a) {\n  return vector< T >(a);\n}\n\ntemplate< typename T,\
    \ typename... Ts >\nauto make_v(size_t a, Ts... ts) {\n  return vector< decltype(make_v<\
    \ T >(ts...)) >(a, make_v< T >(ts...));\n}\n\ntemplate< typename T, typename V\
    \ >\ntypename enable_if< is_class< T >::value == 0 >::type fill_v(T &t, const\
    \ V &v) {\n  t = v;\n}\n\ntemplate< typename T, typename V >\ntypename enable_if<\
    \ is_class< T >::value != 0 >::type fill_v(T &t, const V &v) {\n  for(auto &e\
    \ : t) fill_v(e, v);\n}\n\ntemplate< typename F >\nstruct FixPoint : F {\n  FixPoint(F\
    \ &&f) : F(forward< F >(f)) {}\n \n  template< typename... Args >\n  decltype(auto)\
    \ operator()(Args &&... args) const {\n    return F::operator()(*this, forward<\
    \ Args >(args)...);\n  }\n};\n \ntemplate< typename F >\ninline decltype(auto)\
    \ MFP(F &&f) {\n  return FixPoint< F >{forward< F >(f)};\n}\n#line 4 \"test/verify/yosupo-bellnoulli-number.test.cpp\"\
    \n\n#line 1 \"math/combinatorics/mod-int.cpp\"\ntemplate< int mod >\nstruct ModInt\
    \ {\n  int x;\n\n  ModInt() : x(0) {}\n\n  ModInt(int64_t y) : x(y >= 0 ? y %\
    \ mod : (mod - (-y) % mod) % mod) {}\n\n  ModInt &operator+=(const ModInt &p)\
    \ {\n    if((x += p.x) >= mod) x -= mod;\n    return *this;\n  }\n\n  ModInt &operator-=(const\
    \ ModInt &p) {\n    if((x += mod - p.x) >= mod) x -= mod;\n    return *this;\n\
    \  }\n\n  ModInt &operator*=(const ModInt &p) {\n    x = (int) (1LL * x * p.x\
    \ % mod);\n    return *this;\n  }\n\n  ModInt &operator/=(const ModInt &p) {\n\
    \    *this *= p.inverse();\n    return *this;\n  }\n\n  ModInt operator-() const\
    \ { return ModInt(-x); }\n\n  ModInt operator+(const ModInt &p) const { return\
    \ ModInt(*this) += p; }\n\n  ModInt operator-(const ModInt &p) const { return\
    \ ModInt(*this) -= p; }\n\n  ModInt operator*(const ModInt &p) const { return\
    \ ModInt(*this) *= p; }\n\n  ModInt operator/(const ModInt &p) const { return\
    \ ModInt(*this) /= p; }\n\n  bool operator==(const ModInt &p) const { return x\
    \ == p.x; }\n\n  bool operator!=(const ModInt &p) const { return x != p.x; }\n\
    \n  ModInt inverse() const {\n    int a = x, b = mod, u = 1, v = 0, t;\n    while(b\
    \ > 0) {\n      t = a / b;\n      swap(a -= t * b, b);\n      swap(u -= t * v,\
    \ v);\n    }\n    return ModInt(u);\n  }\n\n  ModInt pow(int64_t n) const {\n\
    \    ModInt ret(1), mul(x);\n    while(n > 0) {\n      if(n & 1) ret *= mul;\n\
    \      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n  }\n\n  friend ostream\
    \ &operator<<(ostream &os, const ModInt &p) {\n    return os << p.x;\n  }\n\n\
    \  friend istream &operator>>(istream &is, ModInt &a) {\n    int64_t t;\n    is\
    \ >> t;\n    a = ModInt< mod >(t);\n    return (is);\n  }\n\n  static int get_mod()\
    \ { return mod; }\n};\n\nusing modint = ModInt< mod >;\n#line 1 \"math/fft/number-theoretic-transform-friendly-mod-int.cpp\"\
    \ntemplate< typename Mint >\nstruct NumberTheoreticTransformFriendlyModInt {\n\
    \n  vector< Mint > dw, idw;\n  int max_base;\n  Mint root;\n\n  NumberTheoreticTransformFriendlyModInt()\
    \ {\n    const unsigned mod = Mint::get_mod();\n    assert(mod >= 3 && mod % 2\
    \ == 1);\n    auto tmp = mod - 1;\n    max_base = 0;\n    while(tmp % 2 == 0)\
    \ tmp >>= 1, max_base++;\n    root = 2;\n    while(root.pow((mod - 1) >> 1) ==\
    \ 1) root += 1;\n    assert(root.pow(mod - 1) == 1);\n    dw.resize(max_base);\n\
    \    idw.resize(max_base);\n    for(int i = 0; i < max_base; i++) {\n      dw[i]\
    \ = -root.pow((mod - 1) >> (i + 2));\n      idw[i] = Mint(1) / dw[i];\n    }\n\
    \  }\n\n  void ntt(vector< Mint > &a) {\n    const int n = (int) a.size();\n \
    \   assert((n & (n - 1)) == 0);\n    assert(__builtin_ctz(n) <= max_base);\n \
    \   for(int m = n; m >>= 1;) {\n      Mint w = 1;\n      for(int s = 0, k = 0;\
    \ s < n; s += 2 * m) {\n        for(int i = s, j = s + m; i < s + m; ++i, ++j)\
    \ {\n          auto x = a[i], y = a[j] * w;\n          a[i] = x + y, a[j] = x\
    \ - y;\n        }\n        w *= dw[__builtin_ctz(++k)];\n      }\n    }\n  }\n\
    \n  void intt(vector< Mint > &a, bool f = true) {\n    const int n = (int) a.size();\n\
    \    assert((n & (n - 1)) == 0);\n    assert(__builtin_ctz(n) <= max_base);\n\
    \    for(int m = 1; m < n; m *= 2) {\n      Mint w = 1;\n      for(int s = 0,\
    \ k = 0; s < n; s += 2 * m) {\n        for(int i = s, j = s + m; i < s + m; ++i,\
    \ ++j) {\n          auto x = a[i], y = a[j];\n          a[i] = x + y, a[j] = (x\
    \ - y) * w;\n        }\n        w *= idw[__builtin_ctz(++k)];\n      }\n    }\n\
    \    if(f) {\n      Mint inv_sz = Mint(1) / n;\n      for(int i = 0; i < n; i++)\
    \ a[i] *= inv_sz;\n    }\n  }\n\n  vector< Mint > multiply(vector< Mint > a, vector<\
    \ Mint > b) {\n    int need = a.size() + b.size() - 1;\n    int nbase = 1;\n \
    \   while((1 << nbase) < need) nbase++;\n    int sz = 1 << nbase;\n    a.resize(sz,\
    \ 0);\n    b.resize(sz, 0);\n    ntt(a);\n    ntt(b);\n    Mint inv_sz = Mint(1)\
    \ / sz;\n    for(int i = 0; i < sz; i++) a[i] *= b[i] * inv_sz;\n    intt(a, false);\n\
    \    a.resize(need);\n    return a;\n  }\n};\n#line 7 \"test/verify/yosupo-bellnoulli-number.test.cpp\"\
    \n\n#line 1 \"math/fps/formal-power-series.cpp\"\ntemplate< typename T >\nstruct\
    \ FormalPowerSeries : vector< T > {\n  using vector< T >::vector;\n  using P =\
    \ FormalPowerSeries;\n\n  using MULT = function< P(P, P) >;\n  using FFT = function<\
    \ void(P &) >;\n  using SQRT = function< T(T) >;\n\n  static MULT &get_mult()\
    \ {\n    static MULT mult = nullptr;\n    return mult;\n  }\n\n  static void set_mult(MULT\
    \ f) {\n    get_mult() = f;\n  }\n\n  static FFT &get_fft() {\n    static FFT\
    \ fft = nullptr;\n    return fft;\n  }\n\n  static FFT &get_ifft() {\n    static\
    \ FFT ifft = nullptr;\n    return ifft;\n  }\n\n  static void set_fft(FFT f, FFT\
    \ g) {\n    get_fft() = f;\n    get_ifft() = g;\n  }\n\n  static SQRT &get_sqrt()\
    \ {\n    static SQRT sqr = nullptr;\n    return sqr;\n  }\n\n  static void set_sqrt(SQRT\
    \ sqr) {\n    get_sqrt() = sqr;\n  }\n\n  void shrink() {\n    while(this->size()\
    \ && this->back() == T(0)) this->pop_back();\n  }\n\n  P operator+(const P &r)\
    \ const { return P(*this) += r; }\n\n  P operator+(const T &v) const { return\
    \ P(*this) += v; }\n\n  P operator-(const P &r) const { return P(*this) -= r;\
    \ }\n\n  P operator-(const T &v) const { return P(*this) -= v; }\n\n  P operator*(const\
    \ P &r) const { return P(*this) *= r; }\n\n  P operator*(const T &v) const { return\
    \ P(*this) *= v; }\n\n  P operator/(const P &r) const { return P(*this) /= r;\
    \ }\n\n  P operator%(const P &r) const { return P(*this) %= r; }\n\n  P &operator+=(const\
    \ P &r) {\n    if(r.size() > this->size()) this->resize(r.size());\n    for(int\
    \ i = 0; i < r.size(); i++) (*this)[i] += r[i];\n    return *this;\n  }\n\n  P\
    \ &operator+=(const T &r) {\n    if(this->empty()) this->resize(1);\n    (*this)[0]\
    \ += r;\n    return *this;\n  }\n\n  P &operator-=(const P &r) {\n    if(r.size()\
    \ > this->size()) this->resize(r.size());\n    for(int i = 0; i < r.size(); i++)\
    \ (*this)[i] -= r[i];\n    shrink();\n    return *this;\n  }\n\n  P &operator-=(const\
    \ T &r) {\n    if(this->empty()) this->resize(1);\n    (*this)[0] -= r;\n    shrink();\n\
    \    return *this;\n  }\n\n  P &operator*=(const T &v) {\n    const int n = (int)\
    \ this->size();\n    for(int k = 0; k < n; k++) (*this)[k] *= v;\n    return *this;\n\
    \  }\n\n  P &operator*=(const P &r) {\n    if(this->empty() || r.empty()) {\n\
    \      this->clear();\n      return *this;\n    }\n    assert(get_mult() != nullptr);\n\
    \    return *this = get_mult()(*this, r);\n  }\n\n  P &operator%=(const P &r)\
    \ { return *this -= *this / r * r; }\n\n  P operator-() const {\n    P ret(this->size());\n\
    \    for(int i = 0; i < this->size(); i++) ret[i] = -(*this)[i];\n    return ret;\n\
    \  }\n\n  P &operator/=(const P &r) {\n    if(this->size() < r.size()) {\n   \
    \   this->clear();\n      return *this;\n    }\n    int n = this->size() - r.size()\
    \ + 1;\n    return *this = (rev().pre(n) * r.rev().inv(n)).pre(n).rev(n);\n  }\n\
    \n  P dot(P r) const {\n    P ret(min(this->size(), r.size()));\n    for(int i\
    \ = 0; i < ret.size(); i++) ret[i] = (*this)[i] * r[i];\n    return ret;\n  }\n\
    \n  P pre(int sz) const { return P(begin(*this), begin(*this) + min((int) this->size(),\
    \ sz)); }\n\n  P operator>>(int sz) const {\n    if(this->size() <= sz) return\
    \ {};\n    P ret(*this);\n    ret.erase(ret.begin(), ret.begin() + sz);\n    return\
    \ ret;\n  }\n\n  P operator<<(int sz) const {\n    P ret(*this);\n    ret.insert(ret.begin(),\
    \ sz, T(0));\n    return ret;\n  }\n\n  P rev(int deg = -1) const {\n    P ret(*this);\n\
    \    if(deg != -1) ret.resize(deg, T(0));\n    reverse(begin(ret), end(ret));\n\
    \    return ret;\n  }\n\n  P diff() const {\n    const int n = (int) this->size();\n\
    \    P ret(max(0, n - 1));\n    for(int i = 1; i < n; i++) ret[i - 1] = (*this)[i]\
    \ * T(i);\n    return ret;\n  }\n\n  P integral() const {\n    const int n = (int)\
    \ this->size();\n    P ret(n + 1);\n    ret[0] = T(0);\n    for(int i = 0; i <\
    \ n; i++) ret[i + 1] = (*this)[i] / T(i + 1);\n    return ret;\n  }\n\n  // F(0)\
    \ must not be 0\n  P inv(int deg = -1) const {\n    assert(((*this)[0]) != T(0));\n\
    \    const int n = (int) this->size();\n    if(deg == -1) deg = n;\n    if(get_fft()\
    \ != nullptr) {\n      P ret(*this);\n      ret.resize(deg, T(0));\n      return\
    \ ret.inv_fast();\n    }\n    P ret({T(1) / (*this)[0]});\n    for(int i = 1;\
    \ i < deg; i <<= 1) {\n      ret = (ret + ret - ret * ret * pre(i << 1)).pre(i\
    \ << 1);\n    }\n    return ret.pre(deg);\n  }\n\n  // F(0) must be 1\n  P log(int\
    \ deg = -1) const {\n    assert((*this)[0] == 1);\n    const int n = (int) this->size();\n\
    \    if(deg == -1) deg = n;\n    return (this->diff() * this->inv(deg)).pre(deg\
    \ - 1).integral();\n  }\n\n  P sqrt(int deg = -1) const {\n    const int n = (int)\
    \ this->size();\n    if(deg == -1) deg = n;\n    if((*this)[0] == T(0)) {\n  \
    \    for(int i = 1; i < n; i++) {\n        if((*this)[i] != T(0)) {\n        \
    \  if(i & 1) return {};\n          if(deg - i / 2 <= 0) break;\n          auto\
    \ ret = (*this >> i).sqrt(deg - i / 2);\n          if(ret.empty()) return {};\n\
    \          ret = ret << (i / 2);\n          if(ret.size() < deg) ret.resize(deg,\
    \ T(0));\n          return ret;\n        }\n      }\n      return P(deg, 0);\n\
    \    }\n\n    P ret;\n    if(get_sqrt() == nullptr) {\n      assert((*this)[0]\
    \ == T(1));\n      ret = {T(1)};\n    } else {\n      auto sqr = get_sqrt()((*this)[0]);\n\
    \      if(sqr * sqr != (*this)[0]) return {};\n      ret = {T(sqr)};\n    }\n\n\
    \    T inv2 = T(1) / T(2);\n    for(int i = 1; i < deg; i <<= 1) {\n      ret\
    \ = (ret + pre(i << 1) * ret.inv(i << 1)) * inv2;\n    }\n    return ret.pre(deg);\n\
    \  }\n\n  // F(0) must be 0\n  P exp(int deg = -1) const {\n    assert((*this)[0]\
    \ == T(0));\n    const int n = (int) this->size();\n    if(deg == -1) deg = n;\n\
    \    if(get_fft() != nullptr) {\n      P ret(*this);\n      ret.resize(deg, T(0));\n\
    \      return ret.exp_rec();\n    }\n    P ret({T(1)});\n    for(int i = 1; i\
    \ < deg; i <<= 1) {\n      ret = (ret * (pre(i << 1) + T(1) - ret.log(i << 1))).pre(i\
    \ << 1);\n    }\n    return ret.pre(deg);\n  }\n\n\n  P online_convolution_exp(const\
    \ P &conv_coeff) const {\n    const int n = (int) conv_coeff.size();\n    assert((n\
    \ & (n - 1)) == 0);\n    vector< P > conv_ntt_coeff;\n    auto& fft = get_fft();\n\
    \    auto& ifft = get_ifft();\n    for(int i = n; i >= 1; i >>= 1) {\n      P\
    \ g(conv_coeff.pre(i));\n      fft(g);\n      conv_ntt_coeff.emplace_back(g);\n\
    \    }\n    P conv_arg(n), conv_ret(n);\n    auto rec = [&](auto rec, int l, int\
    \ r, int d) -> void {\n      if(r - l <= 16) {\n        for(int i = l; i < r;\
    \ i++) {\n          T sum = 0;\n          for(int j = l; j < i; j++) sum += conv_arg[j]\
    \ * conv_coeff[i - j];\n          conv_ret[i] += sum;\n          conv_arg[i] =\
    \ i == 0 ? T(1) : conv_ret[i] / i;\n        }\n      } else {\n        int m =\
    \ (l + r) / 2;\n        rec(rec, l, m, d + 1);\n        P pre(r - l);\n      \
    \  for(int i = 0; i < m - l; i++) pre[i] = conv_arg[l + i];\n        fft(pre);\n\
    \        for(int i = 0; i < r - l; i++) pre[i] *= conv_ntt_coeff[d][i];\n    \
    \    ifft(pre);\n        for(int i = 0; i < r - m; i++) conv_ret[m + i] += pre[m\
    \ + i - l];\n        rec(rec, m, r, d + 1);\n      }\n    };\n    rec(rec, 0,\
    \ n, 0);\n    return conv_arg;\n  }\n\n  P exp_rec() const {\n    assert((*this)[0]\
    \ == T(0));\n    const int n = (int) this->size();\n    int m = 1;\n    while(m\
    \ < n) m *= 2;\n    P conv_coeff(m);\n    for(int i = 1; i < n; i++) conv_coeff[i]\
    \ = (*this)[i] * i;\n    return online_convolution_exp(conv_coeff).pre(n);\n \
    \ }\n\n\n  P inv_fast() const {\n    assert(((*this)[0]) != T(0));\n\n    const\
    \ int n = (int) this->size();\n    P res{T(1) / (*this)[0]};\n\n    for(int d\
    \ = 1; d < n; d <<= 1) {\n      P f(2 * d), g(2 * d);\n      for(int j = 0; j\
    \ < min(n, 2 * d); j++) f[j] = (*this)[j];\n      for(int j = 0; j < d; j++) g[j]\
    \ = res[j];\n      get_fft()(f);\n      get_fft()(g);\n      for(int j = 0; j\
    \ < 2 * d; j++) f[j] *= g[j];\n      get_ifft()(f);\n      for(int j = 0; j <\
    \ d; j++) {\n        f[j] = 0;\n        f[j + d] = -f[j + d];\n      }\n     \
    \ get_fft()(f);\n      for(int j = 0; j < 2 * d; j++) f[j] *= g[j];\n      get_ifft()(f);\n\
    \      for(int j = 0; j < d; j++) f[j] = res[j];\n      res = f;\n    }\n    return\
    \ res.pre(n);\n  }\n\n  P pow(int64_t k, int deg = -1) const {\n    const int\
    \ n = (int) this->size();\n    if(deg == -1) deg = n;\n    for(int i = 0; i <\
    \ n; i++) {\n      if((*this)[i] != T(0)) {\n        T rev = T(1) / (*this)[i];\n\
    \        P ret = (((*this * rev) >> i).log() * k).exp() * ((*this)[i].pow(k));\n\
    \        if(i * k > deg) return P(deg, T(0));\n        ret = (ret << (i * k)).pre(deg);\n\
    \        if(ret.size() < deg) ret.resize(deg, T(0));\n        return ret;\n  \
    \    }\n    }\n    return *this;\n  }\n\n  T eval(T x) const {\n    T r = 0, w\
    \ = 1;\n    for(auto &v : *this) {\n      r += w * v;\n      w *= x;\n    }\n\
    \    return r;\n  }\n\n  P pow_mod(int64_t n, P mod) const {\n    P modinv = mod.rev().inv();\n\
    \    auto get_div = [&](P base) {\n      if(base.size() < mod.size()) {\n    \
    \    base.clear();\n        return base;\n      }\n      int n = base.size() -\
    \ mod.size() + 1;\n      return (base.rev().pre(n) * modinv.pre(n)).pre(n).rev(n);\n\
    \    };\n    P x(*this), ret{1};\n    while(n > 0) {\n      if(n & 1) {\n    \
    \    ret *= x;\n        ret -= get_div(ret) * mod;\n      }\n      x *= x;\n \
    \     x -= get_div(x) * mod;\n      n >>= 1;\n    }\n    return ret;\n  }\n};\n\
    #line 1 \"math/fps/formal-power-series-seq.cpp\"\ntemplate< typename T >\nFormalPowerSeries<\
    \ T > bernoulli(int N) {\n  FormalPowerSeries< T > poly(N + 1);\n  poly[0] = T(1);\n\
    \  for(int i = 1; i <= N; i++) {\n    poly[i] = poly[i - 1] / T(i + 1);\n  }\n\
    \  poly = poly.inv();\n  T tmp(1);\n  for(int i = 1; i <= N; i++) {\n    tmp *=\
    \ T(i);\n    poly[i] *= tmp;\n  }\n  return poly;\n}\n\ntemplate< typename T >\n\
    FormalPowerSeries< T > partition(int N) {\n  FormalPowerSeries< T > poly(N + 1);\n\
    \  poly[0] = 1;\n  for(int k = 1; k <= N; k++) {\n    if(1LL * k * (3 * k + 1)\
    \ / 2 <= N) poly[k * (3 * k + 1) / 2] += (k % 2 ? -1 : 1);\n    if(1LL * k * (3\
    \ * k - 1) / 2 <= N) poly[k * (3 * k - 1) / 2] += (k % 2 ? -1 : 1);\n  }\n  return\
    \ poly.inv();\n}\n\ntemplate< typename T >\nFormalPowerSeries< T > bell(int N)\
    \ {\n  FormalPowerSeries< T > poly(N + 1), ret(N + 1);\n  poly[1] = 1;\n  poly\
    \ = poly.exp();\n  poly[0] -= 1;\n  poly = poly.exp();\n  T mul = 1;\n  for(int\
    \ i = 0; i <= N; i++) {\n    ret[i] = poly[i] * mul;\n    mul *= i + 1;\n  }\n\
    \  return ret;\n}\n\ntemplate< typename T >\nFormalPowerSeries< T > stirling_first(int\
    \ N) {\n  if(N == 0) return {1};\n  int M = N / 2;\n  FormalPowerSeries< T > A\
    \ = stirling_first< T >(M), B, C(N - M + 1);\n\n  if(N % 2 == 0) {\n    B = A;\n\
    \  } else {\n    B.resize(M + 2);\n    B[M + 1] = 1;\n    for(int i = 1; i < M\
    \ + 1; i++) B[i] = A[i - 1] + A[i] * M;\n  }\n\n  T tmp = 1;\n  for(int i = 0;\
    \ i <= N - M; i++) {\n    C[N - M - i] = T(M).pow(i) / tmp;\n    B[i] *= tmp;\n\
    \    tmp *= T(i + 1);\n  }\n  C *= B;\n  tmp = 1;\n  for(int i = 0; i <= N - M;\
    \ i++) {\n    B[i] = C[N - M + i] / tmp;\n    tmp *= T(i + 1);\n  }\n  return\
    \ A * B;\n}\n\ntemplate< typename T >\nFormalPowerSeries< T > stirling_second(int\
    \ N) {\n  FormalPowerSeries< T > A(N + 1), B(N + 1);\n  modint tmp = 1;\n  for(int\
    \ i = 0; i <= N; i++) {\n    T rev = T(1) / tmp;\n    A[i] = T(i).pow(N) * rev;\n\
    \    B[i] = T(1) * rev;\n    if(i & 1) B[i] *= -1;\n    tmp *= i + 1;\n  }\n \
    \ return (A * B).pre(N + 1);\n}\n\ntemplate< typename T >\nFormalPowerSeries<\
    \ T > stirling_second_kth_column(int N, int K) {\n  FormalPowerSeries< T > poly(N\
    \ + 1), ret(N + 1);\n  poly[1] = 1;\n  poly = poly.exp();\n  poly[0] -= 1;\n \
    \ poly = poly.pow(K);\n  T rev = 1, mul = 1;\n  for(int i = 2; i <= K; i++) rev\
    \ *= i;\n  rev = T(1) / rev;\n  poly *= rev;\n  for(int i = 0; i <= N; i++) {\n\
    \    ret[i] = poly[i] * mul;\n    mul *= i + 1;\n  }\n  return ret;\n}\n\ntemplate<\
    \ typename T >\nFormalPowerSeries< T > eulerian(int N) {\n  vector< T > fact(N\
    \ + 2), rfact(N + 2);\n  fact[0] = rfact[N + 1] = 1;\n  for(int i = 1; i <= N\
    \ + 1; i++) fact[i] = fact[i - 1] * i;\n  rfact[N + 1] /= fact[N + 1];\n  for(int\
    \ i = N; i >= 0; i--) rfact[i] = rfact[i + 1] * (i + 1);\n\n  FormalPowerSeries<\
    \ T > A(N + 1), B(N + 1);\n  for(int i = 0; i <= N; i++) {\n    A[i] = fact[N\
    \ + 1] * rfact[i] * rfact[N + 1 - i];\n    if(i & 1) A[i] *= -1;\n    B[i] = T(i\
    \ + 1).pow(N);\n  }\n  return (A * B).pre(N + 1);\n}\n#line 10 \"test/verify/yosupo-bellnoulli-number.test.cpp\"\
    \n\nconst int MOD = 998244353;\nusing mint = ModInt< MOD >;\n\nint main() {\n\
    \  NumberTheoreticTransformFriendlyModInt< mint > ntt;\n  using FPS = FormalPowerSeries<\
    \ mint >;\n  auto mult = [&](const FPS::P &a, const FPS::P &b) {\n    auto ret\
    \ = ntt.multiply(a, b);\n    return FPS::P(ret.begin(), ret.end());\n  };\n  FPS::set_mult(mult);\n\
    \  FPS::set_fft([&](FPS::P &a) { ntt.ntt(a); }, [&](FPS::P &a) { ntt.intt(a);\
    \ });\n\n  int N;\n  cin >> N;\n  cout << bernoulli< mint >(N) << endl;\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bernoulli_number\"\n\n\
    #include \"../../template/template.cpp\"\n\n#include \"../../math/combinatorics/mod-int.cpp\"\
    \n#include \"../../math/fft/number-theoretic-transform-friendly-mod-int.cpp\"\n\
    \n#include \"../../math/fps/formal-power-series.cpp\"\n#include \"../../math/fps/formal-power-series-seq.cpp\"\
    \n\nconst int MOD = 998244353;\nusing mint = ModInt< MOD >;\n\nint main() {\n\
    \  NumberTheoreticTransformFriendlyModInt< mint > ntt;\n  using FPS = FormalPowerSeries<\
    \ mint >;\n  auto mult = [&](const FPS::P &a, const FPS::P &b) {\n    auto ret\
    \ = ntt.multiply(a, b);\n    return FPS::P(ret.begin(), ret.end());\n  };\n  FPS::set_mult(mult);\n\
    \  FPS::set_fft([&](FPS::P &a) { ntt.ntt(a); }, [&](FPS::P &a) { ntt.intt(a);\
    \ });\n\n  int N;\n  cin >> N;\n  cout << bernoulli< mint >(N) << endl;\n}\n\n"
  dependsOn:
  - template/template.cpp
  - math/combinatorics/mod-int.cpp
  - math/fft/number-theoretic-transform-friendly-mod-int.cpp
  - math/fps/formal-power-series.cpp
  - math/fps/formal-power-series-seq.cpp
  isVerificationFile: true
  path: test/verify/yosupo-bellnoulli-number.test.cpp
  requiredBy: []
  timestamp: '2020-02-24 19:19:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/yosupo-bellnoulli-number.test.cpp
layout: document
redirect_from:
- /verify/test/verify/yosupo-bellnoulli-number.test.cpp
- /verify/test/verify/yosupo-bellnoulli-number.test.cpp.html
title: test/verify/yosupo-bellnoulli-number.test.cpp
---