from cs50 import get_int, get_string

# get card number
card = None
while not isinstance(card, int) or card < 0:
    try:
        card = get_int("Number: ")
    except:
        pass

# Convert card to str datatype
card = str(card)
length = len(card)

# Perform checksum
checksum = 0

# - rule 1: Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
for i in range(1, length, 2):
    x = int(card[-i-1]) * 2

    if x >= 10:  # exception case where the multiplication is > 10, and only the digits are added
        tens = x // 10
        ones = x % 10
        checksum += (tens + ones)
    else:
        checksum += x

# - rule 2: Add the sum to the sum of the digits that weren’t multiplied by 2.
for i in range(0, length, 2):
    checksum += int(card[-i-1])

print(checksum)
# - rule 3: If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
if checksum % 10 != 0:
    print("INVALID")
elif length == 15 and int(str(card)[:2]) in [34, 37]:
    print("AMEX")
elif length == 16 and int(str(card)[:2]) in [51, 52, 53, 54, 55]:
    print("MASTERCARD")
elif length in [13, 16] and int(str(card)[0]) == 4:
    print("VISA")
else:
    print("INVALID")
