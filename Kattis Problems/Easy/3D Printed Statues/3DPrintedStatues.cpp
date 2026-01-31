#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/*
    URL: https://open.kattis.com/problems/3dprinter
    
    Group Members:
    - Bryan

    Time to completion:
    00:39:02 only passed 2 tests
    Going to AI for help
*/

/*
    You can either use a 3D printer to print a statue, or another 3D printer

    Each print takes 1 day



    n = 5

    only 1 printer means 5 days

    or day 1 make one
    day 2 you can do 2 at a time

    num print    day     remaining
        1         1         5
        2         2         5
        2         3         3
        2         4         1
        2         5         0  


    Num printers = num statues per day

    5 4 3 2 1   -1
    5 5 3 1 0   -2
    5 5 5 1 0   -4


    6 5 4 3 2 1     -1
    6 6 4 2 0 0     -2
    6 6 6 2 0 0     -4


    7 6 5 4 3 2 1    -1
    7 7 5 3 1 0 0    -2   
    7 7 7 3 0 0 0    -4


    8 7 6 5 4 3 2 1
    8 8 6 4 2 0
    8 8 8 4 0
    8 8 8 8 0
    Brute force approach, try each iteration, but then double the subtraction (num printers doubles per day) and find the min num days
*/


/*
    AI Help:
    - After 0 days: 1 printer
    - After 1 day building: 2 printers
    - After 2 days building: 4 printers
    - After 3 days building: 8 printers
    So after k days of building you have 2^k printers, not 2k.
*/



int main() {
    int numStatues;

    cin >> numStatues;

    vector<int> days;

    for (int daysUsedForPrinter = 0; daysUsedForPrinter < numStatues; daysUsedForPrinter++) {
        int remainingStatues = numStatues;

        // ### AI ###
        // After k days of building, you have 2^k printers (each day doubles: 1→2→4→8...)
        int printCapacity = (daysUsedForPrinter == 0) ? 1 : (1 << daysUsedForPrinter);
        // ### AI ###

        int numDays = daysUsedForPrinter;
        while (remainingStatues > 0) {
            remainingStatues -= printCapacity;
            numDays++;
        }

        days.push_back(numDays);
    }

    auto min_ptr = min_element(days.begin(), days.end());
    int min_value = *min_ptr;

    cout << min_value;
    return 0;
}