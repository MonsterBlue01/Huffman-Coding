# Notes

This file contains notes and documentation for the project.

## Table of Contents
- [Assumption](#Assumption)
- [TODO](#todo)

## Assumption

- Encode can generate the corresponding frequency table and huffman tree according to the characters. But the huffman tree is also needed when decoding. It may be cumbersome to directly let the user enter the huffman tree. So should I let the user input the code table as a string and use eval or a similar function to convert it into a dict before decoding?

## TODO

- Try assumption 1
    + > Encode can generate the corresponding frequency table and huffman tree according to the characters. But the huffman tree is also needed when decoding. It may be cumbersome to directly let the user enter the huffman tree. So should I let the user input the code table as a string and use eval or a similar function to convert it into a dict before decoding? [*Done*]

- Try to separate the other functions from the main function (put them in different files) after basically everything is done [*Done*]
- Try to put huffman's code table into the file [*Done*]
- Complete the content in README.md [*Done*]
- Start writing WRITEUP.tex [*Done*]
- Complete the part about Encoding and Decoding design in the LaTeX document (since the introduction of function has been mentioned in the function part, try to focus on the whole rather than these modules, such as explaining the main function)
