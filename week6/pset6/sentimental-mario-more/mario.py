# Repeatedly prompts the user for input
while True:
    # Makes sure input is an integer
    try:
        height = int(input("Height: "))
    except ValueError:
        continue
    # Makes sure that input is in correct range
    if height > 0 and height < 9:
        break

# Prints the pyramid
for i in range(height):
    for j in range(height + i + 3):
        if i + j < height - 1 or j == height or j == height + 1:
            print(" ", end='')
        else:
            print("#", end='')
    print("")