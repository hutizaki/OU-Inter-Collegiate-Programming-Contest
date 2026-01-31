#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class contestant {
public:
    int x, y, z, a;
    int finalScore = 0;
    int id;

    contestant(int problems, int penalty, int time, int inPerson, int idx)
        : x(problems), y(penalty), z(time), a(inPerson), id(idx) {}

    bool operator==(const contestant &o) const {
        return x == o.x && y == o.y && z == o.z;
    }
};

bool comparator(const contestant &A, const contestant &B) {
    if (A.x != B.x) return A.x > B.x;
    if (A.y != B.y) return A.y < B.y;
    if (A.z != B.z) return A.z < B.z;
    return false;
}

int rankScore(int r) {
    static int scores[30] = {
        100, 75, 60, 50, 45, 40, 36, 32, 29, 26,
        24, 22, 20, 18, 16, 15, 14, 13, 12, 11,
        10, 9, 8, 7, 6, 5, 4, 3, 2, 1
    };
    if (r <= 30) return scores[r - 1];
    return 0;
}

int main() {
    int n;
    cin >> n;

    vector<contestant> v;
    for (int i = 0; i < n; i++) {
        int x, y, z, a;
        cin >> x >> y >> z >> a;
        v.emplace_back(x, y, z, a, i);
    }

    sort(v.begin(), v.end(), comparator);

    int i = 0;
    while (i < n) {
        int j = i;
        while (j < n && v[i] == v[j]) j++;

        double sum = 0;
        for (int k = i; k < j; k++) {
            sum += rankScore(k + 1);
        }
        int avg = ceil(sum / (j - i));

        for (int k = i; k < j; k++) {
            v[k].finalScore = avg + v[k].a;
        }

        i = j;
    }

    // Restore input order
    vector<int> ans(n);
    for (auto &c : v)
        ans[c.id] = c.finalScore;

    for (int x : ans)
        cout << x << endl;
}