vector<int> jimOrders(vector<vector<int>> orders) {
    vector<int> serve;
    vector<int> res;
    for ( int i = 0; i < orders.size(); ++i ) {
        int time = orders[i][0] + orders[i][1];
        serve.push_back(time);
        res.push_back(i + 1);
    }
    int max = serve[0];
    for ( int i = serve.size() - 1; i >= 1; --i ) {
        for ( int j = 0; j <= i - 1; ++j ) {
            if ( serve[i] < serve[j] ) {
                swap(serve[i], serve[j]);
                swap(res[i], res[j]);
            }
        }
    }
    return res;
}