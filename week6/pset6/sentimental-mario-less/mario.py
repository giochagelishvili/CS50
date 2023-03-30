# Repeatedly prompts the user for height
while True:
    # Make sure the input is integer
    try:
        height = int(input("Height: "))
    except ValueError:
        continue

    # Make sure that input is between the correct range
    if height > 0 and height < 9:
        break

# Build a pyramid
for i in range(height):
    for j in range(height):
        if i + j < height - 1:
            print(" ", end='')
        elif i + j >= height - 1:
            print("#", end='')
    print("")