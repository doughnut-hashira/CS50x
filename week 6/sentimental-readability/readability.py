
text = input("Text : ")
while (len(text) < 1):
    text = input("Text : ")

letters = 0
for i in range(len(text)):
    if text[i].isalpha():
        letters += 1

words = text.count(" ") + 1
sentences = text.count(".") + text.count("?") + text.count("!")

print(letters, words, sentences)

L = letters/words * 100
S = sentences/words * 100
temp = ((0.0588 * L) - (0.296 * S) - 15.8)
tem = temp - int(temp)

if (tem != 0 and tem >= 0.55):
    index = temp - tem + 1
else:
    index = temp

if (index < 1):
    print("Before Grade 1")
elif (index > 16):
    print("Grade 16+")
else:
    print(f"Grade {int(index)}")
