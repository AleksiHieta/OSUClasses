# word_count.py
# ===================================================
# Implement a word counter that counts the number of
# occurrences of all the words in a file. The word
# counter will return the top X words, as indicated
# by the user.
# ===================================================

import re
import string
from hash_map import HashMap

"""
This is the regular expression used to capture words. It could probably be endlessly
tweaked to catch more words, but this provides a standard we can test against, so don't
modify it for your assignment submission.
"""
rgx = re.compile("(\w[\w']*\w|\w)")

def hash_function_2(key):
    """
    This is a hash function that can be used for the hashmap.
    """

    hash = 0
    index = 0
    for i in key:
        hash = hash + (index + 1) * ord(i)
        index = index + 1
    return hash

def top_words(source, number):
    """
    Takes a plain text file and counts the number of occurrences of case insensitive words.
    Returns the top `number` of words in a list of tuples of the form (word, count).

    Args:
        source: the file name containing the text
        number: the number of top results to return (e.g. 5 would return the 5 most common words)
    Returns:
        A list of tuples of the form (word, count), sorted by most common word. (e.g. [("a", 23), ("the", 20), ("it", 10)])
    """
    s = open(source,'r').read()

    words = s.split()
    d = {}
    for w in words:
        if w in d:
            d[w] += 1
        else:
            d[w] = 1

    num_words = sum(d[w] for w in d)

    lst = [(d[w],w) for w in d]
    lst.sort()
    lst.reverse()

    return lst[:number]


    """
    for char in '-.,\n':
        source = source.replace(char,' ')
    source = source.lower()
    word_list = source.split()
    
    d = {}
    for word in word_list:
        if word not in d:
            d[word] = 0
        d[word] += 1

    word_freq = []
    for key, value in d.items():
        word_freq.append((value, key))
    word_freq.sort(reverse=True)
    
    return word_freq[:number-1]
    """
    """
    keys = set()

    ht = HashMap(2500,hash_function_2)

    # This block of code will read a file one word as a time and
    # put the word in `w`. It should be left as starter code.
    with open(source) as f:
        for line in f:
            words = rgx.findall(line)
            for w in words:
                
                ht.put(ht, w, 1)
    return []

                lw = w.lower()
                if lw in ht:
                    ht[lw] = ht[lw] + 1
                else:
                    ht[lw] = 1

    totals = []
    keys = ht.keys()
    for key in keys:
        totals.append((ht[key], key))
    totals = sorted(totals, reverse=True)
    for i in range(len(totals)):
        totals[i] = (totals[i][1], totals[i][0])
    return totals[:number]
    """
