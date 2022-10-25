void countSort(vector<vector<string>> arr) {
    for (int i = 0; i < arr.size() / 2; ++i) {
        arr[i][1] = "-";
    }
    int max = -1;
    for (int i = 0; i < arr.size(); ++i) {
        if (stoi(arr[i][0]) > max) {
            max = stoi(arr[i][0]);
        }
    }
    vector<vector<string>> strings(max + 1);
    for (int i = 0; i < arr.size(); ++i) {
        strings[stoi(arr[i][0])].push_back(arr[i][1]);
    }
    for (int i = 0; i < strings.size(); ++i) {
        for (int j = 0; j < strings[i].size(); ++j) {
            cout << strings[i][j] << ' ';
        }
    }
}