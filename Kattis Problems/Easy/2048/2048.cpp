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

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
    URL:

    Group Members:
    - Bryan
    - Ethan
    - Angela
    - Ari

    Time to completion:
    - 1:41:45
*/

// int == 1 UP, start on top
// int == 3 DOWN, start on bottom
void shiftCol(int (&mat)[4][4], int dir) {
    if (dir == 1) //up
    {
        for (int j = 0; j < 4; j++) {
            int start = 0;
            int last = 0;
            for (int i = 0; i < 4; i++) {
                    int current = mat[i][j];
                    if (current == 0) continue;
                    if (last == 0) {
                        last = current;
                    }
                    else if (last == current) {
                        mat[start][j] = last * 2;
                        start++;
                        last = 0;
                    }
                    else {
                        mat[start][j] = last;
                        start++;
                        last = current;
                    } 
            }
            if (last != 0) {
                mat[start][j] = last;
                start++;
            }
            while (start < 4) {
                mat[start][j] = 0;
                start++;
            }
        }
    }
    else if (dir == 3) //down 
    {
        for (int j = 0; j < 4; j++) {
            int start = 3;
            int last = 0;
            for (int i = 3; i >= 0; i--) {
                    int current = mat[i][j];
                    if (current == 0) continue;
                    if (last == 0) {
                        last = current;
                    }
                    else if (last == current) {
                        mat[start][j] = last * 2;
                        start--;
                        last = 0;
                    }
                    else {
                        mat[start][j] = last;
                        start--;
                        last = current;
                    } 
            }
            if (last != 0) {
                mat[start][j] = last;
                start--;
            }
            while (start >= 0) {
                mat[start][j] = 0;
                start--;
            }
        }
    }
}

// int == 0 LEFT start at front
// int == 2 RIGHT start at back
void shiftRow(int (&mat)[4][4], int dir) {

    //Shift left
    if(dir == 0) {
        for(int row = 0; row < 4; row++){
            for(int col = 0; col < 3; col++) {
                int first = mat[row][col];
                int next = mat[row][col+1];

                if(first == 0) {
                    int move = col;
                    while (first == 0 && move < 4) {
                        for (int shift = col; shift < 3; shift++){
                            mat[row][shift] = mat[row][shift+1];
                        }
                        mat[row][3] = 0;

                        //check if it is still 0 at that column
                        move++;
                        first = mat[row][move];

                    }   
                }
                else if (first == next) {
                    mat[row][col] = first + next;
                    for (int shift = col; shift < 3; shift++){
                        mat[row][shift] = mat[row][shift+1];
                    }
                    mat[row][3] = 0;
                
                }

            }
        }
    }
    //Shift right
     if(dir == 2) {
        for(int row = 0; row < 4; row++){
            for(int col = 3; col > -1; col--) {
                int first = mat[row][col];
                int next = mat[row][col-1];

                if(first == 0) {
                    //perform shift right
                    for (int shift = col; shift > -1; shift--){
                        mat[row][shift] = mat[row][shift-1];
                    }
                    mat[row][0] = 0;

                    //check if it is still 0
                    first = mat[row][col];
                }
                else if (first == next) {
                    mat[row][col] = first + next;
                    for (int shift = col; shift > 0; shift--){
                        mat[row][shift] = mat[row][shift-1];
                    }
                    mat[row][0] = 0;
                }

            }
        }
    }
}
void mergeRow(int (&mat)[4][4], int dir)
{
    for( int r = 0; r<4; r++)
    {
        if(dir == 0)
        {
            for(int c = 0; c <3; c++)
            {
                if(mat[r][c] != 0 && mat[r][c] == mat[r][c+1]) {
                    mat[r][c] *= 2;
                    mat[r][c+1] = 0;
                    
                }
            }
        }
        else{
            for(int c = 3; c > 0; c--)
            {
                if(mat[r][c] != 0 && mat[r][c] == mat[r][c-1]) {
                    mat[r][c] *= 2;
                    mat[r][c-1] = 0;
                    
                }
            }
        }
    }
}



int main() {

    int grid[4][4];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> grid[i][j];
        }
    }

    int direction;

    cin >> direction;

    if (direction % 2 == 0) {
        shiftRow(grid,direction);
    }
    else {
        shiftCol(grid,direction);
    }
    
    //print matrix
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}