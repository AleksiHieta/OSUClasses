# Course: CS261 - Data Structures
# Student Name:
# Assignment:
# Description:


from a1_include import *


def is_sorted(arr: StaticArray) -> int:
    """
    TODO: Write this implementation
    """
    if (arr._size == 1):
        return 1    

    if (arr[0] < arr[1]):
        prevresult = 1
    elif (arr[0] > arr[1]):
        prevresult = 2

    for i in range(0, arr._size-1):
        if (arr[i] < arr[i+1]):
            result = 1
            if (prevresult != result):
                #print('Mistake Caught!!')
                return 0
        elif (arr[i] > arr[i+1]):
            result = 2
            if (prevresult != result):
                #print('Mistake Caught!!')
                return 0
        elif (arr[i] == arr[i+1]):
            return 0

    return result


# BASIC TESTING
if __name__ == "__main__":

    # example 1
    test_cases = (
        [-100, -8, 0, 2, 3, 10, 20, 100],
        ['A', 'B', 'Z', 'a', 'z'],
        ['Z', 'T', 'K', 'A', '1'],
        [1, 3, -10, 20, -30, 0],
        [-10, 0, 0, 10, 20, 30],
        [100, 90, 0, -90, -200],
        ['apple']
    )
    for case in test_cases:
        arr = StaticArray(len(case))
        for i, value in enumerate(case):
            arr[i] = value
        print('Result:', is_sorted(arr), arr)
