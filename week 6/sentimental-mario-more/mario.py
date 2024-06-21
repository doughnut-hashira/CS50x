while True:
    height = input("Height: ")
    if not height.isdigit():
        continue
    elif int(height) < 1 or int(height) > 8:
        continue
    else:
        h = int(height)
        for i in range(0, h):
            print(" " * (h - 1 - i) + "#" * (i + 1) + "  " + "#" * (i + 1))
        break
