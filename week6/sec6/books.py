books = []

for i in range(2):
    book = dict()
    book["title"] = input("Title: ").strip().capitalize()
    book["author"] = input("Author: ")

    books.append(book)

for book in books:
    print(book["title"])