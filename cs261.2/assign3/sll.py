#Course: CS261 - Data Structures
# Student Name:
# Assignment:
# Description:



class SLLException(Exception):
    """
    Custom exception class to be used by Singly Linked List
    DO NOT CHANGE THIS CLASS IN ANY WAY
    """
    pass


class SLNode:
    """
    Singly Linked List Node class
    DO NOT CHANGE THIS CLASS IN ANY WAY
    """
    def __init__(self, value: object) -> None:
        self.next = None
        self.value = value


class LinkedList:
    def __init__(self, start_list=None):
        """
        Initializes a new linked list with front and back sentinels
        DO NOT CHANGE THIS METHOD IN ANY WAY
        """
        self.head = SLNode(None)
        self.tail = SLNode(None)
        self.head.next = self.tail

        # populate SLL with initial values (if provided)
        # before using this feature, implement add_back() method
        if start_list is not None:
            for value in start_list:
                self.add_back(value)

    def __str__(self) -> str:
        """
        Return content of singly linked list in human-readable form
        DO NOT CHANGE THIS METHOD IN ANY WAY
        """
        out = 'SLL ['
        if self.head.next != self.tail:
            cur = self.head.next.next
            out = out + str(self.head.next.value)
            while cur != self.tail:
                out = out + ' -> ' + str(cur.value)
                cur = cur.next
        out = out + ']'
        return out

    def length(self) -> int:
        """
        Return the length of the linked list
        DO NOT CHANGE THIS METHOD IN ANY WAY
        """
        length = 0
        cur = self.head
        while cur.next != self.tail:
            cur = cur.next
            length += 1
        return length

    def is_empty(self) -> bool:
        """
        Return True is list is empty, False otherwise
        DO NOT CHANGE THIS METHOD IN ANY WAY
        """
        return self.head.next == self.tail

    # ------------------------------------------------------------------ #

    def add_front(self, value: object) -> None:
        new = SLNode(value)
        
        if self.head != None:
            new.next = self.head.next
            self.head.next = new
        else:
            self.head.next = new

        pass

    def add_back(self, value: object) -> None:
        new = SLNode(value)

        curr = self.head
        while curr.next != self.tail:
            curr = curr.next
        new.next = self.tail
        curr.next = new

        # traverse the list to find last node
        pass

    def insert_at_index(self, index: int, value: object) -> None:
        new = SLNode(value)

        if index < 0:
            raise SLLException
        #print(index)
        #print(self.length())
        if index > self.length():
            raise SLLException

        if index == 0:
            self.add_front(value)
        else:
            curr = self.head
            for i in range(index):
                curr = curr.next
            new.next = curr.next
            curr.next = new

        pass

    def remove_front(self) -> None:
        if self.length() == 0:
            raise SLLException
        self.head.next = self.head.next.next

        pass

    def remove_back(self) -> None:
        if self.length() == 0:
            raise SLLException
        curr = self.head
        while curr.next.next != self.tail:
            curr = curr.next
        curr.next = self.tail

        pass

    def remove_at_index(self, index: int) -> None:
        if index < 0:
            raise SLLException
        if index > self.length()-1:
            raise SLLException

        if index == 0:
            self.remove_front()
        else:
            curr = self.head
            for i in range(index):
                curr = curr.next
            curr.next = curr.next.next

        pass

    def get_front(self) -> object:
        if self.length() == 0:
            raise SLLException
        return self.head.next.value

    def get_back(self) -> object:
        if self.length() == 0:
            raise SLLException
        curr = self.head
        while curr.next != self.tail:
            curr = curr.next
        return curr.value

    def remove(self, value: object) -> bool:
        if self.length() == 0:
            return False
        curr = self.head
        if curr.next.value == value:
            curr.next = curr.next.next
            return True

        while curr.next.next != self.tail:
            curr = curr.next
            if curr.next.value == value:
                curr.next = curr.next.next
                return True

        return False

    def count(self, value: object) -> int:
        curr = self.head  
        count = 0      
        while curr.next != self.tail:
            curr = curr.next
            if curr.value == value:
                count += 1

        return count

    def slice(self, start_index: int, size: int) -> object:
        if start_index < 0:
            raise SLLException
        if start_index > self.length()-1:
            raise SLLException
        if size < 0:
            raise SLLException
        if start_index + size > self.length():
            raise SLLException

        list2 = LinkedList()
        curr = self.head
        for i in range(0, start_index):
            curr = curr.next
        for i in range(size):
            curr = curr.next
            list2.add_back(curr.value)
        return list2




