#include <bits/stdc++.h>

using namespace std;

int LongestSubstring(string s) {
    unordered_map<char, int> mpp;
    int Len = 0, start = 0;
    for (int end = 0; end < s.size(); ++end) {
        if (mpp.find(s[end]) != mpp.end()) {
            start = max(start, mpp[s[end]] + 1);
        }
        mpp[s[end]] = end;
        Len = max(Len, end - start + 1);
    }
    return Len;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << "Length of the longest substring without repeating characters: " << LongestSubstring(s) << endl;
    return 0;
}

