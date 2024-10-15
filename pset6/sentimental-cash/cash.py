from cs50 import get_float

# Get change
change = None
while (not isinstance(change, float) or change < 0):
    try:
        change = float(get_float("Change: "))
    except:
        pass

# Multiply change by 100 to remove float
change = int(change * 100)

# Get coin values
quarter, dime, nickel, penny = 25, 10, 5, 1

# Coin counter
coins = 0

# Calculate change w/ number of coins
while change > 0:
    # check if change is larger than each coin (starting from the largest denomination)
    if change >= quarter:  # 0.25
        change -= quarter
    elif change >= dime:  # 0.10
        change -= dime
    elif change >= nickel:  # 0.05
        change -= nickel
    elif change >= penny:  # 0.01
        change -= penny

    # increment coin
    coins += 1

# print coins
print(coins)
