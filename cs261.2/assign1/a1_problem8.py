# Course: CS261 - Data Structures
# Student Name:
# Assignment:
# Description:


from a1_include import *


def remove_duplicates(arr: StaticArray) -> StaticArray:
    """
    TODO: Write this implementation
    """
    arr2 = StaticArray(arr._size)

    arr2[0] = arr[0]
    idx = 1

    for i in range(1, arr._size):
        if (arr[i] != arr[i-1]):
            arr2[idx] = arr[i]
            idx = idx+1
 
    #print(arr2)

    count = 0
    for i in range(arr2._size):
        if (arr2[i] != None):
            count = count + 1

    #print(count)

    arr3 = StaticArray(count)

    for i in range(count):
        arr3[i] = arr2[i]

    #print(arr3)

    return arr3


# BASIC TESTING
if __name__ == "__main__":

    # example 1
    test_cases = (
        [1], [1, 2], [1, 1, 2], [1, 20, 30, 40, 500, 500, 500],
        [5, 5, 5, 4, 4, 3, 2, 1, 1], [1, 1, 1, 1, 2, 2, 2, 2]
    )
    for case in test_cases:
        arr = StaticArray(len(case))
        for i, value in enumerate(case):
            arr[i] = value
        print(arr)
        print(remove_duplicates(arr))
