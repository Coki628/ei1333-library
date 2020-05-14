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


# :warning: Weight-Balanced-Tree(重み平衡木) <small>(structure/bbst/weight-balanced-tree.cpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ac1922c227762d9e573c4f7aedc86899">structure/bbst</a>
* <a href="{{ site.github.repository_url }}/blob/master/structure/bbst/weight-balanced-tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-14 22:00:37+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Weight-Balanced-Tree(重み平衡木)
 */
template< typename Monoid, typename F >
struct WeightBalancedTree {
public:
  struct Node {
    Node *l, *r;
    int cnt;
    Monoid key, sum;

    Node() {}

    Node(const Monoid &k) : key(k), sum(k), l(nullptr), r(nullptr), cnt(1) {}

    Node(Node *l, Node *r, const Monoid &k) : key(k), l(l), r(r) {}

    bool is_leaf() { return !l || !r; }
  };

private:
  Node *update(Node *t) {
    t->cnt = count(t->l) + count(t->r) + t->is_leaf();
    t->sum = f(f(sum(t->l), t->key), sum(t->r));
    return t;
  }

  inline Node *alloc(Node *l, Node *r) {
    auto t = &(*pool.alloc() = Node(l, r, M1));
    return update(t);
  }

  Node *submerge(Node *l, Node *r) {
    if(count(l) * 2 > count(r) * 7) {
      l = clone(l);
      auto nl = clone(l->l);
      auto nr = submerge(l->r, r);
      if(count(nl) * 7 >= count(nr) * 2) {
        l->r = nr;
        return update(l);
      }
      if(count(nr->l) * 2 <= count(nr->r) * 5) {
        l->r = nr->l;
        nr->l = l;
        update(l);
        return update(nr);
      }
      Node *t = clone(nr->l);
      l->r = nr->l->l;
      update(l);
      nr->l = nr->l->r;
      update(nr);
      t->l = l;
      t->r = nr;
      return update(t);
    }
    if(count(l) * 7 < count(r) * 2) {
      r = clone(r);
      auto nl = submerge(l, r->l);
      auto nr = clone(r->r);
      if(count(nl) * 2 <= count(nr) * 7) {
        r->l = nl;
        return update(r);
      }
      if(count(nl->l) * 5 >= count(nl->r) * 2) {
        r->l = nl->r;
        nl->r = r;
        update(r);
        return update(nl);
      }
      Node *t = clone(nl->r);
      r->l = nl->r->r;
      update(r);
      nl->r = nl->r->l;
      update(nl);
      t->r = r;
      t->l = nl;
      return update(t);
    }
    return alloc(l, r);
  }

  Node *build(int l, int r, const vector< Monoid > &v) {
    if(l + 1 >= r) return alloc(v[l]);
    return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));
  }

  void dump(Node *r, typename vector< Monoid >::iterator &it) {
    if(r->is_leaf()) {
      *it++ = r->key;
      return;
    }
    dump(r->l, it);
    dump(r->r, it);
  }

  virtual Node *clone(Node *t) {
    return t;
  }

  Node *merge(Node *l) {
    return l;
  }

  Monoid query(Node *t, int a, int b, int l, int r) {
    if(r <= a || b <= l) return M1;
    if(a <= l && r <= b) return t->sum;
    return f(query(t->l, a, b, l, l + count(t->l)), query(t->r, a, b, r - count(t->r), r));
  }

