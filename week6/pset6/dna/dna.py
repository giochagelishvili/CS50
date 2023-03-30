import csv
import sys


def main():
    # Ensure the proper usage
    argc = len(sys.argv)
    if argc != 3:
        print("Program should use 2 command-line arguments")
        sys.exit()
    elif argc == 3:
        if ".csv" not in sys.argv[1]:
            print("First command-line argument should be a CSV file.")
            sys.exit()
        elif ".txt" not in sys.argv[2]:
            print("Second command-line argument should be a TXT file.")
            sys.exit()

    # Read CSV file into database[]
    database = []
    with open(sys.argv[1], 'r') as csvFile:
        csvreader = csv.DictReader(csvFile)
        for i in csvreader:
            database.append(i)

    # Read DNA sequence file into a variable
    with open(sys.argv[2], 'r') as sequence:
        txtreader = sequence.read()

    # Find longest match of each STR in DNA sequence
    subsequences = list(database[0].keys())[1:]

    results = {}

    # Save the results in results{}
    for i in subsequences:
        results[i] = longest_match(txtreader, i)

    # Check database for matching profiles
    for i in database:
        counter = 0
        for j in subsequences:
            if int(i[j]) == results[j]:
                counter += 1

        # Print the person's name if all sequences match
        if counter == len(subsequences):
            print(i["name"])
            return

    # Else print no match
    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
