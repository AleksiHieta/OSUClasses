# Course: CS261 - Data Structures
# Student Name:
# Assignment:
# Description:


class Stack:
    """
    Class implementing STACK ADT.
    Supported methods are: push, pop, top, is_empty

    DO NOT CHANGE THIS CLASS IN ANY WAY
    YOU ARE ALLOWED TO CREATE AND USE OBJECTS OF THIS CLASS IN YOUR SOLUTION
    """
    def __init__(self):
        """ Initialize empty stack based on Python list """
        self._data = []

    def push(self, value: object) -> None:
        """ Add new element on top of the stack """
        self._data.append(value)

    def pop(self) -> object:
        """ Remove element from top of the stack and return its value """
        return self._data.pop()

    def top(self) -> object:
        """ Return value of top element without removing from stack """
        return self._data[-1]

    def is_empty(self):
        """ Return True if the stack is empty, return False otherwise """
        return len(self._data) == 0

    def __str__(self):
        """ Return content of the stack as a string (for use with print) """
        data_str = [str(i) for i in self._data]
        return "STACK: { " + ", ".join(data_str) + " }"


class Queue:
    """
    Class implementing QUEUE ADT.
    Supported methods are: enqueue, dequeue, is_empty

    DO NOT CHANGE THIS CLASS IN ANY WAY
    YOU ARE ALLOWED TO CREATE AND USE OBJECTS OF THIS CLASS IN YOUR SOLUTION
    """
    def __init__(self):
        """ Initialize empty queue based on Python list """
        self._data = []

    def enqueue(self, value: object) -> None:
        """ Add new element to the end of the queue """
        self._data.append(value)

    def dequeue(self) -> object:
        """ Remove element from the beginning of the queue and return its value """
        return self._data.pop(0)

    def is_empty(self):
        """ Return True if the queue is empty, return False otherwise """
        return len(self._data) == 0

    def __str__(self):
        """ Return content of the stack as a string (for use with print) """
        data_str = [str(i) for i in self._data]
        return "QUEUE { " + ", ".join(data_str) + " }"


class TreeNode:
    """
    Binary Search Tree Node class
    DO NOT CHANGE THIS CLASS IN ANY WAY
    """
    def __init__(self, value: object) -> None:
        """
        Init new Binary Search Tree
        DO NOT CHANGE THIS METHOD IN ANY WAY
        """
        self.value = value          # to store node's data
        self.left = None            # pointer to root of left subtree
        self.right = None           # pointer to root of right subtree

    def __str__(self):
        return str(self.value)


