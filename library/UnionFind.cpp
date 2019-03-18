/*UnionFind*/
class UnionFind {
private:
    vector<ll> dataArray;
public:
    UnionFind(size_t size): dataArray(size, -1) {}
    void unite(ll lhs, ll rhs) {
        lhs = root(lhs);
        rhs = root(rhs);
        bool isUnion = (lhs != rhs);
        if (isUnion) {
            if (dataArray[lhs] > dataArray[rhs] ) {
                swap(lhs, rhs);
            }
            dataArray[lhs] += dataArray[rhs];
            dataArray[rhs] = lhs;
        }
        return;
    }
    
    ll root(ll id) {
        if (dataArray[id] >= 0) {
            return dataArray[id] = root(dataArray[id]);
        } else {
            return id;
        }
    }
    
    bool same(ll lhs, ll rhs) {
        return (root(lhs) == root(rhs));
    }
};
