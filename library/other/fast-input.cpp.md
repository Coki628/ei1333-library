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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: other/fast-input.cpp
<a href="../../index.html">Back to top page</a>

* category: other
* <a href="{{ site.github.repository_url }}/blob/master/other/fast-input.cpp">View this file on GitHub</a>
    - Last commit date: 2019-07-20 01:29:30 +0900




## Code
{% raw %}
```cpp
template< int sz >
struct FastInput {
  char buf[sz + 1];
  char *o;

  FastInput() { init(); }

  void init() {
    o = buf;
    buf[fread(buf, sizeof(char), sizeof(char) * sz, stdin)] = '\0';
  }

  int64_t read() {
    int64_t ret = 0, sign = 1;
    while(*o && *o <= 32) ++o;
    if(*o == '-') sign *= -1, ++o;
    while(*o >= '0' && *o <= '9') {
      ret *= 10;
      ret += *o++ - '0';
    }
    return ret * sign;
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
