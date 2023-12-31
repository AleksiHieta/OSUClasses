# Course: CS261 - Data Structures
# Student Name:
# Assignment:
# Description:
# Last revised:


from static_array import *


class DynamicArrayException(Exception):
    """
    Custom exception class to be used by Dynamic Array
    DO NOT CHANGE THIS CLASS IN ANY WAY
    """
    pass


class DynamicArray:
    def __init__(self, start_array=None):
        """
        Initialize new dynamic array
        DO NOT CHANGE THIS METHOD IN ANY WAY
        """
        self.size = 0
        self.capacity = 4
        self.first = 0  # do not use / change this value
        self.data = StaticArray(self.capacity)

        # populate dynamic array with initial values (if provided)
        # before using this feature, implement append() method
        if start_array is not None:
            for value in start_array:
                self.append(value)

    def __str__(self) -> str:
        """
        Return content of dynamic array in human-readable form
        DO NOT CHANGE THIS METHOD IN ANY WAY
        """
        out = "DYN_ARR Size/Cap: "
        out += str(self.size) + "/" + str(self.capacity) + ' ['
        out += ', '.join([str(self.data[_]) for _ in range(self.size)])
        return out + ']'

    def is_empty(self) -> bool:
        """
        Return True is array is empty / False otherwise
        DO NOT CHANGE THIS METHOD IN ANY WAY
        """
        return self.size == 0

    def length(self) -> int:
        """
        Return number of elements stored in array
        DO NOT CHANGE THIS METHOD IN ANY WAY
        """
        return self.size

    def resize(self, new_capacity: int) -> None:
        if (self.data[0] != None):
            self2 = DynamicArray()
            while (self2.capacity < self.capacity):
                self2.resize(self2.capacity*2)
            for i in range(0,self.size):
                self2.data[i] = self.data[i]
        
        if (new_capacity == 0):
            print("passed resize because 0 or less")
        elif (new_capacity < self.size):
            "print(passed resize because less than size)"
        else:
            self.capacity = new_capacity
            self.data = StaticArray(self.capacity)
            for i in range(0,self.size):
                self.data[i] = self2.data[i]
        pass

    def append(self, value: object) -> None:
        if (self.capacity == self.size):
            "print(===== Resized in Append =======)"
            self.resize(self.capacity*2)

        "print(self.capacity)"

        self.data[self.size] = value
        "print(self.size)"
        self.size += 1
        "print(self.size)"

        pass

    def insert_at_index(self, index: int, value: object) -> None:
        if (self.size == self.capacity):
            self.resize(self.capacity*2)
        if (index < 0):
            raise DynamicArrayException
        elif (index == 0):
            if (self.size == 1):
                self.data[1] = self.data[0]
                self.data[0] = value
                self.size += 1
            else:
                self2 = DynamicArray()
                while (self2.capacity < self.capacity):   # makes same size duped array
                    self2.resize(self2.capacity*2)
                for i in range(0,self.size):     # reassigns values to new array
                    self2.data[i] = self.data[i]
                self2.size = self.size
                for i in range(1, self.size+1):      # assigns values back 1 index off
                    self.data[i] = self2.data[i-1]
                self.data[0] = value
                self.size += 1
        else:
            if (index > self.size):
                raise DynamicArrayException
            else:
                self2 = DynamicArray()
                while (self2.capacity < self.capacity):   # makes same size duped array
                    self2.resize(self2.capacity*2)
                for i in range(0,self.size):     # reassigns values to new array
                    self2.data[i] = self.data[i]
                for i in range(0, index-1):
                    self.data[i] = self2.data[i]  # reassign first part
                for i in range(index+1, self.size+1):
                    self.data[i] = self2.data[i-1] # reassign second part
                self.data[index] = value
                self.size += 1
                
        pass

    def get_at_index(self, index: int) -> object:
        if (index < 0):
            raise DynamicArrayException
        if (index > self.size-1):
            raise DynamicArrayException
        else:
            return self.data[index]
        pass

    def remove_at_index(self, index: int) -> None:
        if (index < 0):
            raise DynamicArrayException
        if (index > self.size - 1):
            raise DynamicArrayException
        if (index == 0):
            self2 = DynamicArray()
            while (self2.capacity < self.capacity):   # makes same size duped array
                self2.resize(self2.capacity*2)
            for i in range(0,self.size):     # reassigns values to new array
                self2.data[i] = self.data[i]
            for i in range(1,self.size):
                self.data[i-1] = self2.data[i]
        else:
            self2 = DynamicArray()
            while (self2.capacity < self.capacity):   # makes same size duped array
                self2.resize(self2.capacity*2)
            for i in range(0,self.size):     # reassigns values to new array
                self2.data[i] = self.data[i]
            for i in range(0,index-1):
                self.data[i] = self2.data[i]
            for i in range(index,self.size-1):
                self.data[i] = self2.data[i+1]
        if (self.size < self.capacity/4):
            self.resize(self.capacity-(self.size-1)*2)

        self.size = self.size - 1
 
        pass

    def slice(self, start_index: int, quantity: int) -> object:
        if (start_index < 0):
            raise DynamicArrayException
        if (start_index > self.size - 1):
            raise DynamicArrayException
        elif (start_index > self.size):
            raise DynamicArrayException
        elif (quantity > (self.size - start_index)):
            raise DynamicArrayException
        elif (quantity < 0):
            raise DynamicArrayException

        self2 = DynamicArray()
        while (self2.capacity < quantity):
            self2.resize(self2.capacity*2)
        for i in range(start_index, start_index+quantity):
            self2.data[i-start_index] = self.data[i]
        self2.size = quantity
        return self2

    def merge(self, second_da: object) -> None:
        if (second_da.size == 0):
            pass
        else:
            #while (self.size+second_da.size < self.capacity):
            #    self.resize(self.capacity*2)

            #for i in range(self.size, self.size+second_da.size-1):
            #    self.data[i] = second_da.data[i-self.size]
            for i in range(0, second_da.size):
                self.append(second_da.data[i])
        pass

    def map(self, map_func) -> object:
        #for i in range(0, self.size):
        #    self.data[i] =

        return self

    def filter(self, filter_func) -> object:
        """
        TODO: Write this implementation
        """
        pass

    def reduce(self, reduce_func, initializer=None) -> object:
        """
        TODO: Write this implementation
        """
        pass

    def magic(self) -> None:
        for i in range(self.size-1, -1, -1):
            self.append(self.data[i])
            self.remove_at_index(i)
        return



