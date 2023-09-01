from word_count import *
f = open('alice.txt', 'r')
content = f.read()

print("\n\n***************** WORD COUNT TEST *******************")
print("---Top Words---")
print(top_words(content, 3))
