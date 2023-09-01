from bst import Student, BST


if __name__ == '__main__':
	bst1 = BST()
	bst1.add(5)
	bst1.add(9)
	bst1.add(1)
	bst1.add(7)
	bst1.add(2)
	bst1.add(3)
	bst1.add(6)
	bst1.add(4)
	bst1.add(0)
       
	print(bst1.pre_order_traversal())
	print(bst1.in_order_traversal())
	print(bst1.post_order_traversal())

	bst1.remove_first()
	print(bst1.pre_order_traversal())
	bst1.remove_first()
	print(bst1.pre_order_traversal())

	bst2 = BST()
	bst2.add(Student(88, "Sasha"))
	bst2.add(Student(94, "Rachel"))
	bst2.add(Student(93, "Phil"))
	bst2.add(Student(85, "Mike"))
	bst2.remove_first()
	in_order = bst2.in_order_traversal()
	for i in in_order:
		print(i)
