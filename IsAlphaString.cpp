#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isAlphabetic(const string& s) {
    for (char c : s) {
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) {
            return false;
        }
    }
    return true;
}

//bool isAlphabetic(const string& s) {
//    for (char c : s) {
//        if (!isalpha(c)) return false;
//    }
//    return true;
//}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << "The string " << (isAlphabetic(s) ? "contains" : "does not contain") << " only alphabetic characters." << endl;
    return 0;
}

