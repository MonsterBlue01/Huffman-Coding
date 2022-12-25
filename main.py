import ast
from function import *

if __name__ == '__main__':
    choice = input("Are you using encoding or decoding?(0 for encoding, 1 for decoding)': ")
    while True:
        try:
            choice = int(choice)
            if choice != 0 and choice != 1:
                continue
            break
        except ValueError:
            choice = input("Invalid choice, please try again: ")
    if choice == 0:
        std = input("Do you want to use standard input? (else use file)(y/n): ")
        while True:
            if std == 'y' or std == 'n':
                break
            std = input("Invalid choice, please try again: ")
        if std == 'y':
            message = ""
            correct = ""
            while correct != 'y':
                message = input("Enter your message: ")
                correct = input("Is this correct?(y/n): ")
            frequency = create_frequency_table(message)
            print("Frequency table:", frequency)
            root = build_huffman_tree(frequency)
            codes = {}
            get_codes(root, codes, "")
            print("Codes: ", codes)
            encoded_message = encode(message, codes)
            print("Encoded message:", encoded_message)
            yn = input("Do you want to export the encoded message to a file?(y/n): ")
            while True:
                if yn == 'y' or yn == 'n':
                    break
                yn = input("Invalid choice, please try again: ")
            if yn == 'y':
                filename = input("Enter filename: ")
                with open(filename, 'w') as f:
                    f.write("Encoded_message: " + encoded_message)
                    f.write("\n")
                with open(filename, 'a') as f:
                    f.write("Codes: " + str(codes))
            elif yn == 'n':
                pass
            else:
                print("Something wrong happened, please try again later")
                exit(1)
        elif std == 'n':
            filename = input("Enter filename: ")
            while True:
                try:
                    with open(filename, 'r') as f:
                        message = f.read()
                        break
                except FileNotFoundError:
                    filename = input("File not found, please try again: ")
                except PermissionError:
                    filename = input("Permission denied, please try again: ")
            frequency = create_frequency_table(message)
            print("Frequency table:", frequency)
            root = build_huffman_tree(frequency)
            codes = {}
            get_codes(root, codes, "")
            print("Codes:", codes)
            encoded_message = encode(message, codes)
            print("Encoded message:", encoded_message)
            yn = input("Do you want to export the encoded message to a file?(y/n): ")
            while True:
                if yn == 'y' or yn == 'n':
                    break
                yn = input("Invalid choice, please try again: ")
            if yn == 'y':
                filename = input("Enter filename: ")
                with open(filename, 'w') as f:
                    f.write("Encoded_message: " + encoded_message)
                    f.write("\n")
                with open(filename, 'a') as f:
                    f.write("Codes: " + str(codes))
            elif yn == 'n':
                pass
            else:
                print("Something wrong happened, please try again later")
                exit(1)
        else:
            print("Something wrong happened, please try again later")
            exit(1)
    elif choice == 1:
        std = input("Do you want to use standard input? (else use file)(y/n): ")
        while True:
            if std == 'y' or std == 'n':
                break
            std = input("Invalid choice, please try again: ")
        if std == 'y':
            encoded_message = input("Please enter encoded message: ")
            code_table = input("Please enter code table in dictionary format: ")
            code_table = ast.literal_eval(code_table)
            root = decode_build_huffman_tree(code_table)
            decoded_message = decode(encoded_message, root)
            print("Decoded message: ", decoded_message)
        elif std == 'n':
            print("****************************************")
            print("The file should be in the following format:")
            print("Encoded_message: <encoded message>")
            print("Codes: <code table in dictionary format>")
            print("****************************************")
            filename = input("Enter filename: ")
            while True:
                try:
                    with open(filename, 'r') as f:
                        lines = f.readlines()
                        break
                except FileNotFoundError:
                    filename = input("File not found, please try again: ")
                except PermissionError:
                    filename = input("Permission denied, please try again: ")
            encoded_message = lines[0].split(": ")[1].strip()
            code_table = lines[1]
            code_table = code_table[code_table.find('{'):]
            code_table = ast.literal_eval(code_table)
            root = decode_build_huffman_tree(code_table)
            decoded_message = decode(encoded_message, root)
            print("Decoded message:", decoded_message)
        else:
            print("Something wrong happened, please try again later")
            exit(1)
    else:
        print("Something wrong happened, please try again later")
        exit(1)