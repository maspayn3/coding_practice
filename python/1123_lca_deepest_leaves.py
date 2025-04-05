from binary_tree import TreeNode, print_binary_tree, build_tree_from_list


def lca_deepest_leaves(root):
    # return (LCA, depth) 
    def dfs(root: TreeNode, curr_depth=0):
        if root is None:
            return (None, curr_depth + 1)

        print(f"At {root.val}")

        left_node, left_depth = dfs(root.left, curr_depth + 1)
        right_node, right_depth = dfs(root.right, curr_depth + 1)

        if left_depth > right_depth: 
            return left_node, left_depth
        elif left_depth < right_depth:
            return right_node, right_depth
        print(f"Found potential solution. Node: {root.val}")
        return root, left_depth
        
    root, _ = dfs(root, 0)
    return root

def main():
    root = build_tree_from_list([3,5,1,6,2,0,8,None,None,7,4])
    root1 = build_tree_from_list([0,1,3,None,2])
    lca_deepest_leaves(root)


if __name__ == '__main__':
    main()