# Huffman Coding

## Usage:

```bash
python3 main.py # You may also need to install some necessary libraries
```

## Steps for Encoding:

1. Read text and convert it to a frequency table.
2. Build a Huffman tree from a frequency table.
3. Traverse the Huffman tree and store all characters and corresponding codes into a dictionary.
4. Encode the original message using the dictionary.

## Steps for Decoding:

1. Get the code table and binary code from the user.
2. Build a Huffman tree from the code table.
3. Decode the binary code using the Huffman tree.   

## License

This project is licensed under the Creative Commons Attribution License (CC-BY 4.0). See the LICENSE file for details.

## References:

1. [Huffman Coding](https://en.wikipedia.org/wiki/Huffman_coding)