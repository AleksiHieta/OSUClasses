# linked_list.py
# ===================================================
# Linked list exploration
# Part 1: implement the deque and bag ADT with a Linked List
# Part 2: implement the deque ADT with a CircularlyDoubly-
# Linked List
# ===================================================


'''
**********************************************************************************
Part1: Deque and Bag implemented with Linked List
**********************************************************************************
'''

class SLNode:
    def __init__(self):
        self.next = None
        self.data = None


class LinkedList:
    def __init__(self, start_list=None):
        """
        Initializes a linked list with a head and tail node with None data
        """
        self.head = SLNode()
        self.tail = SLNode()
        self.head.next = self.tail

        # populate list with initial set of nodes (if provided)
        if start_list is not None:
            for data in start_list:
                self.add_back(data)

    def __str__(self):
        """
        Returns a human readable string of the list content of the form
        [value1 -> value2 -> value3]

        An empty list should just return []

        Returns:
            The string of the human readable list representation
        """
        out = '['
        if self.head.next != self.tail:             
            cur = self.head.next.next
            out = out + str(self.head.next.data)
            while cur != self.tail:
                out = out + ' -> ' + str(cur.data)
                cur = cur.next
        out = out + ']'
        return out

    def add_link_before(self, data, index):
        """
        Adds a new link containing data and inserts it before the link at index.
        If index is 0, it inserts at the beginning of the list.

        Args:
            data: The data the new node will contain
            index: The index of the node that will immediately follow the newly added node
        """
        new_link = SLNode()  # initialize a new link
        new_link.data = data  # set new_link data

        
        if index == 0:
            if self.head != None:
                new_link.next = self.head.next
                self.head.next = new_link
            else:
                self.head.next = new_link 
        else:
            curr = self.head
            for x in range(index):
                curr = curr.next
            new_link.next = curr.next
            curr.next = new_link

    def remove_link(self, index):
        """
        Removes the link at the location specified by index
        Args:
            Index: The index of the node that will be removed
        """
        curr = self.head
        for x in range(index):
            curr = curr.next
        curr.next = curr.next.next

    def add_front(self, data):
        """
        Adds a new node after the head that contains data

        Args:
            data: The data the new node will contain
        """
        new_link = SLNode()  # initialize a new link
        new_link.data = data  # set new_link data

        if self.head != None:
            new_link.next = self.head.next
            self.head.next = new_link
        else:
            self.head.next = new_link 

    def add_back(self, data):
        """
        Adds a new node before the tail that contains data

        Args:
        data: The data the new node will contain
        """
        new_link = SLNode()  # initialize a new link
        new_link.data = data  # set new_link data
         
        curr = self.head
        while curr.next != self.tail:
            curr = curr.next
        new_link.next = self.tail
        curr.next = new_link

    def get_front(self):
        """
        Returns the data in the element at the front of the list. Will return
        None in an empty list.

        Returns:
            The data in the node at index 0 or None if there is no such node
        """

        if self.head.next.data == None:
            return None
        else:
            return self.head.next.data

    def get_back(self):
        """
        Returns the data in the element at the end of the list. Will return
        None in an empty list.

        Returns:
            The data in the node at last index of the list or None if there is no such node
        """

        curr = self.head
        while curr.next.next != None:
            curr = curr.next
        return curr.data

    def remove_front(self):
        """
        Removes the first element of the list. Will not remove the tail.
        """

        self.head.next = self.head.next.next

    def remove_back(self):
        """
        Removes the last element of the list. Will not remove the head.
        """

        curr = self.head
        while curr.next.next.next != None:
            curr = curr.next
        curr.next = self.tail

    def is_empty(self):
        """
        Checks if the list is empty

        Returns:
            True if the list has no data nodes, False otherwise
        """

        if self.head.next == self.tail:
            return True
        else:
            return False

    def contains(self, value):
        """
        Checks if any node contains value

        Args:
            value: The value to look for

        Returns:
            True if value is in the list, False otherwise
        """

        curr = self.head
        while curr.next != None:
            curr = curr.next
            if curr.data == value:
                return True 
        return False

    def remove(self, value):
        """
        Removes the first instance of an element from the list

        Args:
            value: the value to remove
        """

        curr = self.head
        while curr.next != None:
            if curr.next.data == value:
                curr.next = curr.next.next
            curr = curr.next

'''
**********************************************************************************
Part 2: Deque implemented with CircularlyDoublyLinked List
**********************************************************************************
'''

class DLNode:
    def __init__(self):
        self.next = None
        self.prev = None
        self.data = None

