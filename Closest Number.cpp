vector<int> closestNumbers(vector<int> arr) {
    vector<int> res;
    sort(arr.begin(), arr.end());
    int min = INT32_MAX;
    for (int i = 0; i < arr.size() - 1; ++i) {
        if (abs(arr[i] - arr[i + 1]) < min) {
            min = abs(arr[i] - arr[i + 1]);
        }
    }
    for (int i = 0; i < arr.size() - 1; ++i) {
        if (abs(arr[i] - arr[i + 1]) == min) {
            res.push_back(arr[i]);
            res.push_back(arr[i + 1]);
        }
    }
    return res;
}