class BST:
    def __init__(self, start_tree=None) -> None:
        """
        Init new Binary Search Tree
        DO NOT CHANGE THIS METHOD IN ANY WAY
        """
        self.root = None

        # populate BST with initial values (if provided)
        # before using this feature, implement add() method
        if start_tree is not None:
            for value in start_tree:
                self.add(value)

    def __str__(self) -> str:
        """
        Return content of BST in human-readable form using in-order traversal
        DO NOT CHANGE THIS METHOD IN ANY WAY
        """
        values = []
        self._str_helper(self.root, values)
        return "TREE in order { " + ", ".join(values) + " }"

    def _str_helper(self, cur, values):
        """
        Helper method for __str__. Does in-order tree traversal
        DO NOT CHANGE THIS METHOD IN ANY WAY
        """
        # base case
        if cur is None:
            return
        # recursive case for left subtree
        self._str_helper(cur.left, values)
        # store value of current node
        values.append(str(cur.value))
        # recursive case for right subtree
        self._str_helper(cur.right, values)

    # ------------------------------------------------------------------ #

    def add(self, value: object) -> None:
        if (self.root == None):
            self.root = TreeNode(value)

        else:
            new = TreeNode(value)
            curr = self.root
            while(curr != None):
                if(value < curr.value):
                    if(curr.left is None):
                        curr.left = new
                        break
                    else:
                        curr = curr.left
                else:
                    if(curr.right is None):
                        curr.right = new
                        break
                    curr = curr.right
            #print("Need to add more")

        pass

    def contains(self, value: object) -> bool:
        curr = self.root
        while curr is not None:
            if (curr.value == value):
                return True
            elif curr.value > value:
                curr = curr.left
            else:
                curr = curr.right

        return False

    def get_first(self) -> object:
        if self.root is None:
            return None
        else:
            return self.root.value

    def remove_first(self) -> bool:
        if self.root == None:
            return False
        else:
            if self.root.left is None:
                self.root = self.root.right
            if self.root.right is None:
                self.root = self.root.left
            

            

    def remove(self, value) -> bool:
        if self.root == None:
            return False
        if not self.contains(value):
            return False       
 
        parentN = None
        curr = self.root                
        found = True
        while found:
            #print("====Looking=====")
            if value == curr.value:
                N = curr
                found = False
                #print("===Found!====")
            elif value < curr.value:
                parentN = curr
                curr = curr.left
            else:
                parentN = curr
                curr = curr.right
        
        if N.right is None:
            if N.left is None:
                parentS = None
                S = None
            else:
                S = N.left
                #print("Subbing Left")
                parentS = N
        else:
            S = N.right
            parentS = N
            while S.left is not None:
                parentS = S
                S = S.left 

        print(N, parentN, S, parentS)

        if S is None:          #N has no children
            if parentN.right == N:
                parentN.right = None
            else:
                 parentN.left = None
        else:
            if parentN is None:     #Root of tree w/ children
                if N.right is None:
                    self.root = N.left
                elif N.left is None:
                    parentS.left = S.right
                    S.left = N.left
                    S.right = N.right
                    return True
            else:                   #other position
                print("Defined S and not root")
                if parentN.right == N:
                    print("N is to the right of parentN")
                    parentN.right = S
                    #if S.right is not None and S.left is not None:
                    #    if parentS.left == S:
                    #        parentS.left = S.left
                    #        parentS.

                    #else:
                    if S.left is not None:
                        print("Subbing Left")
                        print(parentS.value)
                        print(S.left.value)
                        print(S.right.value)
                        parentS.left = S.left
                        parentS.right = S.right 
                        #print(parentS.left.right.value)             
                    S.left = N.left
                    S.right = N.right
                    print(S.left)
                    print(S.right)
                else:
                    print("N is to left of parentN")
                    parentN.left = S
                    if S.left is not None:
                        parentS.left = S.left
                        parentS.left.right = S.right 
                    else:
                        parentS.left = S.right
                        
                    S.left = N.left
                    S.right = N.right
        return True

    def pre_order_traversal(self, curr=None, q=None) -> Queue:
        if q is None:
            q = Queue()
            self.pre_order_traversal(self.root, q)

        if curr is None:
            return q
        
        q.enqueue(curr.value)
        self.pre_order_traversal(curr.left, q)
        self.pre_order_traversal(curr.right, q)
        return q
        
    def in_order_traversal(self, curr=None, q=None) -> Queue:
        if q is None:
            q = Queue()
            self.in_order_traversal(self.root, q)

        if curr is None:
            return q

        self.in_order_traversal(curr.left, q)
        #print(q)
        q.enqueue(curr.value)
        #print(q)
        self.in_order_traversal(curr.right, q)
        #print(q)
        return q

    def post_order_traversal(self, curr=None, q=None) -> Queue:
        if q is None:
            q = Queue()
            self.post_order_traversal(self.root, q)

        if curr is None:
            return q

        self.post_order_traversal(curr.left, q)
        #print(q)
        self.post_order_traversal(curr.right, q)
        #print(q)
        q.enqueue(curr.value)
        #print(q)
        return q

    def by_level_traversal(self) -> Queue:
        """
        TODO: Write this implementation
        """
        return Queue()

    def is_full(self) -> bool:
        """
        TODO: Write this implementation
        """
        return True

    def is_complete(self) -> bool:
        """
        TODO: Write this implementation
        """
        return True

    def is_perfect(self) -> bool:
        """
        TODO: Write this implementation
        """
        return True

    def size(self) -> int:
        q = self.in_order_traversal()
        
        count = 0
        while not (q.is_empty()):
            q.dequeue()
            count += 1
        return count

    def height(self) -> int:
        """
        if self.root is None:
            return -1
        curr = self.root
        count = 0

        if self.root.left is None and self.root.right is None:
            return 0
        
        kids = True
        while kids:
            if curr.left is not None and curr.right is not None:
                currl = curr.left 
                currr = curr.right
                pass
            elif curr.left is not None and curr.right is None:
                curr = curr.right
                count += 1
                pass
            elif curr.right is not None and curr.left is None:
                curr = curr.left
                count += 1
                pass
            else:
                return count
        """
        return 0

    def count_leaves(self) -> int:
        """
        TODO: Write this implementation
        """
        return 0

    def count_unique(self) -> int:
        """
        TODO: Write this implementation
        """
        return 0

    def magic(self, cur=None, first_call=True) -> int:

        if first_call:
            return self.magic(self.root, False)

        if cur is None:
            return 0

        if cur.left is None and cur.right is None:
            return 1

        return self.magic(cur.left, False) + self.magic(cur.right, False)

