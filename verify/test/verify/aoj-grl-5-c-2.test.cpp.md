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


# :heavy_check_mark: test/verify/aoj-grl-5-c-2.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/verify/aoj-grl-5-c-2.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-11 21:18:41 +0900


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/graph/template.cpp.html">graph/template.cpp</a>
* :heavy_check_mark: <a href="../../../library/graph/tree/heavy-light-decomposition.cpp.html">graph/tree/heavy-light-decomposition.cpp</a>
* :warning: <a href="../../../library/template/template.cpp.html">template/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"

#include "../../template/template.cpp"
#include "../../graph/template.cpp"

#include "../../graph/tree/heavy-light-decomposition.cpp"

int main() {
  int N, Q;
  scanf("%d", &N);
  UnWeightedGraph g(N);
  HeavyLightDecomposition< UnWeightedGraph > tree(g);
  for(int i = 0; i < N; i++) {
    int k;
    scanf("%d", &k);
    for(int j = 0; j < k; j++) {
      int c;
      scanf("%d", &c);
      g[i].push_back(c);
    }
  }
  tree.build();
  scanf("%d", &Q);
  for(int i = 0; i < Q; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    printf("%d\n", tree.lca(u, v));
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

