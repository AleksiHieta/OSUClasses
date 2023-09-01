# balance.py
# ===================================================
# Using a stack to check for unbalanced parentheses
# ===================================================

import sys

# Checks whether the input string is balanced
# param: input string
# returns True if string is balanced, otherwise returns False
def is_balanced(input_string):    
# initialize an empty list as the stack
    stack = []
    # iterate over each character in the string
    for char in input_string:
        if char in ["{", "(", "["]:
            stack.append(char)
        else:
            if not stack:
                return False
            current_char = stack.pop()
            if current_char == '(':
                if char != ")":
                    return False
            if current_char == '{':
                if char != "}":
                    return False
            if current_char == '[':
                if char != "]":
                    return False
            
    if stack:
        return False
    return True

if __name__ == '__main__':
    # get input string
    _input_string = sys.argv[1]
  # DO NOT MODIFY
    balanced = is_balanced(_input_string)
    if balanced:
        print("The string {} is balanced".format(_input_string))
    else:
        print("The string {} is not balanced".format(_input_string))
