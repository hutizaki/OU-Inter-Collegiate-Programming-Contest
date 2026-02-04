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
#include <unordered_map>

using namespace std;

/*
    URL:https://open.kattis.com/problems/martiandna

    Group Members:
    - Bryan
    - Ethan

    Time to completion:
    00:50:00
*/
bool check_requirements(unordered_map<int, int> requirements, unordered_map<int, int> counter, int key){
        if (!counter[key] || counter.at(key)<requirements.at(key)){
            return false;
        }
    return true;
}

int main() {
    int N, K, R;

    cin >> N >> K >> R;

    int DNA[N];
    for (int i = 0; i < N; i++) {
        cin >> DNA[i];
    }

    unordered_map<int, int> requirements = unordered_map<int,int>();
    for (int i = 0; i<R; i++){
        int nucleotide, amount;
        cin >> nucleotide >> amount;
        requirements[nucleotide] = amount;
    }

    int l = 0;
    int r = 0;
    unordered_map<int, int> counter = unordered_map<int,int>();
    int min_length = N+1;
    int last_updated_key = -1;
    while (r < N +1 && l< r+1){

        // debug
        // cout << l << " " << r << endl;
        // for (auto count: counter){
        //     cout << count.first << " AAAA " << count.second << endl;
        // }

        if (check_requirements(requirements, counter, last_updated_key)){
            min_length = min(r - l, min_length);
            counter[DNA[l]]--;
            l++;
        }
        else{
            counter[DNA[r]]++;
            r++;
        }
    }

    if (min_length == N+1){
        cout << "impossible";
    }
    else{
        cout << min_length;
    }
    
    return 0;
}