class CircularList:
    def __init__(self, start_list=None):
        """
        Initializes a linked list with a single sentinel node containing None data
        """
        self.sentinel = DLNode()
        self.sentinel.next = self.sentinel
        self.sentinel.prev = self.sentinel

        # populate list with initial set of nodes (if provided)
        if start_list is not None:
            for data in start_list:
                self.add_back(data)

    def __str__(self):
        """
        Returns a human readable string of the list content of the form
        [value1 <-> value2 <-> value3]

        An empty list should just print []

        Returns:
            The string of the human readable list representation
        """
        out = '['
        if self.sentinel.prev != self.sentinel:             
            cur = self.sentinel.next.next
            out = out + str(self.sentinel.next.data)
            while cur != self.sentinel:
                out = out + ' <-> ' + str(cur.data)
                cur = cur.next
        out = out + ']'
        return out

    def add_link_before(self, data, index):
        """
        Adds a new link containing data and inserts it before the link at index.
        If index is 0, it inserts at the beginning of the list.

        Args:
            data: The data the new node will contain
            index: The index of the node that will immediately follow the newly added node
        """
        new_link = DLNode()  # initialize a new link
        new_link.data = data  # set new_link data

        if index != 0:
            curr = self.sentinel
            for x in range(index+1):
                curr = curr.next
            curr.prev.next = new_link
            new_link.prev = curr.prev
            new_link.next = curr
            curr.prev = new_link
        else:
            new_link.next = self.sentinel.next
            self.sentinel.next.prev = new_link
            self.sentinel.next = new_link
            new_link.prev = self.sentinel

    def remove_link(self, index):
        """
        Removes the link at the location specified by index
        Args:
            Index: The index of the node that will be removed
        """
         
        curr = self.sentinel.next
        for x in range(index):
            curr = curr.next
        curr.prev.next = curr.next
        curr.next.prev = curr.prev
        

    def add_front(self, data):
        """
        Adds a new node at the beginning of the list that contains data

        Args:
            data: The data the new node will contain
        """
        new_link = DLNode()  # initialize a new link
        new_link.data = data  # set new_link data

        curr = self.sentinel
        new_link.next = curr.next
        curr.next.prev = new_link
        new_link.prev = curr
        curr.next = new_link

    def add_back(self, data):
        """
        Adds a new node at the end of the list that contains data

        Args:
            data: The data the new node will contain
        """
        new_link = DLNode()  # initialize a new link
        new_link.data = data  # set new_link data

        curr = self.sentinel
        while curr.next != self.sentinel:
            curr = curr.next
        new_link.next = curr.next
        curr.next.prev = new_link
        new_link.prev = curr
        curr.next = new_link
        

    def get_front(self):
        """
        Returns the data in the element at the front of the list. Will return
        None in an empty list.

        Returns:
            The data in the node at index 0 or None if there is no such node
        """

        return self.sentinel.next.data


    def get_back(self):
        """
        Returns the data in the element at the end of the list. Will return
        None in an empty list.

        Returns:
            The data in the node at last index of the list or None if there is no such node
        """

        return self.sentinel.prev.data

    def remove_front(self):
        """
        Removes the first element of the list. Will not remove the tail.
        """

        self.sentinel.next = self.sentinel.next.next
        self.sentinel.next.prev = self.sentinel

    def remove_back(self):
        """
        Removes the last element of the list. Will not remove the head.
        """

        self.sentinel.prev = self.sentinel.prev.prev
        self.sentinel.prev.next = self.sentinel

    def is_empty(self):
        """
        Checks if the list is empty

        Returns:
            True if the list has no data nodes, False otherwise
        """
 
        if self.sentinel.prev != self.sentinel:
            return False
        else:
            return True

    def contains(self, value):
        """
        Checks if any node contains value

        Args:
            value: The value to look for

        Returns:
            True if value is in the list, False otherwise
        """

        curr = self.sentinel
        while curr.next != self.sentinel:
            if curr.data == value:
                return True
            curr = curr.next
        return False

    def remove(self, value):
        """
        Removes the first instance of an element from the list

        Args:
            value: the value to remove
        """

        curr = self.sentinel
        while curr.next != self.sentinel:
            if curr.data == value:
                curr.prev.next = curr.next
                curr.next.prev = curr.prev
            curr = curr.next
            

    def circularListReverse(self):
        """
        Reverses the order of the links. It must not create any additional new links to do so.
        (e.g. you cannot call DLNode()). If the list printed by following next was 0, 1, 2, 3,
        after the call it will be 3,2,1,0
        """
        
        temp_sent = self.sentinel
        curr = self.sentinel
        temp_curr = temp_sent

        while curr.next != self.sentinel:
            temp_curr.prev = curr.next
            temp_curr = temp_curr.prev
            curr = curr.next
        temp_curr.prev = temp_sent
        temp_sent.next = temp_curr
        
        temp_curr = temp_sent
        while temp_curr.prev != temp_sent:
            next_temp = temp_curr
            temp_curr = temp_curr.prev
            temp_curr.next = next_temp
       
        self.sentinel.next = temp_sent.next
        self.sentinel.prev = temp_sent.prev
        temp_sent.next.prev = self.sentinel
        temp_sent.prev.next = self.sentinel
            




