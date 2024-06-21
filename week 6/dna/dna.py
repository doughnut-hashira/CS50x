import csv
import sys


def main():
    result = [0]

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Format : dna.py csv_file txt_file")
        sys.exit(1)

    # TODO: Read database file into a variable
    with open(sys.argv[1], "r") as data:
        subsequence = list(csv.reader(data))

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2], "r") as Dna:
        sequence = list(csv.reader(Dna))
        sequence = sequence[0][0]

    # TODO: Find longest match of each STR in DNA sequence
    for i in range(1, len(subsequence[0])):
        result.insert(i, longest_match(sequence, subsequence[0][i]))
    # TODO: Check database for matching profiles

    number = 0
    for i in range(1, len(subsequence)):
        helper = True
        for j in range(1, len(result)):
            if (result[j] == int(subsequence[i][j])):
                helper = True
            else:
                helper = False
                break
        if helper:
            number = i
            break
    else:
        print("No Match")
        sys.exit(2)

    name = subsequence[number][0]
    print(name)
    return


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
