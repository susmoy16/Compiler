
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, result = "";
    bool multiComment = false;
    bool singleComment = false;

    cout << "Enter source code (use # to finish):" << endl;

    while (getline(cin, s) && s != "#") {
        for (int i = 0; i < s.length(); i++) {
            if (multiComment) {
                if (s[i] == '*' && i + 1 < s.length() && s[i + 1] == '/') {
                    multiComment = false;
                    i++;
                }
            }
            else if (singleComment) {
                break;
            }
            else if (s[i] == '/' && i + 1 < s.length() && s[i + 1] == '/') {
                singleComment = true;
                break;
            }
            else if (s[i] == '/' && i + 1 < s.length() && s[i + 1] == '*') {
                multiComment = true;
                i++;
            }
            else {
                result += s[i];
            }
        }

        if (!multiComment) {
            singleComment = false;
        }

        result += '\n';
    }

    cout << "\nCode without comments:\n";
    cout << result;

    return 0;
}
