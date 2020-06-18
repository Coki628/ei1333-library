/**
 * @brief Lazy-Splay-Tree(遅延伝搬Splay木)
 */
template< typename Monoid = int, typename OperatorMonoid = Monoid >
struct LazySplayTree {
public:
  using F = function< Monoid(Monoid, Monoid) >;
  using G = function< Monoid(Monoid, OperatorMonoid) >;
  using H = function< OperatorMonoid(OperatorMonoid, OperatorMonoid) >;
  using S = function< Monoid(Monoid) >;

  struct Node {
    Node *l, *r, *p;
    Monoid key, sum;
    OperatorMonoid lazy;
    bool rev;
    size_t sz;

    bool is_root() const {
      return !p || (p->l != this && p->r != this);
    }

    Node(const Monoid &key, const OperatorMonoid &om) :
        key(key), sum(key), lazy(om), sz(1), rev(false),
        l(nullptr), r(nullptr), p(nullptr) {}
  };

  LazySplayTree(const F &f, const Monoid &M1) :
      LazySplayTree(f, [](const Monoid &a) { return a; }, M1) {}

  LazySplayTree(const F &f, const S &s, const Monoid &M1) :
      LazySplayTree(f, G(), H(), s, M1, OperatorMonoid()) {}

  LazySplayTree(const F &f, const G &g, const H &h, const S &s,
                const Monoid &M1, const OperatorMonoid &OM0) :
      f(f), g(g), h(h), s(s), M1(M1), OM0(OM0) {}


  inline size_t count(const Node *t) { return t ? t->sz : 0; }

  inline const Monoid &sum(const Node *t) { return t ? t->sum : M1; }

  Node *alloc(const Monoid &v = Monoid()) {
    return new Node(v, OM0);
  }

  void splay(Node *t) {
    push(t);
    while(!t->is_root()) {
      auto *q = t->p;
      if(q->is_root()) {
        push(q), push(t);
        if(q->l == t) rotr(t);
        else rotl(t);
      } else {
        auto *r = q->p;
        push(r), push(q), push(t);
        if(r->l == q) {
          if(q->l == t) rotr(q), rotr(t);
          else rotl(t), rotr(t);
        } else {
          if(q->r == t) rotl(q), rotl(t);
          else rotr(t), rotl(t);
        }
      }
    }
  }

  Node *push_front(Node *t, const Monoid &v = Monoid()) {
    if(!t) {
      t = alloc(v);
      return t;
    } else {
      Node *cur = get_left(t), *z = alloc(v);
      splay(cur);
      z->p = cur;
      cur->l = z;
      splay(z);
      return z;
    }
  }

  Node *push_back(Node *t, const Monoid &v = Monoid()) {
    if(!t) {
      t = alloc(v);
      return t;
    } else {
      Node *cur = get_right(t), *z = alloc(v);
      splay(cur);
      z->p = cur;
      cur->r = z;
      splay(z);
      return z;
    }
  }

  Node *erase(Node *t) {
    splay(t);
    Node *x = t->l, *y = t->r;
    delete t;
    if(!x) {
      t = y;
      if(t) t->p = nullptr;
    } else if(!y) {
      t = x;
      t->p = nullptr;
    } else {
      x->p = nullptr;
      t = get_right(x);
      splay(t);
      t->r = y;
      y->p = t;
    }
    return t;
  }

  Node *get_left(Node *t) const {
    while(t->l) t = t->l;
    return t;
  }

  Node *get_right(Node *t) const {
    while(t->r) t = t->r;
    return t;
  }

  void set_propagate(Node *&t, int a, int b, const OperatorMonoid &pp) {
    auto x = split(t, a);
    auto y = split(x.second, b - a);
    set_propagate(y.first, pp);
    t = merge(x.first, y.first, y.second);
  }

  virtual void set_propagate(Node *&t, const OperatorMonoid &pp) {
    propagate(t, pp);
    push(t);
  }

  pair< Node *, Node * > split(Node *t, int k) {
    if(!t) return {nullptr, nullptr};
    push(t);
    if(k <= count(t->l)) {
      auto x = split(t->l, k);
      t->l = x.second;
      t->p = nullptr;
      if(x.second) x.second->p = t;
      return {x.first, update(t)};
    } else {
      auto x = split(t->r, k - count(t->l) - 1);
      t->r = x.first;
      t->p = nullptr;
      if(x.first) x.first->p = t;
      return {update(t), x.second};
    }
  }

  template< typename ... Args >
  Node *merge(Node *l, Args ...rest) {
    Node *r = merge(rest...);
    if(!l && !r) return nullptr;
    if(!l) return splay(r), r;
    if(!r) return splay(l), l;
    splay(l), splay(r);
    l = get_right(l);
    splay(l);
    l->r = r;
    r->p = l;
    update(l);
    return l;
  }

  void insert(Node *&t, int k, const Monoid &v) {
    auto x = split(t, k);
    t = merge(merge(x.first, alloc(v)), x.second);
  }

  Monoid erase(Node *&t, int k) {
    auto x = split(t, k);
    auto y = split(x.second, 1);
    auto v = y.first->c;
    delete y.first;
    t = merge(x.first, y.second);
    return v;
  }

  Monoid query(Node *&t, int a, int b) {
    auto x = split(t, a);
    auto y = split(x.second, b - a);
    auto ret = sum(y.first);
    t = merge(x.first, y.first, y.second);
    return ret;
  }

  Node *build(const vector< Monoid > &v) {
    return build(0, (int) v.size(), v);
  }

  void toggle(Node *t) {
    swap(t->l, t->r);
    t->sum = s(t->sum);
    t->rev ^= true;
  }

  Node *update(Node *t) {
    t->sz = 1;
    t->sum = t->key;
    if(t->l) t->sz += t->l->sz, t->sum = f(t->l->sum, t->sum);
    if(t->r) t->sz += t->r->sz, t->sum = f(t->sum, t->r->sum);
    return t;
  }

  tuple< Node *, Node *, Node * > split3(Node *t, int a, int b) {
    auto x = split(t, a);
    auto y = split(x.second, b - a);
    return make_tuple(x.first, y.first, y.second);
  }

  void push(Node *t) {
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

private:
  const Monoid M1;
  const OperatorMonoid OM0;
  const F f;
  const G g;
  const H h;
  const S s;

  Node *build(int l, int r, const vector< Monoid > &v) {
    if(l + 1 >= r) return alloc(v[l]);
    return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));
  }

  void propagate(Node *t, const OperatorMonoid &x) {
    t->lazy = h(t->lazy, x);
    t->key = g(t->key, x);
    t->sum = g(t->sum, x);
  }

  void rotr(Node *t) {
    auto *x = t->p, *y = x->p;
    if((x->l = t->r)) t->r->p = x;
    t->r = x, x->p = t;
    update(x), update(t);
    if((t->p = y)) {
      if(y->l == x) y->l = t;
      if(y->r == x) y->r = t;
      update(y);
    }
  }

  void rotl(Node *t) {
    auto *x = t->p, *y = x->p;
    if((x->r = t->l)) t->l->p = x;
    t->l = x, x->p = t;
    update(x), update(t);
    if((t->p = y)) {
      if(y->l == x) y->l = t;
      if(y->r == x) y->r = t;
      update(y);
    }
  }

  Node *merge(Node *l) {
    return l;
  }
};