bool compare(string s1, string s2) {
    if (s1.length() < s2.length()) {
        return true;
    } else if (s1.length() == s2.length()) {
        for (int i = 0; i < s1.length(); ++i) {
            if (s1[i] < s2[i]) {
                return true;
            } else if (s1[i] > s2[i]) {
                return false;
            }
        }
    }
    return false;
}

vector<string> bigSorting(vector<string> unsorted) {
    sort(unsorted.begin(), unsorted.end(), compare);
    return unsorted;
}