a = []


def check(row, col, num):

    # column
    for i in range(9):
        if a[i][col] == num:
            return False

    # row
    for j in range(9):
        if a[row][j] == num:
            return False

    # 3x3 box
    startRow = (row // 3) * 3
    startCol = (col // 3) * 3

    for i in range(startRow, startRow + 3):
        for j in range(startCol, startCol + 3):
            if a[i][j] == num:
                return False

    return True


def solve():

    for i in range(9):
        for j in range(9):

            if a[i][j] == 0:

                for num in range(1, 10):

                    if check(i, j, num):

                        a[i][j] = num

                        if solve():
                            return True

                        a[i][j] = 0

                return False

    return True


if __name__ == "__main__":

    for i in range(9):
        a.append(list(map(int, input().split())))

    if solve():

        for row in a:
            print(*row)

    else:
        print("No solution exists")