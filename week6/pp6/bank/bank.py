greeting = input("Greeting: ")
rmspaces = greeting.lstrip()

if rmspaces.startswith("Hello"):
    print("$0")
elif rmspaces.startswith("H"):
    print("$20")
else:
    print("$100")