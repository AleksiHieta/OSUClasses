# Course: CS261 - Data Structures
# Student Name:
# Assignment:
# Description:


from a1_include import *


def sa_sort(arr: StaticArray) -> None:
    """
    TODO: Write this implementation
    """
    #Note: Referenced geeksforgeeks.org for bubble
    #      sort methods and CS 162 C++ Methods

    for i in range(arr._size-1):
        for j in range(0, arr._size-i-1):
            if (arr[j] > arr[j+1]):
                arr[j], arr[j+1] = arr[j+1], arr[j]

    return arr


# BASIC TESTING
if __name__ == "__main__":

    # example 1
    test_cases = (
        [1, 10, 2, 20, 3, 30, 4, 40, 5],
        ['zebra2', 'apple', 'tomato', 'apple', 'zebra1'],
        [(1, 1), (20, 1), (1, 20), (2, 20)]
    )
    for case in test_cases:
        arr = StaticArray(len(case))
        for i, value in enumerate(case):
            arr[i] = value
        print(arr)
        sa_sort(arr)
        print(arr)