# BASIC TESTING
if __name__ == "__main__":

    print("\n# resize - example 1")
    da = DynamicArray()
    print(da.size, da.capacity, da.data)
    da.resize(8)
    print(da.size, da.capacity, da.data)
    da.resize(2)
    print(da.size, da.capacity, da.data)
    da.resize(0)
    print(da.size, da.capacity, da.data)

    print("\n# resize - example 2")
    da = DynamicArray([1, 2, 3])
    print(da)
    da.resize(20)
    print(da)
    da.resize(4)
    print(da)

    print("\n# append - example 1")
    da = DynamicArray()
    print(da.size, da.capacity, da.data)
    da.append(1)
    print(da.size, da.capacity, da.data)
    print(da)

    print("\n# append - example 2")
    da = DynamicArray()
    for i in range(9):
        da.append(i + 101)
        print(da)

    print("\n# append - example 3")
    da = DynamicArray()
    for i in range(600):
        da.append(i)
    print(da.size)
    print(da.capacity)

    print("\n# insert_at_index - example 1")
    da = DynamicArray([100])
    print(da)
    da.insert_at_index(0, 200)
    print(da)
    da.insert_at_index(0, 300)
    print(da)
    da.insert_at_index(0, 400)
    print(da)
    da.insert_at_index(3, 500)
    print(da)
    da.insert_at_index(1, 600)
    print(da)

    print("\n# insert_at_index example 2")
    da = DynamicArray()
    try:
        da.insert_at_index(-1, 100)
    except Exception as e:
        print("Exception raised:", type(e))
    da.insert_at_index(0, 200)
    try:
        da.insert_at_index(2, 300)
    except Exception as e:
        print("Exception raised:", type(e))
    print(da)

    print("\n# insert at index example 3")
    da = DynamicArray()
    for i in range(1, 10):
        index, value = i - 4, i * 10
        try:
            da.insert_at_index(index, value)
        except Exception as e:
            print("Can not insert value", value, "at index", index)
    print(da)

    print("\n# get_at_index - example 1")
    da = DynamicArray([10, 20, 30, 40, 50])
    print(da)
    for i in range(4, -1, -1):
        print(da.get_at_index(i))

    print("\n# get_at_index example 2")
    da = DynamicArray([100, 200, 300, 400, 500])
    print(da)
    for i in range(-1, 7):
        try:
            print("Index", i, ": value", da.get_at_index(i))
        except Exception as e:
            print("Index", i, ": exception occurred")

    print("\n# remove_at_index - example 1")
    da = DynamicArray([10, 20, 30, 40, 50, 60, 70, 80])
    print(da)
    da.remove_at_index(1)
    print(da)
    da.remove_at_index(3)
    print(da)
    da.remove_at_index(2)
    print(da)

    # remove_at_index - example 2
    da = DynamicArray([1024])
    print(da)
    for i in range(17):
        da.insert_at_index(i, i)
    print(da.size, da.capacity)
    for i in range(16, -1, -1):
        da.remove_at_index(0)
    print(da)

    print("\n# remove_at_index - example 3")
    da = DynamicArray()
    print(da.size, da.capacity)
    [da.append(1) for i in range(100)]          # step 1 - add 100 elements
    print(da.size, da.capacity)
    [da.remove_at_index(0) for i in range(68)]  # step 2 - remove 69 elements
    print(da.size, da.capacity)
    da.remove_at_index(0)                       # step 3 - remove 1 element
    print(da.size, da.capacity)
    da.remove_at_index(0)                       # step 4 - remove 1 element
    print(da.size, da.capacity)
    [da.remove_at_index(0) for i in range(14)]  # step 5 - remove 14 elements
    print(da.size, da.capacity)
    da.remove_at_index(0)                       # step 6 - remove 1 element
    print(da.size, da.capacity)
    da.remove_at_index(0)                       # step 7 - remove 1 element
    print(da.size, da.capacity)

    for i in range(14):
        print("Before remove_at_index(): ", da.size, da.capacity, end="")
        da.remove_at_index(0)
        print(" After remove_at_index(): ", da.size, da.capacity)


    print("\n# remove at index - example 4")
    da = DynamicArray([1, 2, 3, 4, 5])
    print(da)
    for _ in range(5):
        da.remove_at_index(0)
        print(da)

    print("\n# slice example 1")
    da = DynamicArray([1, 2, 3, 4, 5, 6, 7, 8, 9])
    da_slice = da.slice(1, 3)
    print(da, da_slice, sep="\n")
    da_slice.remove_at_index(0)
    print(da, da_slice, sep="\n")

    print("\n# slice example 2")
    da = DynamicArray([10, 11, 12, 13, 14, 15, 16])
    print("SOUCE:", da)
    slices = [(0, 7), (-1, 7), (0, 8), (2, 3), (5, 0), (5, 3), (6, 1), (6, -1)]
    for i, cnt in slices:
        print("Slice", i, "/", cnt, end="")
        try:
            print(" --- OK: ", da.slice(i, cnt))
        except:
            print(" --- exception occurred.")


    print("\n")
    da2 = DynamicArray([10, 11, 12, 13, 14, 15, 16])
    print(da2)
    da2_slice = da2.slice(0,7)
    print(da2_slice)

    print("\n# merge example 1")
    da = DynamicArray([1, 2, 3, 4, 5])
    da2 = DynamicArray([10, 11, 12, 13])
    print(da)
    da.merge(da2)
    print(da)

    print("\n# merge example 2")
    da = DynamicArray([1, 2, 3])
    da2 = DynamicArray()
    da3 = DynamicArray()
    da.merge(da2)
    print(da)
    da2.merge(da3)
    print(da2)
    da3.merge(da)
    print(da3)

    print("\n# map example 1")
    da = DynamicArray([1, 5, 10, 15, 20, 25])
    print(da)
    print(da.map(lambda x: x ** 2))


    print("\n# map example 2")
    def double(value):
        return value * 2

    def square(value):
        return value ** 2

    def cube(value):
        return value ** 3

    def plus_one(value):
        return value + 1

    da = DynamicArray([plus_one, double, square, cube])
    for value in [1, 10, 20]:
        print(da.map(lambda x: x(value)))


    print("\n# filter example 1")
    def filter_a(e):
        return e > 10

    da = DynamicArray([1, 5, 10, 15, 20, 25])
    print(da)
    result = da.filter(filter_a)
    print(result)
    print(da.filter(lambda x: (10 <= x <= 20)))


    print("\n# filter example 2")
    def is_long_word(word, length):
        return len(word) > length

    da = DynamicArray("This is a sentence with some long words".split())
    print(da)
    for length in [3, 4, 7]:
        print(da.filter(lambda word: is_long_word(word, length)))


    print("\n# reduce example 1")
    values = [100, 5, 10, 15, 20, 25]
    da = DynamicArray(values)
    print(da)
    print(da.reduce(lambda x, y: x + y ** 2))
    print(da.reduce(lambda x, y: x + y ** 2, -1))

    print("\n# reduce example 2")
    da = DynamicArray([100])
    print(da.reduce(lambda x, y: x + y ** 2))
    print(da.reduce(lambda x, y: x + y ** 2, -1))
    da.remove_at_index(0)
    print(da.reduce(lambda x, y: x + y ** 2))
    print(da.reduce(lambda x, y: x + y ** 2, -1))



    print("===================")
    dasisgut = DynamicArray([20, 30, 40, 50, 60, 70, 80])
    print(dasisgut)
    dasisgut.magic()
    print(dasisgut)
