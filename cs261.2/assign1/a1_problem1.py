# Course: CS261 - Data Structures
# Student Name: Aleksi Hieta
# Assignment: Min & Max
# Description:


from a1_include import *


def min_max(arr: StaticArray) -> ():
    """
    TODO: Write this implementation
    """ 
    Min = arr[arr._size-1]
    Max = arr[arr._size-1]
    for i in range(1, arr._size):
        #print("Numbers: ")
        #print(arr[i-1], arr[i])
        if arr[i-1] < arr[i]:
            #print("In Min")
            if arr[i-1] < Min:
                #print("Replacing Min")
                Min = arr[i-1]
        if arr[i-1] > arr[i]:
            #print("In Max")
            if arr[i-1] > Max:
                #print("Replacing Max")
                Max = arr[i-1]
    
    return (Min, Max)   

# BASIC TESTING
if __name__ == "__main__":

    # example 1
    arr = StaticArray(5)
    for i, value in enumerate([-10, 7, 6, -5, -40]):
        arr[i] = value
    print(min_max(arr))

    # example 2
    arr = StaticArray(1)
    arr[0] = 100
    print(min_max(arr))

    # example 3
    arr = StaticArray(3)
    for i, value in enumerate([3, 3, 3]):
        arr[i] = value
    print(min_max(arr))

    arr = StaticArray(10)
    for i, value in enumerate([42041, -38677, 52491, 12440, -858, 40923, 86554, 39008, -53614, -88890]):
        arr[i] = value
    print(min_max(arr))




