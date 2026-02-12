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
#include <cmath>

using namespace std;

/*
    URL: https://open.kattis.com/problems/smallschedule

    Group Members:
    - Bryan
    - Devin
    - Ethan

    Time to completion:
    40:00
*/

/*
    spread the large jobs across all machines at first, then take the 1 second jobs, 
    and fill up the next available machine UNTIL it matches the MAX from the other machines,
    THEN go to the next machine and repeat the same. IF over filled, spread the 1 second jobs across.
*/

int main() {
    int num_Machines, num_big_jobs, num_small_jobs, big_job_size;

    cin >> big_job_size >> num_Machines >> num_small_jobs >> num_big_jobs;

    /*
        divy the large jobs by num_machines
    */
    int big_jobs_per_machine = (num_big_jobs) / num_Machines;
    int seconds_per_machine = big_jobs_per_machine * big_job_size;
    int remainder = num_big_jobs % num_Machines;

    if (remainder != 0) {
        seconds_per_machine += big_job_size;
        num_small_jobs -= ((num_Machines - remainder) * big_job_size);
        if (num_small_jobs < 0) num_small_jobs = 0;
    }

    seconds_per_machine += ceil((double) num_small_jobs / num_Machines);

    cout << seconds_per_machine;
    return 0;
}
