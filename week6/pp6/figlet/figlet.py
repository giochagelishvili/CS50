import sys
import random
from pyfiglet import Figlet

figlet = Figlet()

argc = len(sys.argv)

if argc != 1 and argc != 3:
    sys.exit("Invalid usage")

if argc == 3:
    if sys.argv[1] != "-f" and sys.argv[1] != "--font":
        sys.exit("Invalid usage")

    if sys.argv[2] not in figlet.getFonts():
        sys.exit("Invalid usage")

    str = input("Text: ")
    figlet.setFont(font=sys.argv[2])
    print(figlet.renderText(str))
elif argc == 1:
    str = input("Text: ")
    figlet.setFont(font=random.choice(figlet.getFonts()))
    print(figlet.renderText(str))