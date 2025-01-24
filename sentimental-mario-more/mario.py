def main():
    while True:
        try:
            height = input("Height: ")
            if height.isdigit() and int(height) > 0 and int(height) <= 8:
                height = int(height)
                break
            else:
                print("Input must be a number between 1 and 8")
        except ValueError:
            print("Invalid input. Please enter a valid number.")

    for i in range(1, height + 1):
        print(" " * (height - i), end="")
        print("#" * i, end="")
        print("  ", end="")
        print("#" * i)

if __name__ == "__main__":
    main()
