import sys
from cs50 import get_int


def main():
    # Prompt the user for card number using get_number() function
    card_number = get_number()

    # Check the if the card number is valid according to Luhn's algorithm using is_valid() function
    validation = is_valid(card_number)

    # Check the type of the card using check_type() function
    check_type(validation, card_number)


# Checks the type of the given card number
def check_type(valid, cardNum):
    # Check if the card number is valid
    if valid:
        # Turn card number into a string and get the length
        toStr = str(cardNum)
        length = len(toStr)

        # Check if card is AMEX
        if length == 15 and (toStr[0:2] == '34' or toStr[0:2] == '37'):
            print("AMEX")
            sys.exit()
        # Check if card is MASTERCARD
        elif length == 16 and (toStr[0:2] == '51' or toStr[0:2] == '52' or toStr[0:2] == '53' or toStr[0:2] == '54' or toStr[0:2] == '55'):
            print("MASTERCARD")
            sys.exit()
        # Check if card is VISA
        elif (length == 13 or length == 16) and toStr[0] == '4':
            print("VISA")
            sys.exit()
        # Else print INVALID and stop the program
        else:
            print("INVALID")
            sys.exit()


# Validates the card number according to Luhn's algorithm
def is_valid(num):
    # Lists to store the numbers
    evenNumbers = []
    oddNumbers = []

    # Turn card number into a reversed string and get the length
    numToString = str(num)[::-1]
    length = len(numToString)

    # Iterate through reversed string
    for i in range(length):
        # Get oddly placed digits
        if i % 2 != 0:
            # Turn the digit into a string and multiply by 2 as instructed in Luhn's algorithm
            toInt = int(numToString[i]) * 2
            # Check if digit * 2 is greater than 9
            if toInt > 9:
                # Append digits separately into the list (e.g. digit = 7, 7 * 2 = 14, we need to append 1 and 4 separately)
                toStr = str(toInt)
                oddNumbers.append(int(toStr[0]))
                oddNumbers.append(int(toStr[1]))
            else:
                # Else append the digit
                oddNumbers.append(toInt)

    # Iterate through reversed string for the leftover numbers
    for j in range(length):
        # Get the rest of the digits from card number
        if j % 2 == 0:
            evenNumbers.append(int(numToString[j]))

    # Sum up the digits
    checkSum = sum(oddNumbers) + sum(evenNumbers)

    # Card number is valid if % 10 is 0
    if (checkSum % 10) == 0:
        return True
    else:
        # Else print INVALID and exit program
        print("INVALID")
        sys.exit()


# Repeatedly prompts the user for non-negative integer
def get_number():
    while True:
        num = get_int("Number: ")
        if num > 0:
            return num


# Call the main function
if __name__ == '__main__':
    main()