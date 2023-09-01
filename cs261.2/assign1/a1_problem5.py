# Course: CS261 - Data Structures
# Student Name:
# Assignment:
# Description:


from a1_include import *


def sa_range(start: int, end: int) -> StaticArray:
    """
    TODO: Write this implementation
    """
    Length = end-start
    if (Length < 0):
        Length = -Length
    elif (Length == 0):
        arr = StaticArray(1)
        arr[0] = start
        return arr

    arr = StaticArray(Length+1)

    for i in range(arr._size):
        if start < end:
            arr[i] = start+i
        if end < start:
            arr[i] = start-i

    return arr


# BASIC TESTING
if __name__ == "__main__":

    # example 1
    cases = [
        (1, 3), (-1, 2), (0, 0), (0, -3),
        (-105, -99), (-99, -105)]
    for start, end in cases:
        print(start, end, sa_range(start, end))
