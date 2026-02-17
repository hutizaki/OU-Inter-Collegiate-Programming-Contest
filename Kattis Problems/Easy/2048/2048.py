"""
STRUCTURE FOR AI AGENTS:
- Keep the header block below (URL, Group Members, Time to completion).
- Put problem notes / scratch work in comment blocks above main().
- When adding or modifying code, wrap AI-added sections with:
    # ### AI ###
    ... code or comment ...
    # ### AI ###
  so it's easy to find and review later.
"""

"""
    URL:https://open.kattis.com/problems/2048

    Group Members:
    - Bryan
    - Ethan
    - JP
    - Ari
    - Dom
    - Angela

    Time to completion:

"""


def main():
    # ### AI ###
    # Read 4x4 grid lines into arrays and optionally read a direction line.
    import sys
 
    fname = sys.argv[1] if len(sys.argv) > 1 else None
    f = open(fname) if fname else sys.stdin

    grid = []
    for _ in range(4):
        line = f.readline()
        if not line:
            break
        row = list(map(int, line.strip().split()))
        grid.append(row)

    dir_line = f.readline().strip()
    direction = int(dir_line) if dir_line else None

    if fname:
        f.close()
    # ### AI ###
    # For now do not perform any moves — just expose parsed arrays.
    
    # Shift column:
        # start at the bottom for DOWN shift
        # for i range(4:):
            # 

    def shiftList(lst, dir):
        # one is right and down
        if dir == 1:
            for i in range(3, -1, -1):
                # now i is 3
                j = i - 1
                while j > -1:
                    if lst[j] == 0:
                        j -= 1
                        continue
                    elif lst[j] == lst[i]:
                        lst[i] = lst[i] * 2
                        lst[j] = 0
                        break
                    else:
                        i = j
                        break

        # one is left and up
        if dir == 0:
            for i in range(4):
                # now i is 3
                if i == 3:
                    break
                j = i + 1
                while j < 4:
                    if lst[j] == 0:
                        j += 1
                        continue
                    elif lst[j] == lst[i]:
                        lst[i] = lst[i] * 2
                        lst[j] = 0
                        break
                    else:
                        i = j
                        break


    
    def move(dir):

        if dir == 0 or dir == 2:
            # if direction left or right pass in rows
            for row in grid:
                shiftList(row, 1 if dir == 2 else 0)

        if dir == 1 or dir == 3:
            # if direction left or right pass in rows
            for col in grid[0]:
                shiftList(row, 1 if dir == 2 else 0)

    
    move(direction)

    for row in grid:
        print(" ".join(map(str, row)))

if __name__ == "__main__":
    main()
# python3 "Kattis Problems/Easy/2048/2048.py" < "Kattis Problems/Easy/2048/input1.txt" 