## 概要

更新がない場合の区間の最小値を, 前計算 $O(n \log n)$, クエリ $O(1)$ で処理する.

* `SparseTable(v)`: 配列 `v` で初期化する.
* `query(l, r)`: 区間 $[l, r)$ の最小値を求める.

## 計算量

* `SparseTable(v)`: $O(N \log N)$
* `query(l, r)`: $O(1)$
