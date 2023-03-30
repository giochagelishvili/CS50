import csv

with open("books.csv") as books_file:
    file_reader = csv.DictReader(file)
    for book in file_reader:
        print(book)