if __name__ == '__main__':
    """ add() example #1 """
    print("\nPDF - method add() example 1")
    print("----------------------------")
    tree = BST()
    print(tree)
    tree.add(10)
    tree.add(15)
    tree.add(5)
    print(tree)
    tree.add(15)
    tree.add(15)
    print(tree)
    tree.add(5)
    print(tree)

    """ add() example 2 """
    print("\nPDF - method add() example 2")
    print("----------------------------")
    tree = BST()
    tree.add(10)
    tree.add(10)
    print(tree)
    tree.add(-1)
    print(tree)
    tree.add(5)
    print(tree)
    tree.add(-1)
    print(tree)

    """ contains() example 1 """
    print("\nPDF - method contains() example 1")
    print("---------------------------------")
    tree = BST([10, 5, 15])
    print(tree)
    print(tree.contains(15))
    print(tree.contains(-10))
    print(tree.contains(15))

    """ contains() example 2 """
    print("\nPDF - method contains() example 2")
    print("---------------------------------")
    tree = BST()
    print(tree.contains(0))

    """ get_first() example 1 """
    print("\nPDF - method get_first() example 1")
    print("----------------------------------")
    tree = BST()
    print(tree.get_first())
    tree.add(10)
    tree.add(15)
    tree.add(5)
    print(tree.get_first())

    """ remove() example 1 """
    print("\nPDF - method remove() example 1")
    print("-------------------------------")
    tree = BST([10, 5, 15])
    print(tree)
    print(tree.remove(7))
    print(tree.remove(15))
    print(tree.remove(15))
    print(tree)

    """ remove() example 2 """
    print("\nPDF - method remove() example 2")
    print("-------------------------------")
    tree = BST([10, 20, 5, 15, 17, 7, 12])
    print(tree)
    print(tree.remove(20))
    print(tree)
    print(tree.pre_order_traversal())
    print(tree.post_order_traversal())
    

    """ remove() example 3 """
    print("\nPDF - method remove() example 3")
    print("-------------------------------")
    tree = BST([10, 5, 20, 18, 12, 7, 27, 22, 18, 24, 22, 30])
    print(tree)
    print(tree.remove(20))
    #print(tree)
    # comment out the following lines
    # if you have not yet implemented traversal methods
    #print(tree.pre_order_traversal())
    #print(tree.in_order_traversal())
    #print(tree.post_order_traversal())
    #print(tree.by_level_traversal())

    """
    tree = BST([10, 5, 20, 18, 12, 7, 27, 22, 18, 24, 23, 30])
    print(tree)
    tree.remove(22)
    print(tree.pre_order_traversal())
    print(tree.in_order_traversal())
    print(tree.post_order_traversal())
    """
    
    """ remove_first() example 1 """
    print("\nPDF - method remove_first() example 1")
    print("-------------------------------------")
    tree = BST([10, 15, 5])
    print(tree.remove_first())
    print(tree)

    """ remove_first() example 2 """
    print("\nPDF - method remove_first() example 2")
    print("-------------------------------------")
    tree = BST([10, 20, 5, 15, 17, 7])
    print(tree.remove_first())
    print(tree)

    """ remove_first() example 3 """
    print("\nPDF - method remove_first() example 3")
    print("-------------------------------------")
    tree = BST([10, 10, -1, 5, -1])
    print(tree.remove_first(), tree)
    print(tree.remove_first(), tree)
    print(tree.remove_first(), tree)
    print(tree.remove_first(), tree)
    print(tree.remove_first(), tree)
    print(tree.remove_first(), tree)

    """ Traversal methods example 1 """
    print("\nPDF - traversal methods example 1")
    print("---------------------------------")
    tree = BST([10, 20, 5, 15, 17, 7, 12])
    print(tree.pre_order_traversal())
    print(tree.in_order_traversal())
    print(tree.post_order_traversal())
    print(tree.by_level_traversal())

    """ Traversal methods example 2 """
    print("\nPDF - traversal methods example 2")
    print("---------------------------------")
    tree = BST([10, 10, -1, 5, -1])
    print(tree.pre_order_traversal())
    print(tree.in_order_traversal())
    print(tree.post_order_traversal())
    print(tree.by_level_traversal())

    """ Comprehensive example 1 """
    print("\nComprehensive example 1")
    print("-----------------------")
    tree = BST()
    header = 'Value   Size  Height   Leaves   Unique   '
    header += 'Complete?  Full?    Perfect?'
    print(header)
    print('-' * len(header))
    print(f'  N/A {tree.size():6} {tree.height():7} ',
          f'{tree.count_leaves():7} {tree.count_unique():8}  ',
          f'{str(tree.is_complete()):10}',
          f'{str(tree.is_full()):7} ',
          f'{str(tree.is_perfect())}')

    for value in [10, 5, 3, 15, 12, 8, 20, 1, 4, 9, 7]:
        tree.add(value)
        print(f'{value:5} {tree.size():6} {tree.height():7} ',
              f'{tree.count_leaves():7} {tree.count_unique():8}  ',
              f'{str(tree.is_complete()):10}',
              f'{str(tree.is_full()):7} ',
              f'{str(tree.is_perfect())}')
    print()
    print(tree.pre_order_traversal())
    print(tree.in_order_traversal())
    print(tree.post_order_traversal())
    print(tree.by_level_traversal())

    """ Comprehensive example 2 """
    print("\nComprehensive example 2")
    print("-----------------------")
    tree = BST()
    header = 'Value   Size  Height   Leaves   Unique   '
    header += 'Complete?  Full?    Perfect?'
    print(header)
    print('-' * len(header))
    print(f'N/A   {tree.size():6} {tree.height():7} ',
          f'{tree.count_leaves():7} {tree.count_unique():8}  ',
          f'{str(tree.is_complete()):10}',
          f'{str(tree.is_full()):7} ',
          f'{str(tree.is_perfect())}')

    for value in 'DATA STRUCTURES':
        tree.add(value)
        print(f'{value:5} {tree.size():6} {tree.height():7} ',
              f'{tree.count_leaves():7} {tree.count_unique():8}  ',
              f'{str(tree.is_complete()):10}',
              f'{str(tree.is_full()):7} ',
              f'{str(tree.is_perfect())}')
    print('', tree.pre_order_traversal(), tree.in_order_traversal(),
          tree.post_order_traversal(), tree.by_level_traversal(),
          sep='\n')


    tree2 = BST()
    for value in [10, 5, 3, 15, 12, 8, 20, 1, 4, 9, 7, 22]:
        tree2.add(value)

    print(tree2.magic())    