if __name__ == '__main__':
    pass

    print('\n# add_front example 1')
    list = LinkedList()
    print(list)
    list.add_front('A')
    list.add_front('B')
    list.add_front('C')
    print(list)
    #
    #
    print('\n# add_back example 1')
    list = LinkedList()
    print(list)
    list.add_back('C')
    list.add_back('B')
    list.add_back('A')
    print(list)
    #
    #
    print('\n# insert_at_index example 1')
    list = LinkedList()

    #list.insert_at_index(0, 2)

    test_cases = [(0, 'A'), (0, 'B'), (1, 'C'), (3, 'D'), (-1, 'E'), (5, 'F')]
    for index, value in test_cases:
        print('Insert of', value, 'at', index, ': ', end='')
        try:
            list.insert_at_index(index, value)
            print(list)
        except Exception as e:
            print(type(e))
    #
    #
    print('\n# remove_front example 1')
    list = LinkedList([1, 2])
    print(list)
    for i in range(3):
        try:
            list.remove_front()
            print('Successful removal', list)
        except Exception as e:
            print(type(e))
    #
    #
    print('\n# remove_back example 1')
    list = LinkedList()
    try:
        list.remove_back()
    except Exception as e:
        print(type(e))
    list.add_front('Z')
    list.remove_back()
    print(list)
    list.add_front('Y')
    list.add_back('Z')
    list.add_front('X')
    print(list)
    list.remove_back()
    print(list)
    #
    #
    print('\n# remove_at_index example 1')
    list = LinkedList([1, 2, 3, 4, 5, 6])
    print(list)
    for index in [0, 0, 0, 2, 2, -2]:
        print('Removed at index:', index, ': ', end='')
        try:
            list.remove_at_index(index)
            print(list)
        except Exception as e:
            print(type(e))
    print(list)
    #
    #
    print('\n# get_front example 1')
    list = LinkedList(['A', 'B'])
    print(list.get_front())
    print(list.get_front())
    list.remove_front()
    print(list.get_front())
    list.remove_back()
    try:
        print(list.get_front())
    except Exception as e:
        print(type(e))
    #
    #
    print('\n# get_back example 1')
    list = LinkedList([1, 2, 3])
    list.add_back(4)
    print(list.get_back())
    list.remove_back()
    print(list)
    print(list.get_back())
    #
    #
    print('\n# remove example 1')
    list = LinkedList([1, 2, 3, 1, 2, 3, 1, 2, 3])
    print(list)
    for value in [7, 1, 1, 1, 1]:
        print(list.remove(value), list.length(), list)
    #
    #
    print('\n# count example 1')
    list = LinkedList([1, 2, 3, 1, 2, 2])
    print(list, list.count(1), list.count(2), list.count(3), list.count(4))
    #
    #
    print('\n# slice example 1')
    list = LinkedList([1, 2, 3, 4, 5, 6, 7, 8, 9])
    ll_slice = list.slice(1, 3)
    print(list, ll_slice, sep="\n")
    ll_slice.remove_at_index(0)
    print(list, ll_slice, sep="\n")
    #
    #
    print('\n# slice example 2')
    list = LinkedList([10, 11, 12, 13, 14, 15, 16])
    print("SOURCE:", list)
    slices = [(0, 7), (-1, 7), (0, 8), (2, 3), (5, 0), (5, 3), (6, 1)]
    for index, size in slices:
        print("Slice", index, "/", size, end="")
        try:
            print(" --- OK: ", list.slice(index, size))
        except:
            print(" --- exception occurred.")

