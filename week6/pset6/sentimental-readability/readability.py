from cs50 import get_string


def main():
    # Get the text from the user
    text = get_text()

    # Count how many letters are in the given text using count_letters() function
    letters = count_letters(text)

    # Count how many words are in the given text using count_words() function
    words = count_words(text)

    # Count how many sentences are in the given text using count_sentences() function
    sentences = count_sentences(text)

    # Calculate average number of letters per 100 words in the text using calculate_l() function
    l = calculate_l(letters, words)

    # Calculate average number of sentences per 100 words in the text using calculate_s() function
    s = calculate_s(sentences, words)

    # Calculate The Coleman-Liau index and round it to nearest integer
    index = index = 0.0588 * l - 0.296 * s - 15.8
    index = round(index)

    # Output the grade
    if index >= 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {index}")


# Calculates average number of sentences per 100 words in the text
def calculate_s(sentences, words):
    s = sentences / words * 100
    s = round(s, 2)
    return s


# Calculates average number of letters per 100 words in the text
def calculate_l(letters, words):
    l = letters / words * 100
    l = round(l, 2)
    return l


# Counts how many sentences are in the given text
def count_sentences(text):
    sentences = 0

    for i in text:
        if i == '.' or i == '?' or i == '!':
            sentences += 1

    return sentences


# Counts how many words are in the given text
def count_words(text):
    words = 0

    for i in text:
        if i == " ":
            words += 1
    words += 1

    return words


# Counts how many letters are in the given text
def count_letters(text):
    letters = 0

    for i in text:
        if i.isalpha():
            letters += 1

    return letters


# Prompts the user for input string
def get_text():
    text = get_string("Text: ")
    return text


# Call the main function
if __name__ == '__main__':
    main()