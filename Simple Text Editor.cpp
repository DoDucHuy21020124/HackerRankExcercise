#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string appendString(string W, string s, vector<string>& operation) {
    s += W;
    operation.push_back(s);
    return s;
}

string deleteString(string s, int k, vector<string>& operation) {
    s = s.substr(0, s.length() - k - 1);
    operation.push_back(s);
    return s;
}

void print(string s, int k) {
    cout << s[k] << endl;
}

string undo(vector<string>& operation) {
    operation.pop_back();
    string s = operation[operation.size() - 1];
    return s;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string s = "";
    int Q;
    cin >> Q;
    cin.ignore();
    vector<string> queries;
    for (int i = 0; i < Q; ++i) {
        string query;
        getline(cin, query);
        queries.push_back(query);
    }
    vector<string> operationString;
    operationString.push_back(s);
    for (int i = 0; i < queries.size(); ++i) {
        if (queries[i].length() == 1) {

            s = undo(operationString);
        } else {
            string oper = "";
            oper += queries[i][0];
            
            string handle = "";
            for (int j = 2; j < queries[i].length(); ++j) {
                handle += queries[i][j];
            }
            if (stoi(oper) == 1) {
                s = appendString(handle, s, operationString);
            } else if (stoi(oper) == 2) {
                s = deleteString(s, stoi(handle) - 1, operationString);
            } else if (stoi(oper) == 3) {
                print(s, stoi(handle) - 1);
            }
        }
    }
    return 0;
}
