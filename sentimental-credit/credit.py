def is_valid_card_number(card_number):
    total = 0
    alternate = False
    length = len(card_number)

    # Loop through the card number in reverse order
    for i in range(length - 1, -1, -1):
        n = int(card_number[i])
        if alternate:
            n *= 2
            if n > 9:
                n -= 9
        total += n
        alternate = not alternate

    return total % 10 == 0

def is_american_express(card_number):
    return len(card_number) == 15 and card_number[0] == '3' and (card_number[1] == '4' or card_number[1] == '7')

def is_mastercard(card_number):
    return len(card_number) == 16 and card_number[0] == '5' and '1' <= card_number[1] <= '5'

def is_visa(card_number):
    return (len(card_number) == 13 or len(card_number) == 16) and card_number[0] == '4'

def main():
    card_number = input("Enter the credit card number: ")

    if is_valid_card_number(card_number):
        if is_american_express(card_number):
            print("AMEX")
        elif is_mastercard(card_number):
            print("MASTERCARD")
        elif is_visa(card_number):
            print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")

if __name__ == "__main__":
    main()
