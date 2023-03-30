from cs50 import SQL

db = SQL("sqlite:///favorites.db")

favorite = input("Favorite: ")

rows = db.execute("SELECT * FROM favorites WHERE problem = ?", favorite)

print(rows[0]["language"])