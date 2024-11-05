# reverse a list
lst = [1, 2, 3 ,4]
print(f"Reversing a list...")
print(f"Original: {lst}")
print(f"Reversed: {lst[::-1]}\n")

# [::-1]
# double colon ::
#   - used to specify a step without stating a start and stop
#   - '-1' means to "go backwards" from last element to 0
#   - useful operation for rotating a 2D matrix

# Rotating a n x n 2D matrix
matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9],
]

# with extra memory
def rotate_matrix_90(matrix):
    """
    

    [1, 2, 3]       [7, 4, 1]
    [4, 5, 6]   ->  [8, 5, 2]
    [7, 8, 9]       [9, 6, 3]

    i = row
    j = column

    My intuition: The rows now become columns. So i will contribute to the column change.
                  The columns become rows. So j will affect the row change.

                  we subtract i because we want i to have no effect when shifting right and down, and a 
                  strong effect when shifing left and up.

                  we have n - 1 due to 0 indexing, and n due to wanting to shift the corners the whole matrix
                  and then adjust based on the current i offset

                  so therefore the new row is [j] and the new column is [n - 1 - i]

    Elements swap like:
        n = 3
        [i][j] -> [j][n - 1 - i]
        [0][0] -> [0][2]

        [0][2] -> [2][2]

        [2][2] -> [2][0]

        [2][0] -> [0][0]
    """
    n = len(matrix)
    rotated = [[0 for _ in range(n)] for _ in range(n)]

    for i in range(n):
        for j in range(n):
            rotated[j][n - 1 - i] = matrix[i][j]

    return rotated

# modified in place
def rotate_matrix_in_place(matrix):
    pass

print("Rotating matrix 90 degrees...")
print("Original:")
for row in matrix:
    print(row)

print("\n")
print("Rotated matrix:")
for row in rotate_matrix_90(matrix):
    print(row)