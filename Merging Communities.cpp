#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int findParent(int a, int parents[]) {
    if (a == parents[a]) {
        return a;
    }
    return findParent(parents[a], parents);
}

void mergeCommunity(int parents[], int size[], int a, int b) {
    a = findParent(a, parents);
    b = findParent(b, parents);
    if (a != b) {
        if (size[a] < size[b]) {
            swap(a, b);
        }
        size[a] += size[b];
        parents[b] = a;
    }
}

int printSize(int parents[], int size[], int a) {
    a = findParent(a, parents);
    return size[a];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    int parents[n + 1];
    int size[n + 1];
    for (int i = 0; i < n + 1; ++i) {
        parents[i] = i;
        size[i] = 1;
    }
    int q;
    cin >> q;
    cin.ignore();
    string queries[q];
    for (int i = 0; i < q; ++i) {
        getline(cin, queries[i]);
    }
    for (int i = 0; i < q; ++i) {
        if (queries[i][0] == 'M') {
            string number1 = "";
            string number2 = "";
            int index = 2;
            for (index = index; queries[i][index] != ' '; ++index) {
                number1 += queries[i][index];
            }
            for (index = index + 1; index < queries[i].length(); ++index) {
                number2 += queries[i][index];
            }
            mergeCommunity(parents, size, stoi(number1), stoi(number2));
            
        } else if (queries[i][0] == 'Q') {
            string number = "";
            for (int j = 2; j < queries[i].size(); ++j) {
                number += queries[i][j]; 
            }
            cout << printSize(parents, size, stoi(number)) << endl;
        }
    }
    return 0;
}
