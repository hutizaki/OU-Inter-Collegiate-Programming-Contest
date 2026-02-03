/*
 * STRUCTURE FOR AI AGENTS:
 * - Keep the header block below (URL, Group Members, Time to completion).
 * - Put problem notes / scratch work in comment blocks above main().
 * - When adding or modifying code, wrap AI-added sections with:
 *     // ### AI ###
 *     ... code or comment ...
 *     // ### AI ###
 *   so it's easy to find and review later.
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
    URL:https://open.kattis.com/problems/martiandna

    Group Members:
    - Bryan
    - Ethan

    Time to completion:
    00:50:00
*/

int main() {
    int N, K, R;

    cin >> N >> K >> R;

    char DNA[N];
    for (int i = 0; i < N; i++) {
        cin >> DNA[i];
    }

    string sDNA(DNA);

    vector<string> PAIRS;
    char pair[R];
    for (int i = 0; i < 2*R; i++) {
        cin >> pair[i % 2];
        if (i % 2 == 1) {
            string str(pair);
            //cout << str << " ";
            PAIRS.push_back(str);
        }
    }
    vector<int> answer;
    for (int i = 0; i < R; i++) {
      int found = sDNA.find(PAIRS[i]);
        if (found != -1) {
            //cout << "here";
            found+=2;
            //cout << found;
            answer.push_back(found);
        }
    }

    //cout << sDNA << endl;

    sort(answer.begin(), answer.end());
    
    if (answer.size()==0) {
        cout << "impossible" << endl;
    }
    else {
    cout << answer[0] << endl; 
    }
    return 0;
}
