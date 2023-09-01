# bst.py
# ===================================================
# Implement a binary search tree that can store any
# arbitrary object in the tree.
# ===================================================


class Student:
    def __init__(self, number, name):
        self.grade = number  # this will serve as the object's key
        self.name = name

    def __lt__(self, kq):
        if(self.grade < kq.grade):
            return True
        else:
            return False

    def __gt__(self, kq):
        if(self.grade > kq.grade):
            return True
        else:
            return False

    def __eq__(self, kq):
        if(self.grade == kq.grade):
            return True
        else:
            return False

    def __str__(self):
        if self.grade is not None:
            return str(self.grade) 

class TreeNode:
    def __init__(self, val):
        self.left = None
        self.right = None
        self.val = val  # when this is a primitive, this serves as the node's key


class BST:
    def __init__(self, start_tree=None) -> None:
        """ Initialize empty tree """
        self.root = None
        
        # populate tree with initial nodes (if provided)
        if start_tree is not None:
            for value in start_tree:
                self.add(value)

    def __str__(self):
        """
        Traverses the tree using "in-order" traversal
        and returns content of tree nodes as a text string
        """
        values = [str(_) for _ in self.in_order_traversal()]
        return "TREE in order { " + ", ".join(values) + " }"

    def add(self, val):
        """
        Creates and adds a new node to the BSTree.
        If the BSTree is empty, the new node should added as the root.

        Args:
            val: Item to be stored in the new node
        """
        if(self.root is None):
            self.root = TreeNode(val)
        else:
            newNode = TreeNode(val)
            curr = self.root
            while(curr != None):
                P = curr
                if(val < curr.val):   
                    if(curr.left is None):
                        curr.left = newNode
                        break
                    else:
                        curr = curr.left
                else:
                    if(curr.right is None):
                        curr.right = newNode
                        break
                    curr = curr.right 

    def in_order_traversal(self, cur_node=None, visited=None) -> []:
            """
            Perform in-order traversal of the tree and return a list of visited nodes
            """
            if visited is None:
                # first call to the function -> create container to store list of visited nodes
                # and initiate recursive calls starting with the root node
                visited = []
                self.in_order_traversal(self.root, visited)

            # not a first call to the function
            # base case - reached the end of current subtree -> backtrack
            if cur_node is None:
                return visited

            # recursive case -> sequence of steps for in-order traversal:
            # visit left subtree, store current node value, visit right subtree
            self.in_order_traversal(cur_node.left, visited)
            visited.append(cur_node.val)
            self.in_order_traversal(cur_node.right, visited)
            return visited

    def pre_order_traversal(self, cur_node=None, visited=None) -> []:
        """
        Perform pre-order traversal of the tree and return a list of visited nodes

        Returns:
            A list of nodes in the specified ordering
        """
        if visited is None:
            visited = []
            self.pre_order_traversal(self.root, visited)

        if cur_node is None:
            return visited

        visited.append(cur_node.val)
        self.pre_order_traversal(cur_node.left, visited)
        self.pre_order_traversal(cur_node.right, visited)
        return visited

    def post_order_traversal(self, cur_node=None, visited=None) -> []:
        """
        Perform post-order traversal of the tree and return a list of visited nodes

        Returns:
            A list of nodes in the specified ordering
        """

        if visited is None:
            visited = []
            self.post_order_traversal(self.root, visited)

        if cur_node is None:
            return visited

        self.post_order_traversal(cur_node.left, visited)
        self.post_order_traversal(cur_node.right, visited)
        visited.append(cur_node.val)
        return visited

    def contains(self, kq):
        """
        Searches BSTree to determine if the query key (kq) is in the BSTree.

        Args:
            kq: query key

        Returns:
            True if kq is in the tree, otherwise False
        """
        in_order = self.in_order_traversal()
        for i in in_order:
            if(kq == i):
                return True
        return False

    def left_child(self, node):
        """
        Returns the left-most child in a subtree.

        Args:
            node: the root node of the subtree

        Returns:
            The left-most node of the given subtree
        """
        curr = node

        while(curr.left != None):
            curr = curr.left
        return curr

    def get_parent(self, node):
        if node is self.root:
            return None
        else:
            curr = self.root
            while curr is not node:
                if node.val < curr.val:
                    if curr.left.val == node.val:
                        return curr
                    else:
                        curr = curr.left
                else:
                    if curr.right.val == node.val:
                        return curr
                    else:
                        curr = curr.right
            return False

    def remove(self, kq):
        """
        Removes node with key k, if the node exists in the BSTree.

        Args:
            node: root of Binary Search Tree
            kq: key of node to remove

        Returns:
            True if k is in the tree and successfully removed, otherwise False
        """
        if kq == self.root.val:
            self.remove_first()
            return
        if self.contains(kq):
            node = self.root
            while node.val != kq:
                if kq < node.val:
                    node = node.left
                else:
                    node = node.right
        else:
            return False
        kq_p = self.get_parent(node)
        if node.left is None and node.right is None:
            if node.val < kq_p.val:
                kq_p.left = None
            else:
                kq_p.right = None
        else:
            if node.right is None:
                ios = node.left
                if node.val < kq_p.val:
                    kq_p.left = ios
                else:
                    kq_p.right = ios
                node.left = None
                node.right = None
                return True
            else:
                ios = self.left_child(node.right)
            ios_p = self.get_parent(ios)
            ios.left = node.left
            if ios is not node.right:
                ios_p.left = ios.right
                ios.right = node.right
            if node.val < kq_p.val:
                kq_p.left = ios
            else:
                kq_p.right = ios
        node.left = None
        node.right = None
        return True

    def get_first(self):
        """
        Gets the val of the root node in the BSTree.

        Returns:
            val of the root node, return None if BSTree is empty
        """
        if self.root is None:
            return None
        else:
            return self.root.val

    def remove_first(self):
        """
        Removes the val of the root node in the BSTree.

        Returns:
            True if the root was removed, otherwise False
        """
        if(self.root == None):
            print("ERROR")
        else:
            if self.root.left is None and self.root.right is None:
                self.root = None
                return True
            elif self.root.right is None:
                self.root = self.root.left
            else:
                ios = self.left_child(self.root.right)
                ios_p = self.get_parent(ios)
                if ios_p == self.root:
                    ios.left = self.root.left
                    self.root = ios
                    return True
                else:
                    ios.left = self.root.left
                    ios_p.left = ios.right
                    ios.right = self.root.right
                    self.root = ios
                    return True
