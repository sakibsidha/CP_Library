#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<class T>
using indexed_set = tree<T,null_type,less<T>,rb_tree_tag,
tree_order_statistics_node_update>;

/*

declare:
indexed_set<deta_type> st;

usage: 
st.find_by_order(x) :: returns iterator of the i-th element
st.order_of_key(x) :: returns index of x (numbe of elements less than x)

for multiset, replace less<T> with less_equal<T>

*/
