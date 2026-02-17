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
#include <vector>
#include <algorithm>

using namespace std;

/*
    URL:https://open.kattis.com/problems/asciikassi2

    Group Members:
    - Bryan
    - Ethan
    - Devin

    Time to completion:
    00:24:43
*/

void printWhiteSpace(int n) {
  for (int i = 0; i < n; i++) {
    cout << " ";
  }
}

int main() {
    int n;
    cin >> n;

    int prefixPadding = n + 1;
    int middlePadding = 1;

    for (int i = 0; i< 2*(n+1)+1; i++){
        printWhiteSpace(prefixPadding);

        if (i == 0 || i == 2*(n+1)){
            cout << "x\n";
            prefixPadding--;
            continue;
        }
        else if (i == n + 1){
            cout << "x";
        }
        else if (i < n+1){
            cout << "/";
        }
        else {
            cout << "\\";
        }

        printWhiteSpace(middlePadding);

        if (i == n + 1) {
          cout << "x\n";
          prefixPadding++;
          middlePadding-=2;
        }
        else if (i < n+1){
          cout << "\\\n";
          prefixPadding--;
          middlePadding+=2;
        }
        else{
            cout << "/\n";
            prefixPadding++;
            middlePadding-=2;
        }
    }
    return 0;
}
