from time import sleep

"""
Conway's game of life uses the following set of rules to produce simulation :-
1. Any live cell with fewer than two live neighbours dies, as if by underpopulation.
2. Any live cell with two or three live neighbours lives on to the next generation.
3. Any live cell with more than three live neighbours dies, as if by overpopulation.
4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
"""

# host ground dimensions
x = 30
y = 40


def alive(matrix, i, j):
    if 0 <= i < x and 0 <= j < y:
        return 1 if matrix[i][j] == 'X' else 0
    return 0


def countNeighbours(matrix, i, j):
    count = alive(matrix, i - 1, j - 1) + alive(matrix, i - 1, j) + alive(matrix, i - 1, j + 1) + alive(matrix, i,
                                                                                                        j - 1) + \
            alive(matrix, i, j + 1) + alive(matrix, i + 1, j - 1) + alive(matrix, i + 1, j) + alive(matrix, i + 1,
                                                                                                    j + 1)

    isAlive = alive(matrix, i, j)
    return isAlive, count


def cglife():
    # 'matrix' produces first generation of organisms
    matrix = [['.' for _ in range(y)] for _ in range(x)]
    matrix[10][10] = matrix[10][11] = matrix[11][10] = matrix[12][10] = matrix[11][9] = 'X'

    while True:
        # 'mat' produces next generation of organisms
        mat = [['.' for _ in range(y)] for _ in range(x)]
        for i in range(x):
            for j in range(y):
                alive, count = countNeighbours(matrix, i, j)

                if alive == 1 and count > 3:
                    mat[i][j] = '.'
                elif alive == 1 and count < 2:
                    mat[i][j] = '.'
                elif alive == 0 and count == 3:
                    mat[i][j] = 'X'
                else:
                    mat[i][j] = matrix[i][j]

                print(matrix[i][j], end=' ')
            print()
        matrix = mat

        # slowing down the simulation for human eye to observe changes in generation properly
        sleep(0.62)


if __name__ == '__main__':
    cglife()
