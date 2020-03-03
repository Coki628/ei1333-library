## 概要

Fenwick Tree とも呼ばれる. 数列に対し, ある要素に値を加える操作と, 区間和を求める操作をそれぞれ対数時間で行うことが出来るデータ構造. セグメント木や平衡二分探索
木の機能を制限したものであるが, 実装が非常に単純で定数倍も軽いなどの利点がある.

* `add(k, x)`: 要素 `k` に値 `x` を加える.
* `query(k)`: 区間 $[0,k]$ の総和を求める(閉区間なので注意すること).
* `lower_bound(x)`: 区間 $[0,k]$ の総和が `x` 以上となる最小の $k$ を返す.
* `upper_bound(x)`: 区間 $[0,k]$ の総和が `x` を上回る最小の $k$ を返す.

## 計算量

* クエリ: $O(\log N)$