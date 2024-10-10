class SegTrees {
public:
  int size;
  vector<ll> tr;

  template<typename T>
  void build(vector<T>& a) {
    for (int i = 0; i < size; ++i) 
      tr[size + i] = a[i];
    for (int i = size - 1; i >= 1; --i) {
      tr[i] = min(tr[2 * i], tr[2 * i + 1]);
    }
  }

  template<typename T>
  void init(T n, vector<T> a) {
    size = n;
    while (__builtin_popcount(size) != 1) {
      size++;
      a.push_back(LLONG_MAX);
    }
    tr.resize(2 * size);
    build(a);
  }

  template<typename T>
  T query(T nd, T s, T e, T l, T r) {
    if (s >= l && e <= r) 
      return tr[nd];
    if (s > r || e < l) 
      return LLONG_MAX;
    T mid = (s + e) / 2;
    T left = query(2 * nd, s, mid, l, r);
    T right = query(2 * nd + 1, mid + 1, e, l, r);
    return min(left, right);
  }

  template<typename T>
  T query(T l, T r) {
    return query(1LL, 0LL, (ll)size - 1, (ll)l, (ll)r);
  }

  template<typename T>
  void update(T idx, T val) {
    tr[size + idx] = val;
    for (int i = (size + idx) / 2; i >= 1; i /= 2) {
      tr[i] = min(tr[2 * i], tr[2 * i + 1]);
    }
  }
};
