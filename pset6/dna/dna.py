import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py database.csv sequence.txt")
        sys.exit(1)

    if sys.argv[1][-3:] != "csv":
        print("Database must be a csv file")
        sys.exit(1)

    if sys.argv[2][-3:] != "txt":
        print("Sequence must be a txt file")
        sys.exit(1)

    database = sys.argv[1]
    sequence = sys.argv[2]
    db_list = list()
    db_match = dict()

    # TODO: Read database file into a variable
    with open(database, 'r') as csvfile:
        reader = csv.DictReader(csvfile)
        STR = reader.fieldnames[1:]
        for row in reader:
            db_list.append(row)

    # TODO: Read DNA sequence file into a variable
    with open(sequence, 'r') as txtfile:
        seq = txtfile.readlines()[0]

    # TODO: Find longest match of each STR in DNA sequence
    for nucleotide in STR:
        db_match[nucleotide] = str(longest_match(seq, nucleotide))  # save match as str

    # TODO: Check database for matching profiles
    for row in db_list:
        person_STR = tuple(row.values())[1:]  # get no. of STR, in tuple

        # Check if person STR matches the sequence
        if person_STR == tuple(db_match.values()):
            print(row["name"])
            return
    # If there is no match
    print("No match")
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
