#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

/*
    Group Members:
    - Devin
    - Ethan
    - Bryan

    Time Completion: 3hrs
*/

class contestant {
public:
  int id = 0;
  int x;
  int y;
  int z;
  int a;
  int finalScore = 0;
  contestant(int counter, int problems, int penalty, int time, int inPerson);
  bool operator==(const contestant &other) {
    return (x == other.x && y == other.y && z == other.z);
  }
};

contestant::contestant(int counter, int problems, int penalty, int time, int inPerson) {
  id = counter;
  x = problems;
  y = penalty;
  z = time;
  a = inPerson;
}

bool comparator(const contestant &A, const contestant &B) {
  if (A.x != B.x)
    return A.x > B.x;
  if (A.y != B.y)
    return A.y < B.y;
  if (A.z != B.z)
    return A.z < B.z;
  return false;
}

void calcScore(vector<contestant> &allC, int score[]) {

  int left = 0;
  int right = 1;
  while (left < allC.size()) {
    right = left + 1;
    while (right < allC.size() && allC [left] == allC[right]) {
      right++;
    }
    double averageSum = 0;
    for (int i = left; i < right; i++) {
      if (i < 30) {
        averageSum += score[i];
      }
    }
    averageSum = ceil(averageSum / (right - left));
    for (int i = left; i < right; i++) {
      allC[i].finalScore = averageSum + allC[i].a;
      // cout << allC[i].finalScore << endl;
    }
    left = right;
  }
};

int main() {
  // index starts at "1" to show score for RANK
  int score[30] = {100, 75, 60, 50, 45, 40, 36, 32, 29, 26, 24, 22, 20, 18, 16,
                   15,  14, 13, 12, 11, 10, 9,  8,  7,  6,  5,  4,  3,  2,  1};

  int numC;
  cin >> numC;

  vector<contestant> allC;
  int counter;

  int final_scores[numC];
  while (numC--) {
    int x, y, z, a;

    cin >> x >> y >> z >> a;

    contestant person{counter, x, y, z, a};

    allC.push_back(person);
    counter++;
  }

  sort(allC.begin(), allC.end(), comparator);
  calcScore(allC, score);

  int answer[allC.size()];
  for (int i = 0; i < allC.size(); i++) {
    answer[allC[i].id] = allC[i].finalScore;
  }

  for (int i = 0; i < allC.size(); i++) {
    cout << answer[i+1] << endl;
  }
  return 0;
}