# Course: CS261 - Data Structures
# Student Name:
# Assignment:
# Description:


class CDLLException(Exception):
    """
    Custom exception class to be used by Circular Doubly Linked List
    DO NOT CHANGE THIS CLASS IN ANY WAY
    """
    pass


class DLNode:
    """
    Doubly Linked List Node class
    DO NOT CHANGE THIS CLASS IN ANY WAY
    """

    def __init__(self, value: object) -> None:
        self.next = None
        self.prev = None
        self.value = value


class CircularList:
    def __init__(self, start_list=None):
        """
        Initializes a new linked list with sentinel
        DO NOT CHANGE THIS METHOD IN ANY WAY
        """
        self.sentinel = DLNode(None)
        self.sentinel.next = self.sentinel
        self.sentinel.prev = self.sentinel

        # populate CDLL with initial values (if provided)
        # before using this feature, implement add_back() method
        if start_list is not None:
            for value in start_list:
                self.add_back(value)

    def __str__(self) -> str:
        """
        Return content of singly linked list in human-readable form
        DO NOT CHANGE THIS METHOD IN ANY WAY
        """
        out = 'CDLL ['
        if self.sentinel.next != self.sentinel:
            cur = self.sentinel.next.next
            out = out + str(self.sentinel.next.value)
            while cur != self.sentinel:
                out = out + ' <-> ' + str(cur.value)
                cur = cur.next
        out = out + ']'
        return out

    def length(self) -> int:
        """
        Return the length of the linked list

        This can also be used as troubleshooting method. This method works
        by independently measuring length during forward and backward
        traverse of the list and return the length if results agree or error
        code of -1 or -2 if thr measurements are different.

        Return values:
        >= 0 - length of the list
        -1 - list likely has an infinite loop (forward or backward)
        -2 - list has some other kind of problem

        DO NOT CHANGE THIS METHOD IN ANY WAY
        """

        # length of the list measured traversing forward
        count_forward = 0
        cur = self.sentinel.next
        while cur != self.sentinel and count_forward < 101_000:
            count_forward += 1
            cur = cur.next

        # length of the list measured traversing backwards
        count_backward = 0
        cur = self.sentinel.prev
        while cur != self.sentinel and count_backward < 101_000:
            count_backward += 1
            cur = cur.prev

        # if any of the result is > 100,000 -> list has a loop
        if count_forward > 100_000 or count_backward > 100_000:
            return -1

        # if counters have different values -> there is some other problem
        return count_forward if count_forward == count_backward else -2

    def is_empty(self) -> bool:
        """
        Return True is list is empty, False otherwise
        DO NOT CHANGE THIS METHOD IN ANY WAY
        """
        return self.sentinel.next == self.sentinel

    # ------------------------------------------------------------------ #

    def add_front(self, value: object) -> None:
        new = DLNode(value)
        if self.is_empty():
            new.next = self.sentinel
            new.prev = self.sentinel
            self.sentinel.next = new
            self.sentinel.prev = new
        else:
            new.next = self.sentinel.next
            new.prev = self.sentinel
            self.sentinel.next = new
            new.next.prev = new
        pass

    def add_back(self, value: object) -> None:
        new = DLNode(value)
        curr = self.sentinel

        if self.is_empty():
            self.add_front(value)
        else:
            curr = curr.prev #last node
            curr.next = new
            new.prev = curr
            self.sentinel.prev = new
            new.next = self.sentinel

        pass

    def insert_at_index(self, index: int, value: object) -> None:
        if index < 0:
            raise CDLLException
        if index > self.length():
            raise CDLLException
        
        if index == 0:
            self.add_front(value)
        elif index == self.length():
            self.add_back(value)
        else:
            new = DLNode(value)
            curr = self.sentinel
            for i in range(index):
                curr = curr.next
            new.next = curr.next
            new.prev = curr
            curr.next.prev = new
            curr.next = new

    def remove_front(self) -> None:
        if self.length() == 0:
            raise CDLLException
        if self.length() == 0:
            self.sentinel.prev = self.sentinel
            self.sentinel.next = self.sentinel
        else:
            self.sentinel.next = self.sentinel.next.next
            self.sentinel.next.prev = self.sentinel

        pass

    def remove_back(self) -> None:
        if self.length() == 0:
            raise CDLLException
        if self.length() == 0:
            self.sentinel.prev = self.sentinel
            self.sentinel.next = self.sentinel
        else:
            self.sentinel.prev = self.sentinel.prev.prev
            self.sentinel.prev.next = self.sentinel 
        pass

    def remove_at_index(self, index: int) -> None:
        if self.length() == 0:
            raise CDLLException
        if index < 0:
            raise CDLLException
        if index > self.length()-1:
            raise CDLLException

        if index == 0:
            self.remove_front()
        elif index == self.length()-1:
            self.remove_back()
        else:
            curr = self.sentinel.next
            for i in range(index):
                curr = curr.next
            curr.prev.next = curr.next
            curr.next.prev = curr.prev
        pass

    def get_front(self) -> object:
        if self.is_empty():
            raise CDLLException
        return self.sentinel.next.value

    def get_back(self) -> object:
        if self.is_empty():
            raise CDLLException
        return self.sentinel.prev.value

    def remove(self, value: object) -> bool:
        if self.length() == 0:
            return False
        curr = self.sentinel
        while curr.next != self.sentinel:
            curr = curr.next
            if curr.value == value:
                curr.prev.next = curr.next
                curr.next.prev = curr.prev
                return True

        return False

    def count(self, value: object) -> int:
        curr = self.sentinel
        count = 0
        while curr.next != self.sentinel:
            curr = curr.next
            if curr.value == value:
                count += 1
        return count

    def swap_pairs(self, index1: int, index2: int) -> None:
        if self.length() < 2:
            raise CDLLException
        if index1 > self.length()-1:
            raise CDLLException
        if index2 > self.length()-1:
            raise CDLLException
        curr = self.sentinel.next
        for i in range(index1):
            curr = curr.next
        swap1 = curr
        curr = self.sentinel.next
        for i in range(index2):
            curr = curr.next
        swap2 = curr
        self.remove_at_index(index1)
        self.insert_at_index(index1, swap2.value)
        self.remove_at_index(index2)
        self.insert_at_index(index2, swap1.value)
         
        pass

    def reverse(self) -> None:
        temp = CircularList()
        curr = self.sentinel
        while curr.next != self.sentinel:
            curr = curr.next
            temp.add_front(curr.value)

        for i in range(self.length()):
            self.remove_at_index(0)

        curr2 = temp.sentinel
        while curr2.next != temp.sentinel:
            curr2 = curr2.next
            self.add_back(curr2.value)

        pass

    def sort(self) -> None:
        curr = self.sentinel

        self2 = CircularList()
        while curr.next != self.sentinel:
            curr = curr.next
            self2.add_back(curr.value)

        curr = self.sentinel        
        for i in range(self.length()-1):
            curr = curr.next
            temp = self2.sentinel.next
            for k in range(0,i):
                temp = temp.next
            for j in range(i, self.length()):
                #print("============")
                #print(curr.value)
                #print(temp.value)
                if (curr.value > temp.value):
                    #print("swapped at:" , i, " and ", j)
                    self.swap_pairs(i, j)
                    curr = self.sentinel.next
                    for l in range(i):
                        curr = curr.next
                temp = temp.next                
        pass

    def rotate(self, steps: int) -> None:
        if steps == 0:
            pass
        elif self.length() == 0:
            pass
        else:
            while steps < 0:
                steps = steps + self.length()
            #print(steps)
            #print(self.length())

            steps = steps % self.length()
        
            temp = CircularList()
            curr = self.sentinel
            for i in range(steps):
                curr = curr.prev
                temp.add_front(curr.value)
            #while curr.next != self.sentinel:
            #    temp.add_back(curr.value)
            #    curr = curr.next
            #print("=====HALF FILLED=====")
            #print(temp)


            curr = self.sentinel
            for i in range(self.length()-steps):
                curr = curr.next
                temp.add_back(curr.value)

            for i in range(self.length()):
                self.remove_at_index(0)

            curr2 = temp.sentinel
            while curr2.next != temp.sentinel:
                curr2 = curr2.next
                self.add_back(curr2.value)
            pass

    def remove_duplicates(self) -> None:
        temp = CircularList()
        curr = self.sentinel
        while curr.next != self.sentinel:
            curr = curr.next
            temp.add_back(curr.value)

        pass

    def odd_even(self) -> None:
        temp = CircularList()
        curr = self.sentinel
        while curr.next != self.sentinel:
            curr = curr.next
            temp.add_back(curr.value)

        for i in range(self.length()):
            self.remove_at_index(0)


        curr2 = temp.sentinel.next
        idx = 0
        while idx < temp.length():
            self.add_back(curr2.value)
            curr2 = curr2.next.next
            idx = idx + 2

        curr2 = temp.sentinel.next.next
        idx = 1
        while idx < temp.length():
            self.add_back(curr2.value)
            curr2 = curr2.next.next
            idx = idx + 2




        pass


