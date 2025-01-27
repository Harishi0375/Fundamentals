class TreeNode:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

def in_order_traversal(root):
    # This list will hold the traversal result.
    result = []
    def traverse(node):
        if node:
            # Traverse the left subtree
            traverse(node.left)
            # Visit the node
            result.append(node.val)
            # Traverse the right subtree
            traverse(node.right)
    
    traverse(root)
    return result
