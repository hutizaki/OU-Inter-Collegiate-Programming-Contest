// ### AI ###
/*
    Optimized sliding window solution:
    Tracks how many requirement types are currently satisfied (formed).
    Each pointer moves at most N times -> O(N).
*/
// ### AI ###

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int N, K, R;

    cin >> N >> K >> R;

    vector<int> DNA(N);
    for (int i = 0; i < N; i++) {
        cin >> DNA[i];
    }

    unordered_map<int, int> requirements;
    for (int i = 0; i < R; i++) {
        int nucleotide, amount;
        cin >> nucleotide >> amount;
        requirements[nucleotide] = amount;
    }

    // ### AI ###
    unordered_map<int, int> counter;

    int required_types = requirements.size();
    int formed = 0;

    int l = 0;
    int min_length = N + 1;

    for (int r = 0; r < N; r++) {

        int add = DNA[r];
        counter[add]++;

        // If this nucleotide just satisfied requirement
        if (requirements.count(add) &&
            counter[add] == requirements[add]) {
            formed++;
        }

        // Try shrinking window while valid
        while (formed == required_types && l <= r) {

            min_length = min(min_length, r - l + 1);

            int remove = DNA[l];
            counter[remove]--;

            // If removing breaks requirement
            if (requirements.count(remove) &&
                counter[remove] == requirements[remove] - 1) {
                formed--;
            }

            l++;
        }
    }
    // ### AI ###

    if (min_length == N + 1) {
        cout << "impossible";
    } else {
        cout << min_length;
    }

    return 0;
}