if __name__ == '__main__':
    pass

    print('\n# add_front example 1')
    lst = CircularList()
    print(lst)
    lst.add_front('A')
    lst.add_front('B')
    lst.add_front('C')
    print(lst)
    #
    print('\n# add_back example 1')
    lst = CircularList()
    print(lst)
    lst.add_back('C')
    lst.add_back('B')
    lst.add_back('A')
    print(lst)
    #
    print('\n# insert_at_index example 1')
    lst = CircularList()
    test_cases = [(0, 'A'), (0, 'B'), (1, 'C'), (3, 'D'), (-1, 'E'), (5, 'F')]
    for index, value in test_cases:
        print('Insert of', value, 'at', index, ': ', end='')
        try:
            lst.insert_at_index(index, value)
            print(lst)
        except Exception as e:
            print(type(e))
   
    print('\n# remove_front example 1')
    lst = CircularList([1, 2])
    print(lst)
    for i in range(3):
        try:
            lst.remove_front()
            print('Successful removal', lst)
        except Exception as e:
            print(type(e))
    #
    print('\n# remove_back example 1')
    lst = CircularList()
    try:
        lst.remove_back()
    except Exception as e:
        print(type(e))
    lst.add_front('Z')
    lst.remove_back()
    print(lst)
    lst.add_front('Y')
    lst.add_back('Z')
    lst.add_front('X')
    print(lst)
    lst.remove_back()
    print(lst)
    #
    print('\n# remove_at_index example 1')
    lst = CircularList([1, 2, 3, 4, 5, 6])
    print(lst)
    for index in [0, 0, 0, 2, 2, -2]:
        print('Removed at index:', index, ': ', end='')
        try:
            lst.remove_at_index(index)
            print(lst)
        except Exception as e:
            print(type(e))
    print(lst)
    #
    print('\n# get_front example 1')
    lst = CircularList(['A', 'B'])
    print(lst.get_front())
    print(lst.get_front())
    lst.remove_front()
    print(lst.get_front())
    lst.remove_back()
    try:
        print(lst.get_front())
    except Exception as e:
        print(type(e))
   
    print('\n# get_back example 1')
    lst = CircularList([1, 2, 3])
    lst.add_back(4)
    print(lst.get_back())
    lst.remove_back()
    print(lst)
    print(lst.get_back())
    #
    print('\n# remove example 1')
    lst = CircularList([1, 2, 3, 1, 2, 3, 1, 2, 3])
    print(lst)
    for value in [7, 3, 3, 3, 3]:
        print(lst.remove(value), lst.length(), lst)
    #
    print('\n# count example 1')
    lst = CircularList([1, 2, 3, 1, 2, 2])
    print(lst, lst.count(1), lst.count(2), lst.count(3), lst.count(4))
    
    print('\n# swap_pairs example 1')
    lst = CircularList([0, 1, 2, 3, 4, 5, 6])
    print(lst)
    test_cases = ((0, 6), (0, 7), (-1, 6), (1, 5),
                  (4, 2), (3, 3), (1, 2), (2, 1))
    #
    for i, j in test_cases:
        print('Swap nodes ', i, j, ' ', end='')
        try:
            lst.swap_pairs(i, j)
            print(lst)
        except Exception as e:
            print(type(e))
    #
    print('\n# reverse example 1')
    test_cases = (
        [1, 2, 3, 3, 4, 5],
        [1, 2, 3, 4, 5],
        ['A', 'B', 'C', 'D']
    )
    for case in test_cases:
        lst = CircularList(case)
        lst.reverse()
        print(lst)
    
    print('\n# reverse example 2')
    lst = CircularList()
    print(lst)
    lst.reverse()
    print(lst)
    lst.add_back(2)
    lst.add_back(3)
    lst.add_front(1)
    lst.reverse()
    print(lst)
    #
    print('\n# reverse example 3')
    
    #
    class Student:
        def __init__(self, name, age):
            self.name, self.age = name, age
   
        def __eq__(self, other):
            return self.age == other.age
    
        def __str__(self):
            return str(self.name) + ' ' + str(self.age)
    
    
    s1, s2 = Student('John', 20), Student('Andy', 20)
    lst = CircularList([s1, s2])
    print(lst)
    lst.reverse()
    print(lst)
    print(s1 == s2)
    
    print('\n# reverse example 4')
    lst = CircularList([1, 'A'])
    lst.reverse()
    print(lst)
    #
    print('\n# sort example 1')
    test_cases = (
        [1, 10, 2, 20, 3, 30, 4, 40, 5],
        ['zebra2', 'apple', 'tomato', 'apple', 'zebra1'],
        [(1, 1), (20, 1), (1, 20), (2, 20)]
    )
    for case in test_cases:
        lst = CircularList(case)
        print(lst)
        lst.sort()
        print(lst)
   
    print('\n# rotate example 1')
    source = [_ for _ in range(-20, 20, 7)]
    for steps in [1, 2, 0, -1, -2, 28, -100]:
        lst = CircularList(source)
        #print("ORIGINAL LIST: ", lst)
        lst.rotate(steps)
        print(lst, steps)
    #
    print('\n# rotate example 2')
    lst = CircularList([10, 20, 30, 40])
    for j in range(-1, 2, 2):
        for _ in range(3):
            lst.rotate(j)
            print(lst)
    #
    print('\n# rotate example 3')
    lst = CircularList()
    lst.rotate(10)
    print(lst)
    #
    print('\n# remove_duplicates example 1')
    test_cases = (
        [1, 2, 3, 4, 5], [1, 1, 1, 1, 1],
        [], [1], [1, 1], [1, 1, 1, 2, 2, 2],
        [0, 1, 1, 2, 3, 3, 4, 5, 5, 6],
        list("abccd"),
        list("005BCDDEEFI")
    )
    #
    for case in test_cases:
        lst = CircularList(case)
        print('INPUT :', lst)
        lst.remove_duplicates()
        print('OUTPUT:', lst)
    #
    print('\n# odd_even example 1')
    test_cases = (
        [1, 2, 3, 4, 5], list('ABCDE'),
        [], [100], [100, 200], [100, 200, 300],
        [100, 200, 300, 400],
        [10, 'A', 20, 'B', 30, 'C', 40, 'D', 50, 'E']
    )
    #
    for case in test_cases:
        lst = CircularList(case)
        print('INPUT :', lst)
        lst.odd_even()
        print('OUTPUT:', lst)
