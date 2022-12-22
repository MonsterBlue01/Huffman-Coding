from heapq import *

class Node:
    def __init__(self, char, frequency):
        self.char = char
        self.frequency = frequency
        self.left = None
        self.right = None

    def __lt__(self, other):
        return self.frequency < other.frequency

def build_huffman_tree(frequency_table):
    pq = []
    for c, f in frequency_table.items():
        heappush(pq, Node(c, f))

    while len(pq) > 1:
        left = heappop(pq)
        right = heappop(pq)
        frequency = left.frequency + right.frequency
        parent = Node('\0', frequency)
        parent.left = left
        parent.right = right
        heappush(pq, parent)

    return pq[0]

def get_codes(root, codes, code):
    if root is None:
        return
    if root.left is None and root.right is None:
        codes[root.char] = code
        return
    get_codes(root.left, codes, code + "0")
    get_codes(root.right, codes, code + "1")

def create_frequency_table(message):
    frequency_table = {}
    for s in message:
        if s in frequency_table:
            frequency_table[s] += 1
        else:
            frequency_table[s] = 1

    return frequency_table

def encode(message, codes):
    encoded_message = ""
    for s in message:
        encoded_message += codes[s]
    return encoded_message

def decode(encoded_message, root):
    decoded_message = ""
    current_node = root
    for bit in encoded_message:
        if bit == '0':
            current_node = current_node.left
        else:
            current_node = current_node.right

        if current_node.left is None and current_node.right is None:
            decoded_message += current_node.char
            current_node = root

    return decoded_message

def decode_build_huffman_tree(huffman_table):
    nodes = [(value, char) for char, value in huffman_table.items()]
    nodes.sort()
    root = Node(None, None)
    for value, char in nodes:
        curr = root
        for c in value:
            if c == '0':
                if curr.left is None:
                    curr.left = Node(None, None)
                curr = curr.left
            else:
                if curr.right is None:
                    curr.right = Node(None, None)
                curr = curr.right
        curr.char = char
    return root

def print_tree(root, code=""):
    if root is None:
        return
    if root.left is None and root.right is None:
        print(root.char, code)
        return
    print_tree(root.left, code + "0")
    print_tree(root.right, code + "1")