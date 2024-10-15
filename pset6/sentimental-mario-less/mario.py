from cs50 import get_int

height = None
while (not isinstance(height, int) or (height < 1 or height > 8)):
    try:
        height = int(get_int("Height: "))
    except:
        print("Height should between 1 and 8.")

# create each row
for i in range(height):

    # create whitespace
    for _ in range(height-1 - i):
        print(" ", end="")

    # create '#'
    for _ in range(i+1):
        print("#", end="")

    # go to new line
    print("\n", end="")
