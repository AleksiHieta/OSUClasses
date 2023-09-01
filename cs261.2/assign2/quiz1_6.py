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

    def insert_at_index(self, index: int, value: object) -> None:
        if (self.size == self.capacity):
            self.capacity = self.capacity*2
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
                    self2.capacity = self2.capacity*2
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
                    self2.capacity = self2.capacity*2
                for i in range(0,self.size):     # reassigns values to new array
                    self2.data[i] = self.data[i]
                for i in range(0, index-1):
                    self.data[i] = self2.data[i]  # reassign first part
                for i in range(index+1, self.size+1):
                    self.data[i] = self2.data[i-1] # reassign second part
                self.data[index] = value
                self.size += 1
                
        pass
