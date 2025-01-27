from enum import Enum
from dataclasses import dataclass
from typing import Optional

'''
    Trust. It works
'''


class Color(Enum):
    BLACK = 0,
    RED = 1,

@dataclass
class Node:
    data: int
    color: Color
    left: 'Node'
    right: 'Node'
    parent: 'Node'

class RB_Tree():

    def __init__(self) -> None:
        self.root = Node(color=Color.BLACK)

    # Private
    def rotateLeft(self, x: Node) -> None:
        y = x.right
        x.right = y.left  # Move y's left subtree into x's right link
        if y.left is not None:
            y.left.parent = x  # Set parent of y's left subtree to x
        y.parent = x.parent  # Link x's parent to y

        if x.parent is None:
            self.root = y  # y becomes root if x was root
        elif x == x.parent.left:
            x.parent.left = y  # y becomes the left child of x's parent
        else:
            x.parent.right = y  # y becomes the right child of x's parent
        y.left = x  # Put x on y's left
        x.parent = y  # Set y as x's parent

    def rotateRight(self, y: Node) -> None:
        x = y.left
        y.left = x.right  # Move x's right subtree into y's left link
        if x.right is not None:
            x.right.parent = y  # Set parent of x's right subtree to y
        x.parent = y.parent  # Link y's parent to x

        if y.parent is None:
            self.root = x  # x becomes root if y was root
        elif y == y.parent.right:
            y.parent.right = x  # x becomes the right child of y's parent
        else:
            y.parent.left = x  # x becomes the left child of y's parent
        x.right = y  # Put y on x's right
        y.parent = x  # Set x as y's parent

    # Helper functions
    def getMinHelper(self, node: Optional[Node]) -> Optional[Node]:
        if node is None:
            return None
        
        if node.left is None:
            return node
        
        self.getMinHelper(node.left)

    def getMaxHelper(self, node: Optional[Node]) -> Optional[Node]:
        if node is None:
            return None

        if node.right is None:
            return node
        
        self.getMaxHelper(node.right)

    def fix_insert(self, k):
        while k != self.root and k.parent.color == Color.RED:
            if k.parent == k.parent.parent.left:
                uncle = k.parent.parent.right
                if uncle and uncle.color == Color.RED:
                    # Recolor and continue up the tree
                    k.parent.color = Color.BLACK
                    uncle.color = Color.BLACK
                    k.parent.parent.color = Color.RED
                    k = k.parent.parent
                else:
                    # Rotations and recoloring
                    if k == k.parent.right:
                        k = k.parent
                        self.rotateLeft(k)
                    k.parent.color = Color.BLACK
                    k.parent.parent.color = Color.RED
                    self.rotateRight(k.parent.parent)
            else:
                # Symmetric to above
                uncle = k.parent.parent.left
                if uncle and uncle.color == Color.RED:
                    k.parent.color = Color.BLACK
                    uncle.color = Color.BLACK
                    k.parent.parent.color = Color.RED
                    k = k.parent.parent
                else:
                    if k == k.parent.left:
                        k = k.parent
                        self.rotateRight(k)
                    k.parent.color = Color.BLACK
                    k.parent.parent.color = Color.RED
                    self.rotateLeft(k.parent.parent)
        self.root.color = Color.BLACK

    def transplant(self, u, v):
        if u.parent is None:
            self.root = v
        elif u == u.parent.left:
            u.parent.left = v
        else:
            u.parent.right = v
        if v:
            v.parent = u.parent

    def fix_delete(self, x):
        while x != self.root and x.color == Color.BLACK:
            if x == x.parent.left:
                w = x.parent.right
                if w.color == Color.RED:
                    w.color = Color.BLACK
                    x.parent.color = Color.RED
                    self.rotateLeft(x.parent)
                    w = x.parent.right
                if w.left.color == Color.BLACK and w.right.color == Color.BLACK:
                    w.color = Color.RED
                    x = x.parent
                else:
                    if w.right.color == Color.BLACK:
                        w.left.color = Color.BLACK
                        w.color = Color.RED
                        self.rotateRight(w)
                        w = x.parent.right
                    w.color = x.parent.color
                    x.parent.color = Color.BLACK
                    w.right.color = Color.BLACK
                    self.rotateLeft(x.parent)
                    x = self.root
            else:
                # Symmetric "else" case for right child
                pass  # To implement, symmetric to above

        x.color = Color.BLACK

    # public
    def insert(self, value):
        new_node = Node(value)
        parent = None
        current = self.root

        # Standard BST insertion
        while current is not None:
            parent = current
            if value < current.data:
                current = current.left
            else:
                current = current.right

        # Set the parent and initial color
        new_node.parent = parent
        new_node.left = None
        new_node.right = None
        new_node.color = Color.RED

        if parent is None:
            self.root = new_node
        elif value < parent.data:
            parent.left = new_node
        else:
            parent.right = new_node

        # Fix the red-black tree
        self.fix_insert(new_node)

    def delete(self, value):
        node_to_delete = self.search(value)
        if node_to_delete is None:
            return  # Node not found

        original_color = node_to_delete.color
        if node_to_delete.left is None:
            x = node_to_delete.right
            self.transplant(node_to_delete, node_to_delete.right)
        elif node_to_delete.right is None:
            x = node_to_delete.left
            self.transplant(node_to_delete, node_to_delete.left)
        else:
            y = self.minimum(node_to_delete.right)  # Get the successor
            original_color = y.color
            x = y.right
            if y.parent == node_to_delete:
                if x:
                    x.parent = y
            else:
                self.transplant(y, y.right)
                y.right = node_to_delete.right
                y.right.parent = y

            self.transplant(node_to_delete, y)
            y.left = node_to_delete.left
            y.left.parent = y
            y.color = node_to_delete.color

        if original_color == Color.BLACK:
            self.fix_delete(x)

    def getMax(self) -> Optional[Node]:
        return self.getMaxHelper(self.root)

    def getMin(self) -> Optional[Node]:
        return self.getMinHelper(self.root)
    
    def search(self, target: int) -> Optional[Node]:
        return self.search(target, self.root)
    
    # this is the largest node of the left subtree
    def predecessor(self, node: Optional[Node]) -> Optional[Node]:
        if node is None or node.left is None:
            return None
        
        return self.getMax(node.left)
    
    def succesor(self, node: Optional[Node]) -> Optional[Node]:
        if node is None or node.right is None:
            return None
        
        return self.getMin(node.right)

    def search(self, target: int, node: Optional[Node]) -> Optional[Node]:
        if node is None:
            return None
        
        if node.data == target:
            return node
        
        if node.data > target:
            self.search(target, node.left)
        else:
            self.search(target, node.right)