public:
  VectorPool< Node > pool;
  const F f;
  const Monoid M1;

  WeightBalancedTree(int sz, const F &f, const Monoid &M1) : pool(sz), M1(M1), f(f) {
    pool.clear();
  }

  inline Node *alloc(const Monoid &key) {
    return &(*pool.alloc() = Node(key));
  }

  static inline int count(const Node *t) { return t ? t->cnt : 0; }

  inline const Monoid &sum(const Node *t) { return t ? t->sum : M1; }

  pair< Node *, Node * > split(Node *t, int k) {
    if(!t) return {nullptr, nullptr};
    if(k == 0) return {nullptr, t};
    if(k >= count(t)) return {t, nullptr};
    t = clone(t);
    Node *l = t->l, *r = t->r;
    pool.free(t);
    if(k < count(l)) {
      auto pp = split(l, k);
      return {pp.first, merge(pp.second, r)};
    }
    if(k > count(l)) {
      auto pp = split(r, k - count(l));
      return {merge(l, pp.first), pp.second};
    }
    return {l, r};
  }

  tuple< Node *, Node *, Node * > split3(Node *t, int a, int b) {
    auto x = split(t, a);
    auto y = split(x.second, b - a);
    return make_tuple(x.first, y.first, y.second);
  }

  template< typename ... Args >
  Node *merge(Node *l, Args ...rest) {
    Node *r = merge(rest...);
    if(!l || !r) return l ? l : r;
    return submerge(l, r);
  }

  Node *build(const vector< Monoid > &v) {
    return build(0, (int) v.size(), v);
  }

  vector< Monoid > dump(Node *r) {
    vector< Monoid > v((size_t) count(r));
    auto it = begin(v);
    dump(r, it);
    return v;
  }

  string to_string(Node *r) {
    auto s = dump(r);
    string ret;
    for(int i = 0; i < s.size(); i++) {
      ret += std::to_string(s[i]);
      ret += ", ";
    }
    return ret;
  }

  void insert(Node *&t, int k, const Monoid &v) {
    auto x = split(t, k);
    t = merge(merge(x.first, alloc(v)), x.second);
  }

  Monoid erase(Node *&t, int k) {
    auto x = split(t, k);
    auto y = split(x.second, 1);
    auto v = y.first->c;
    pool.free(y.first);
    t = merge(x.first, y.second);
    return v;
  }

  Monoid query(Node *t, int a, int b) {
    return query(t, a, b, 0, count(t));
  }

  void set_element(Node *&t, int k, const Monoid &x) {
    t = clone(t);
    if(t->is_leaf()) {
      t->key = t->sum = x;
      return;
    }
    if(k < count(t->l)) set_element(t->l, k, x);
    else set_element(t->r, k - count(t->l), x);
    t = update(t);
  }

  void push_front(Node *&t, const Monoid &v) {
    t = merge(alloc(v), t);
  }

  void push_back(Node *&t, const Monoid &v) {
    t = merge(t, alloc(v));
  }

  Monoid pop_front(Node *&t) {
    auto ret = split(t, 1);
    t = ret.second;
    return ret.first->key;
  }

  Monoid pop_back(Node *&t) {
    auto ret = split(t, count(t) - 1);
    t = ret.first;
    return ret.second->key;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "structure/bbst/weight-balanced-tree.cpp"
/**
 * @brief Weight-Balanced-Tree(重み平衡木)
 */
template< typename Monoid, typename F >
struct WeightBalancedTree {
public:
  struct Node {
    Node *l, *r;
    int cnt;
    Monoid key, sum;

    Node() {}

    Node(const Monoid &k) : key(k), sum(k), l(nullptr), r(nullptr), cnt(1) {}

    Node(Node *l, Node *r, const Monoid &k) : key(k), l(l), r(r) {}

    bool is_leaf() { return !l || !r; }
  };

private:
  Node *update(Node *t) {
    t->cnt = count(t->l) + count(t->r) + t->is_leaf();
    t->sum = f(f(sum(t->l), t->key), sum(t->r));
    return t;
  }

  inline Node *alloc(Node *l, Node *r) {
    auto t = &(*pool.alloc() = Node(l, r, M1));
    return update(t);
  }

  Node *submerge(Node *l, Node *r) {
    if(count(l) * 2 > count(r) * 7) {
      l = clone(l);
      auto nl = clone(l->l);
      auto nr = submerge(l->r, r);
      if(count(nl) * 7 >= count(nr) * 2) {
        l->r = nr;
        return update(l);
      }
      if(count(nr->l) * 2 <= count(nr->r) * 5) {
        l->r = nr->l;
        nr->l = l;
        update(l);
        return update(nr);
      }
      Node *t = clone(nr->l);
      l->r = nr->l->l;
      update(l);
      nr->l = nr->l->r;
      update(nr);
      t->l = l;
      t->r = nr;
      return update(t);
    }
    if(count(l) * 7 < count(r) * 2) {
      r = clone(r);
      auto nl = submerge(l, r->l);
      auto nr = clone(r->r);
      if(count(nl) * 2 <= count(nr) * 7) {
        r->l = nl;
        return update(r);
      }
      if(count(nl->l) * 5 >= count(nl->r) * 2) {
        r->l = nl->r;
        nl->r = r;
        update(r);
        return update(nl);
      }
      Node *t = clone(nl->r);
      r->l = nl->r->r;
      update(r);
      nl->r = nl->r->l;
      update(nl);
      t->r = r;
      t->l = nl;
      return update(t);
    }
    return alloc(l, r);
  }

  Node *build(int l, int r, const vector< Monoid > &v) {
    if(l + 1 >= r) return alloc(v[l]);
    return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));
  }

  void dump(Node *r, typename vector< Monoid >::iterator &it) {
    if(r->is_leaf()) {
      *it++ = r->key;
      return;
    }
    dump(r->l, it);
    dump(r->r, it);
  }

  virtual Node *clone(Node *t) {
    return t;
  }

  Node *merge(Node *l) {
    return l;
  }

  Monoid query(Node *t, int a, int b, int l, int r) {
    if(r <= a || b <= l) return M1;
    if(a <= l && r <= b) return t->sum;
    return f(query(t->l, a, b, l, l + count(t->l)), query(t->r, a, b, r - count(t->r), r));
  }

