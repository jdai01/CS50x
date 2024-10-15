from cs50 import get_string
import re


def coleman_liau_index(L: float, S: float) -> int:
    index = 0.0588 * L - 0.296 * S - 15.8
    return round(index)


def count_letters(text: str) -> int:
    # split text into individual letters, based on alphabets
    letters = re.findall(r'[a-zA-Z]', text)
    return len(letters)


def count_words(text: str) -> int:
    # split text into individual words, based on whitespaces
    words = re.split(r'\s+', text)
    return len(words)


def count_sentences(text: str) -> int:
    # split text into individual sentences, based on punctuations
    sentences = re.split(r'[.!?]\s', text.strip())
    sentences = [s for s in sentences if s]  # remove empty spaces
    return len(sentences)


# Get text input
text = get_string("Text: ")

# Calculate Coleman-Liau index
letter_cnt = count_letters(text)
word_cnt = count_words(text)
sentence_cnt = count_sentences(text)
L = letter_cnt / (word_cnt/100)
S = sentence_cnt / (word_cnt/100)
index = coleman_liau_index(L, S)

# Output
if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
