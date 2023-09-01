# Course: CS261 - Data Structures
# Student Name:
# Assignment:
# Description:


from a1_include import *


def fizz_buzz(arr: StaticArray) -> StaticArray:
    """
    TODO: Write this implementation
    """
    arr2 = StaticArray(arr._size)

    for i in range(0, arr._size):
        if (arr[i] % 15 == 0):
            arr2[i] = 'fizzbuzz'
        elif (arr[i] % 3 == 0):
            arr2[i] = 'fizz'
        elif (arr[i] % 5 == 0):
            arr2[i] = 'buzz'
        else:
            arr2[i] = arr[i]

    return arr2


# BASIC TESTING
if __name__ == "__main__":

    # example 1
    source = [_ for _ in range(-5, 20, 4)]
    arr = StaticArray(len(source))
    for i, value in enumerate(source):
        arr[i] = value
    print(arr)
    print(fizz_buzz(arr))
    print(arr)
