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


# :heavy_check_mark: test/verify/aoj-grl-5-c.test.cpp
<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/verify/aoj-grl-5-c.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-30 23:02:43 +0900


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C</a>


## Depends On
* :heavy_check_mark: <a href="../../../library/graph/template.cpp.html">graph/template.cpp</a>
* :heavy_check_mark: <a href="../../../library/graph/tree/doubling-lowest-common-ancestor.cpp.html">graph/tree/doubling-lowest-common-ancestor.cpp</a>
* :heavy_check_mark: <a href="../../../library/template/template.cpp.html">template/template.cpp</a>


## Code
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"

#include "../../template/template.cpp"
#include "../../graph/template.cpp"

#include "../../graph/tree/doubling-lowest-common-ancestor.cpp"

int main() {
  int N, Q;
  scanf("%d", &N);
  UnWeightedGraph g(N);
  for(int i = 0; i < N; i++) {
    int k;
    scanf("%d", &k);
    while(k--) {
      int c;
      scanf("%d", &c);
      g[i].push_back(c);
    }
  }
  DoublingLowestCommonAncestor< UnWeightedGraph > lca(g);
  lca.build();
  scanf("%d", &Q);
  while(Q--) {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d\n", lca.query(x, y));
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
