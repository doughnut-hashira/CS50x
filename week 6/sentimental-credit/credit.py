import cs50
from math import *
import sys

max = 16
key = 0
digits = []
credit = cs50.get_int("Number: ")
len = ceil(log(credit)/log(10))
temp = credit

if len > max:
    print("INVALID")
    sys.exit(1)

while (True):
    digits.append(int(temp % 10))
    temp /= 10
    if (temp <= 0):
        break

for i in range(len):
    if i % 2 == 1:
        if digits[i] > 4:
            key += ((2 * digits[i] % 100 - (2 * digits[i]) % 10) / 10) + ((2 * digits[i]) % 10)
        else:
            key += 2 * digits[i]
    else:
        key += digits[i]

if key % 10 != 0:
    print("INVALID")
    sys.exit(2)

if ((len == 13 or len == 16) and digits[len - 1] == 4):
    print("VISA")
elif (len == 16 and digits[15] == 5 and digits[14] in range(1, 6)):
    print("MASTERCARD")
elif (len == 15 and digits[14] == 3 and (digits[13] == 4 or digits[13] == 7)):
    print("AMEX")
else:
    print("INVALID")
    sys.exit(3)
