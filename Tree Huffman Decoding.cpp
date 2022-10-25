void decode_huff(node * root, string s) {
    string res = "";
    node* temp = root;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '0') {
            temp = temp->left;
        } else if (s[i] == '1') {
            temp = temp->right;
        }
        if (temp->left == NULL && temp->right == NULL) {
            res += temp->data;
            temp = root;
        }
    }
    cout << res;
}