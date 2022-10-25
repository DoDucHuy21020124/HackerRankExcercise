string isBalanced(string s) {
    stack<char> branket;
    
    for (int i = 0; i < s.length(); ++i) {
        if (branket.empty()) {
            if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                return "NO";
            } else {
                branket.push(s[i]);
            }
        } else {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                branket.push(s[i]);
            } else {
                if (branket.top() == '(') {
                    if (s[i] == ')') {
                        branket.pop();
                    } else {
                        return "NO";
                    }
                } else if (branket.top() == '{') {
                    if (s[i] == '}') {
                        branket.pop();
                    } else {
                        return "NO";
                    }
                } else if (branket.top() == '[') {
                    if (s[i] == ']') {
                        branket.pop();
                    } else {
                        return "NO";
                    }
                }
            }
        }
    }
    if (branket.empty()) {
        return "YES";
    }
    return "NO";
}