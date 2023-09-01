#CS261
#Aleksi Hieta
#Bag Iterator
#

class _bagIterator:
    def __init__(self, theList):
        self._listItems = theList
        self._curItem = 0

    def __iter__(self):
        return self

    def __next__(self) -> int:
        next_thing = 2 * (self._listItems[self._curItem])  #Doubles value based on curItem
        self._curItem += 1
 
        return next_thing

if __name__ == "__main__":

    bag = _bagIterator([1, 2, 3])
    print(bag._curItem)   # checking curItem

    iter_bag = iter(bag)

    print(next(iter_bag))
    print(next(iter_bag))
    print(next(iter_bag))
    

