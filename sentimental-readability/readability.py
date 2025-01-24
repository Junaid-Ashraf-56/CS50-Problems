import math

def count_letters(paragraph):
    count = 0
    for char in paragraph:
        if char.isalpha():
            count += 1
    return count

def count_words(paragraph):
    words = paragraph.split()
    return len(words)

def count_sentences(paragraph):
    count = 0
    for char in paragraph:
        if char in ['.', '?', '!']:
            count += 1
    return count

def main():
    paragraph = input("Enter paragraph: ")

    letters = count_letters(paragraph)
    words = count_words(paragraph)
    sentences = count_sentences(paragraph)

    L = (letters / words) * 100
    S = (sentences / words) * 100

    index = (0.0588 * L) - (0.296 * S) - 15.8

    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {round(index)}")

if __name__ == "__main__":
    main()
