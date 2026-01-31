#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Returns how many values in sorted array "arr" are >= x
static long long count_at_least(const vector<long long> &arr, long long x) {
  auto first_ge = lower_bound(arr.begin(), arr.end(), x);
  return static_cast<long long>(arr.end() - first_ge);
}

// Returns how many prefix sums are <= budget
// (i.e., how many levels can be completed with "budget" strikes)
static long long levels_with_budget(const vector<long long> &prefix,
                                    long long budget) {
  auto first_gt = upper_bound(prefix.begin(), prefix.end(), budget);
  return static_cast<long long>(first_gt - prefix.begin());
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 0;
  cin >> t;

  while (t--) {
    int n = 0;
    cin >> n;

    vector<long long> sword_strength(n);
    for (int i = 0; i < n; i++)
      cin >> sword_strength[i];

    vector<long long> strikes_needed(n);
    for (int i = 0; i < n; i++)
      cin >> strikes_needed[i];

    // prefix[i] = total strikes needed to beat levels 1..(i+1)
    vector<long long> prefix(n);
    long long running_sum = 0;
    for (int i = 0; i < n; i++) {
      running_sum += strikes_needed[i];
      prefix[i] = running_sum;
    }

    sort(sword_strength.begin(), sword_strength.end());

    long long best_score = 0;

    // Only difficulties equal to some sword strength matter.
    // Iterate unique strengths in the sorted list.
    for (int i = 0; i < n;) {
      long long difficulty = sword_strength[i];

      long long usable_strikes = count_at_least(sword_strength, difficulty);
      long long levels_completed = levels_with_budget(prefix, usable_strikes);

      best_score = max(best_score, difficulty * levels_completed);

      // Skip duplicates of this difficulty
      int j = i;
      while (j < n && sword_strength[j] == difficulty)
        j++;
      i = j;
    }

    cout << best_score << '\n';
  }

  return 0;
}
