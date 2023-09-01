# Course: CS261 - Data Structures
# Student Name:
# Assignment:
# Description:


from a1_include import *


def reverse(arr: StaticArray) -> None:
    """
    TODO: Write this implementation
    """
    arr2 = StaticArray(arr._size)

    #for i in range(0, arr._size-1):
    #    value = arr[(arr._size-1)-i]
    #    arr2.set(i, value)

    for i in range(0, arr._size):
    #    print(arr[i], arr[-i+arr._size-1])
        arr2[i] = arr[-i+arr._size-1]

    #print(arr2)

    for i in range(0, arr._size):
        arr[i] = arr2[i]

    #for i in range(0, arr._size-1):
    #    arr2[arr._size-1-i] = arr[i]

    return


# BASIC TESTING
if __name__ == "__main__":

    # example 1
    source = [_ for _ in range(-20, 20, 7)]
    arr = StaticArray(len(source))
    for i, value in enumerate(source):
        arr.set(i, value)
    print(arr)
    reverse(arr)
    print(arr)
