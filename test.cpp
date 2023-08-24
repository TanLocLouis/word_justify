#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();

        int start = 0, len = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            len += words[i].length(); cnt++;
            if (i + 1 != n && len + words[i + 1].length() + cnt > maxWidth) {
                string res = "";
                res += words[start];

                if (cnt > 1) {
                    int div = (maxWidth - len) / (cnt - 1);
                    int mod = (maxWidth - len) % (cnt - 1);
                    for (int k = start + 1; k <= start + cnt - 1; k++) {
                        if (mod) {
                            res += char(32);
                            mod--;
                        }
                        for (int j = 0; j < div; j++) res += char(32); res +=  words[k];
                    }
                }
                
                if (cnt == 1) {
                    int remain = maxWidth - res.length();
                    for (int k = 0; k < remain; k++) res += char(32);
                }
                ans.push_back(res);

                start += cnt;
                len = 0; 
                cnt = 0;
            }

            if (i + 1 == n) {
                string res = "";
                res += words[start];

                for (int k = start + 1; k <= start + cnt - 1; k++) 
                    res += char(32) + words[k];
                
                int remain = maxWidth - res.length();
                for (int k = 0; k < remain; k++)
                    res += char(32);

                ans.push_back(res);
            }
        }
       
        return ans;
    }
};

vector<string> getData() {
    cout << "----AUTO ALIGN TEST----" << endl;
    cout << "--Made by TanLocLouis--" << endl;
    cout << endl;
    cout << "Input data: ";
    string s; 
    getline(cin, s);

    stringstream ss(s);
    string w;
    vector<string> res;
    while (ss >> w) {
        res.push_back(w);
    }

    return res;
}

int main() {
    vector<string> words = getData();
    int maxWidth;
    cout << "Input width: ";
    cin >> maxWidth;

    Solution Sol;
    vector<string> ans = Sol.fullJustify(words, maxWidth);
    for (string s : ans) cout << s << endl;
    cout << endl;
}
