int luckBalance(int k, vector<vector<int>> contests) {
    int sum = 0;
    for ( int i = 0; i < contests.size() - 1; ++i ) {
        for ( int j = i + 1; j < contests.size(); ++j ) {
            if ( contests[i][0] < contests[j][0] ) {
                swap(contests[i][0], contests[j][0]);
                swap(contests[i][1], contests[j][1]);
            }
        }
    }
    for ( int i = 0; i < contests.size(); ++i ) {
        if ( contests[i][1] == 0 ) sum += contests[i][0];
        else {
            if ( k > 0 ) {
                sum += contests[i][0];
                --k;
            }
            else sum -= contests[i][0];
        }
    }
    return sum;
}