public:
  VectorPool< Node > pool;
  const F f;
  const Monoid M1;

  WeightBalancedTree(int sz, const F &f, const Monoid &M1) : pool(sz), M1(M1), f(f) {
    pool.clear();
  }

  inline Node *alloc(const Monoid &key) {
    return &(*pool.alloc() = Node(key));
  }

  static inline int count(const Node *t) { return t ? t->cnt : 0; }

  inline const Monoid &sum(const Node *t) { return t ? t->sum : M1; }

  pair< Node *, Node * > split(Node *t, int k) {
    if(!t) return {nullptr, nullptr};
    if(k == 0) return {nullptr, t};
    if(k >= count(t)) return {t, nullptr};
    t = clone(t);
    Node *l = t->l, *r = t->r;
    pool.free(t);
    if(k < count(l)) {
      auto pp = split(l, k);
      return {pp.first, merge(pp.second, r)};
    }
    if(k > count(l)) {
      auto pp = split(r, k - count(l));
      return {merge(l, pp.first), pp.second};
    }
    return {l, r};
  }

  tuple< Node *, Node *, Node * > split3(Node *t, int a, int b) {
    auto x = split(t, a);
    auto y = split(x.second, b - a);
    return make_tuple(x.first, y.first, y.second);
  }

  template< typename ... Args >
  Node *merge(Node *l, Args ...rest) {
    Node *r = merge(rest...);
    if(!l || !r) return l ? l : r;
    return submerge(l, r);
  }

  Node *build(const vector< Monoid > &v) {
    return build(0, (int) v.size(), v);
  }

  vector< Monoid > dump(Node *r) {
    vector< Monoid > v((size_t) count(r));
    auto it = begin(v);
    dump(r, it);
    return v;
  }

  string to_string(Node *r) {
    auto s = dump(r);
    string ret;
    for(int i = 0; i < s.size(); i++) {
      ret += std::to_string(s[i]);
      ret += ", ";
    }
    return ret;
  }

  void insert(Node *&t, int k, const Monoid &v) {
    auto x = split(t, k);
    t = merge(merge(x.first, alloc(v)), x.second);
  }

  Monoid erase(Node *&t, int k) {
    auto x = split(t, k);
    auto y = split(x.second, 1);
    auto v = y.first->c;
    pool.free(y.first);
    t = merge(x.first, y.second);
    return v;
  }

  Monoid query(Node *t, int a, int b) {
    return query(t, a, b, 0, count(t));
  }

  void set_element(Node *&t, int k, const Monoid &x) {
    t = clone(t);
    if(t->is_leaf()) {
      t->key = t->sum = x;
      return;
    }
    if(k < count(t->l)) set_element(t->l, k, x);
    else set_element(t->r, k - count(t->l), x);
    t = update(t);
  }

  void push_front(Node *&t, const Monoid &v) {
    t = merge(alloc(v), t);
  }

  void push_back(Node *&t, const Monoid &v) {
    t = merge(t, alloc(v));
  }

  Monoid pop_front(Node *&t) {
    auto ret = split(t, 1);
    t = ret.second;
    return ret.first->key;
  }

  Monoid pop_back(Node *&t) {
    auto ret = split(t, count(t) - 1);
    t = ret.first;
    return ret.second->key;
  }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

