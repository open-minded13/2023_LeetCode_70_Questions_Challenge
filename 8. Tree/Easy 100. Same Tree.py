# Time Complexity: O(N), where N is the total number of nodes in the linked list 1 and 2.
#                  This is because the solution iterates all the nodes in the linked list.
#
# Space Complexity: O(1). This is because it uses a constant amount of additional space.
#                   The method only utilizes a variable (current_result),
#                   regardless of the size of the input linked list.


from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        # Check if both nodes are None (reached the end of the tree).
        if p is None and q is None:
            return True

        # Check if either one of the nodes is None (tree structures differ).
        if p is None or q is None:
            return False

        # Check if the values of the nodes are different.
        if p.val != q.val:
            return False

        # Recursively check if the left and right subtrees are the same.
        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)


# Test Cases
# Example 1:
#   Tree 1        Tree 2
#     1            1
#    / \          / \
#   2   3        2   3
p1 = TreeNode(1, TreeNode(2), TreeNode(3))
q1 = TreeNode(1, TreeNode(2), TreeNode(3))
print(Solution().isSameTree(p1, q1))  # Output: True

# Example 2:
#   Tree 1        Tree 2
#     1            1
#    /            /
#   2            2
p2 = TreeNode(1, TreeNode(2))
q2 = TreeNode(1, None, TreeNode(2))
print(Solution().isSameTree(p2, q2))  # Output: False

# Example 3:
#   Tree 1        Tree 2
#     1            1
#    / \          / \
#   2   1        1   2
p3 = TreeNode(1, TreeNode(2), TreeNode(1))
q3 = TreeNode(1, TreeNode(1), TreeNode(2))
print(Solution().isSameTree(p3, q3))  # Output: False

# Additional Test Case:
# Both trees are empty
p4 = None
q4 = None
print(Solution().isSameTree(p4, q4))  # Output: True

# Additional Test Case:
# Tree 1 is empty, Tree 2 has one node with value 1
p5 = None
q5 = TreeNode(1)
print(Solution().isSameTree(p5, q5))  # Output: False
