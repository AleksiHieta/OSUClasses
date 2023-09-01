# Course: CS261 - Data Structures
# Student Name:
# Assignment:
# Description:


from a1_include import *


def rotate(arr: StaticArray, steps: int) -> StaticArray:
    """
    TODO: Write this implementation
    """
    arr2 = StaticArray(arr._size)

    while (steps < 0): #handles negative numbers
        steps = steps + arr._size

    steps = steps % arr._size #handles large positive numbers
    
    #print(steps)

    for i in range(steps, arr._size):
        arr2[i] = arr[i-steps]

    count = 0
    for i in range(arr._size-steps, arr._size):
        arr2[count] = arr[i]
        count = count+1

    #print(arr2)


    return arr2


# BASIC TESTING
if __name__ == "__main__":

    # example 1
    source = [_ for _ in range(-20, 20, 7)]
    arr = StaticArray(len(source))
    for i, value in enumerate(source):
        arr.set(i, value)
    print(arr)
    for steps in [1, 2, 0, -1, -2, 28, -100]:
        print(rotate(arr, steps), steps)
    print(arr)
