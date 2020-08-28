---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: Lazy-Reversible-Splay-Tree(遅延伝搬反転可能Splay木) <small>(structure/develop/lazy-reversible-splay-tree.cpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#b1cd1e8cabf258d1ad55a5bb477f1b01">structure/develop</a>
* <a href="{{ site.github.repository_url }}/blob/master/structure/develop/lazy-reversible-splay-tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-29 04:05:55+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/verify/aoj-2450-3.test.cpp.html">test/verify/aoj-2450-3.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Lazy-Reversible-Splay-Tree(遅延伝搬反転可能Splay木)
 */
template< typename Tp, typename Ep >
struct LazyReversibleSplayTreeNode {
  using T = Tp;
  using E = Ep;
  LazyReversibleSplayTreeNode *l, *r, *p;
  T key, sum;
  E lazy;
  bool rev;
  size_t sz;

  LazyReversibleSplayTreeNode() : LazyReversibleSplayTreeNode(Tp()) {}

  LazyReversibleSplayTreeNode(const T &key) :
      LazyReversibleSplayTreeNode(key, E()) {}

  LazyReversibleSplayTreeNode(const T &key, const E &lazy) :
      key(key), sum(key), rev(false), l(nullptr), r(nullptr), p(nullptr), sz(1), lazy(lazy) {}
};

template< typename Np >
struct LazyReversibleSplayTree : ReversibleSplayTree< Np > {
public:
public:
  using Node = Np;
  using T = typename Node::T;
  using E = typename Node::E;
  using super = ReversibleSplayTree< Node >;
  using F = typename super::F;
  using G = function< T(T, E) >;
  using H = function< E(E, E) >;
  using S = typename super::S;

  explicit LazyReversibleSplayTree(const F &f, const G &g, const H &h, const S &s,
                                   const T &M1, const E &OM0) :
      g(g), h(h), OM0(OM0), super(f, s, M1) {}


  using super::splay;
  using super::split;
  using super::count;
  using super::merge;
  using super::build_node;
  using super::toggle;
  using super::push_back_node;
  using super::push_front_node;
  using super::insert_node;

  Node *alloc(const T &x) override { return new Node(x, OM0); }

  void push(Node *t) override {
    if(t->lazy != OM0) {
      if(t->l) propagate(t->l, t->lazy);
      if(t->r) propagate(t->r, t->lazy);
      t->lazy = OM0;
    }
    if(t->rev) {
      if(t->l) toggle(t->l);
      if(t->r) toggle(t->r);
      t->rev = false;
    }
  }

  Node *build(const vector< T > &v) override {
    vector< Node * > vs(v.size());
    for(int i = 0; i < v.size(); i++) vs[i] = new Node(v[i], OM0);
    return build_node(vs);
  }

  Node *push_front(Node *t, const T &x) override {
    return push_front_node(t, new Node(x, OM0));
  }

  Node *push_back(Node *t, const T &x) override {
    return push_back_node(t, new Node(x, OM0));
  }

  void insert(Node *&t, int k, const T &x) override {
    insert_node(t, k, new Node(x, OM0));
  }

  void set_propagate(Node *&t, int a, int b, const E &pp) {
    splay(t);
    auto x = split(t, a);
    auto y = split(x.second, b - a);
    set_propagate(y.first, pp);
    t = merge(x.first, y.first, y.second);
  }

  void set_propagate(Node *&t, const E &pp) {
    splay(t);
    propagate(t, pp);
    push(t);
  }

private:
  const E OM0;
  const G g;
  const H h;

  void propagate(Node *t, const E &x) {
    t->lazy = h(t->lazy, x);
    t->key = g(t->key, x);
    t->sum = g(t->sum, x);
  }
};

template< typename T, typename E >
using LRST = LazyReversibleSplayTree< LazyReversibleSplayTreeNode< T, E > >;

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "structure/develop/lazy-reversible-splay-tree.cpp"
/**
 * @brief Lazy-Reversible-Splay-Tree(遅延伝搬反転可能Splay木)
 */
template< typename Tp, typename Ep >
struct LazyReversibleSplayTreeNode {
  using T = Tp;
  using E = Ep;
  LazyReversibleSplayTreeNode *l, *r, *p;
  T key, sum;
  E lazy;
  bool rev;
  size_t sz;

  LazyReversibleSplayTreeNode() : LazyReversibleSplayTreeNode(Tp()) {}

  LazyReversibleSplayTreeNode(const T &key) :
      LazyReversibleSplayTreeNode(key, E()) {}

  LazyReversibleSplayTreeNode(const T &key, const E &lazy) :
      key(key), sum(key), rev(false), l(nullptr), r(nullptr), p(nullptr), sz(1), lazy(lazy) {}
};

template< typename Np >
struct LazyReversibleSplayTree : ReversibleSplayTree< Np > {
public:
public:
  using Node = Np;
  using T = typename Node::T;
  using E = typename Node::E;
  using super = ReversibleSplayTree< Node >;
  using F = typename super::F;
  using G = function< T(T, E) >;
  using H = function< E(E, E) >;
  using S = typename super::S;

  explicit LazyReversibleSplayTree(const F &f, const G &g, const H &h, const S &s,
                                   const T &M1, const E &OM0) :
      g(g), h(h), OM0(OM0), super(f, s, M1) {}


  using super::splay;
  using super::split;
  using super::count;
  using super::merge;
  using super::build_node;
  using super::toggle;
  using super::push_back_node;
  using super::push_front_node;
  using super::insert_node;

  Node *alloc(const T &x) override { return new Node(x, OM0); }

  void push(Node *t) override {
    if(t->lazy != OM0) {
      if(t->l) propagate(t->l, t->lazy);
      if(t->r) propagate(t->r, t->lazy);
      t->lazy = OM0;
    }
    if(t->rev) {
      if(t->l) toggle(t->l);
      if(t->r) toggle(t->r);
      t->rev = false;
    }
  }

  Node *build(const vector< T > &v) override {
    vector< Node * > vs(v.size());
    for(int i = 0; i < v.size(); i++) vs[i] = new Node(v[i], OM0);
    return build_node(vs);
  }

  Node *push_front(Node *t, const T &x) override {
    return push_front_node(t, new Node(x, OM0));
  }

  Node *push_back(Node *t, const T &x) override {
    return push_back_node(t, new Node(x, OM0));
  }

  void insert(Node *&t, int k, const T &x) override {
    insert_node(t, k, new Node(x, OM0));
  }

  void set_propagate(Node *&t, int a, int b, const E &pp) {
    splay(t);
    auto x = split(t, a);
    auto y = split(x.second, b - a);
    set_propagate(y.first, pp);
    t = merge(x.first, y.first, y.second);
  }

  void set_propagate(Node *&t, const E &pp) {
    splay(t);
    propagate(t, pp);
    push(t);
  }

private:
  const E OM0;
  const G g;
  const H h;

  void propagate(Node *t, const E &x) {
    t->lazy = h(t->lazy, x);
    t->key = g(t->key, x);
    t->sum = g(t->sum, x);
  }
};

template< typename T, typename E >
using LRST = LazyReversibleSplayTree< LazyReversibleSplayTreeNode< T, E > >;

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

