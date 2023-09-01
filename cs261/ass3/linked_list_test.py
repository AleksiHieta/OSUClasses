from linked_list import LinkedList
from linked_list import CircularList


if __name__ == '__main__':

	list1 = LinkedList([1, 2, 3])
	list1.add_back(4)
        print(list1)
	print(list1.contains(2))

	list2 = LinkedList()
	list2.add_front('A')
        list2.add_front('B')
        list2.add_front('C')
	list2.add_link_before('D', 2)
	print(list2)
        list2.remove_back()
	print(list2)
        print(list2.get_front())
        print(list2.get_back())

	list3 = CircularList([1, 2, 3, 3, 4, 5])
	print(list3)
	list3.circularListReverse()
	print(list3)
       
        list4 = CircularList()
        list4.add_link_before(1, 0)
        print(list4)
        list4.add_link_before(2, 0)
        print(list4)
        list4.add_link_before(3, 1)
        print(list4)
