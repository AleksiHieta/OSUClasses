# student_list.py
# ===================================================
# Reimplementation of Pythons List
# ===================================================

import numpy as np

# StudentList class is our implementation of Python's List

class StudentList:
    def __init__(self):
        # creates an empty array of length 4, change the [4] to another value to make an
        # array of different length.
        self._list = np.empty([4], np.int16)
        self._capacity = 4
        self._size = 0
    def __str__(self):
        return str(self._list[:self._size])

# You may want an internal function that handles resizing the array.
# Dont modify get_list or get_capacity, they are for testing

    def get_list(self):
        return self._list[:self._size]

    def get_capacity(self):
        return self._capacity

def append(self, val):
    self._list[self._size:] = [val]

def pop(self):
    return self._list[self._size:]
    del self._list[self._size]

def insert(self, index, val):
    self._list[self._size:] = 1
    
def remove(self, val):
    for x in self._list
        if val == x
            del self._list[x]
	else
            return "ERROR"

def clear(self):
    for x in self._list
        del self._list[x]

def count(self):
    return 1

def get(self, index):
    return self._list[index]
