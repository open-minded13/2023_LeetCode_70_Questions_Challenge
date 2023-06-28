class TreeNode:
    # Step 1: Create a Tree Node Class
    #         We'll start by creating a class to represent a node in the tree.
    #         Each node will have a value and a list of child nodes.
    def __init__(self, value):
        self.value = value
        self.children = []

    # Step 2: Implement Tree Operations
    #         Next, let's define some common operations you can perform on a tree:
    def add_child(self, child_node):
        self.children.append(child_node)

    def depth_first_traversal(self):
        print(self.value)
        for child in self.children:
            child.depth_first_traversal()

    def breadth_first_traversal(self):
        queue = [self]
        while queue:
            node = queue.pop(0)
            print(node.value)
            queue.extend(node.children)

    def count_nodes(self):
        count = 1
        for child in self.children:
            count += child.count_nodes()
        return count


# Create nodes
root = TreeNode("A")
node_b = TreeNode("B")
node_c = TreeNode("C")
node_d = TreeNode("D")
node_e = TreeNode("E")

# Build the tree
root.add_child(node_b)
root.add_child(node_c)
node_b.add_child(node_d)
node_b.add_child(node_e)

# Traverse the tree
print("Depth-First Traversal:")
root.depth_first_traversal()

print("Breadth-First Traversal:")
root.breadth_first_traversal()

# Count nodes
print("Number of Nodes:", root.count_nodes())
