#!/bin/python3

import math
import os
import random
import re
import sys


class SinglyLinkedListNode:
    def __init__(self, node_data):
        self.data = node_data
        self.next = None


class SinglyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert_node(self, node_data):
        node = SinglyLinkedListNode(node_data)
        if not self.head:
            self.head = node
        else:
            self.tail.next = node
        self.tail = node


#
# Complete the 'reverseEvenIndexedAndAppend' function below.
#
# Collect even-indexed nodes (0-based), reverse that sequence, and append
# it after the remaining odd-indexed nodes.
# The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
# The function accepts INTEGER_SINGLY_LINKED_LIST head as parameter.
#

def reverseEvenIndexedAndAppend(head):
    if not head:
        return None
    odd_head = odd_tail = None
    evens = []
    node = head
    index = 0
    while node:
        nxt = node.next
        node.next = None
        if index % 2 == 0:
            evens.append(node)
        else:
            if odd_tail:
                odd_tail.next = node
            else:
                odd_head = node
            odd_tail = node
        node = nxt
        index += 1
    evens.reverse()
    result = odd_head
    tail = odd_tail
    for even_node in evens:
        if tail:
            tail.next = even_node
        else:
            result = even_node
        tail = even_node
    return result


def print_linked_list(head):
    current = head
    while current:
        print(current.data)
        current = current.next


if __name__ == '__main__':
    head_count = int(input().strip())
    head = SinglyLinkedList()
    for _ in range(head_count):
        head.insert_node(int(input().strip()))
    result = reverseEvenIndexedAndAppend(head.head)
    print_linked_list(result)
