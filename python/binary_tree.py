class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def print_binary_tree(root):
    """
    Print a binary tree in a more visually appealing way.
    This works better in most terminals and handles various tree shapes.
    """
    def get_height(node):
        return 0 if node is None else 1 + max(get_height(node.left), get_height(node.right))
    
    def get_width(node):
        return 0 if node is None else 1 + get_width(node.left) + get_width(node.right)
    
    height = get_height(root)
    width = get_width(root)
    
    # Create a matrix to represent the tree
    matrix = [[' ' for _ in range(width * 2)] for _ in range(height * 2)]
    
    def fill_matrix(node, row, left, right):
        if node is None:
            return
        
        col = (left + right) // 2
        matrix[row][col] = str(node.val)
        
        # Draw connections to children
        if node.left:
            matrix[row + 1][col - 1] = '/'
            fill_matrix(node.left, row + 2, left, col)
        
        if node.right:
            matrix[row + 1][col + 1] = '\\'
            fill_matrix(node.right, row + 2, col, right)
    
    fill_matrix(root, 0, 0, width * 2 - 1)
    
    # Print the matrix
    for row in matrix:
        # Trim trailing spaces and print
        print(''.join(row).rstrip())


def build_tree_from_list(elements, index=0):
    # - num elements at depth n will be 2^n
    # - for an element at index i, its left and right child
    #   will be at 2*i + 1 and 2*i + 2 respectively
    if index >= len(elements) or elements[index] is None:
        return None
    
    root = TreeNode(elements[index])

    # recursively build left and right subtrees
    root.left = build_tree_from_list(elements, 2 * index + 1)
    root.right = build_tree_from_list(elements, 2 * index + 2)

    return root