from cs50 import get_float


def main():
    # Repeatedly prompts the user for non-negative value
    while True:
        amount = get_float("Change owed: ")
        if amount >= 0:
            break

    # Calculate how many quarters fit in the given amount
    quarters = calculate_quarters(amount)
    amount = amount - quarters * 0.25
    amount = round(amount, 2)

    # Calculate how many dimes fit in the given (remaining) amount
    dimes = calculate_dimes(amount)
    amount = amount - dimes * 0.1
    amount = round(amount, 2)

    # Calculate how many nickels fit in the given (remaining) amount
    nickels = calculate_nickels(amount)
    amount = amount - nickels * 0.05
    amount = round(amount, 2)

    # Calculate how many pennies fit in the given (remaining) amount
    pennies = calculate_pennies(amount)
    amount = amount - pennies * 0.01
    amount = round(amount, 2)

    # Sum up the amount of coins
    sum = quarters + dimes + nickels + pennies

    # Print the amount of coins
    print(sum)


# Calculate pennies
def calculate_pennies(amount):
    counter = 0
    while amount >= 0.01:
        amount -= 0.01
        amount = round(amount, 2)
        counter += 1
    return counter


# Calculate nickels
def calculate_nickels(amount):
    counter = 0
    while amount >= 0.05:
        amount -= 0.05
        amount = round(amount, 2)
        counter += 1
    return counter


# Calculate dimes
def calculate_dimes(amount):
    counter = 0
    while amount >= 0.1:
        amount -= 0.1
        amount = round(amount, 2)
        counter += 1
    return counter


# Calculate quarters
def calculate_quarters(amount):
    counter = 0
    while amount >= 0.25:
        amount -= 0.25
        amount = round(amount, 2)
        counter += 1
    return counter


# Call the main function
if __name__ == "__main__":
    main()