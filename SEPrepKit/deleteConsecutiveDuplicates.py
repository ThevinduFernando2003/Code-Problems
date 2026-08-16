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
# Complete the 'deleteDuplicates' function below.
#
# The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
# The function accepts INTEGER_SINGLY_LINKED_LIST head as parameter.
#

def deleteDuplicates(head):
    current = head

    while current and current.next:
        if current.data == current.next.data:
            current.next = current.next.next
        else:
            current = current.next

    return head


def print_linked_list(head):
    current = head
    while current:
        print(current.data)
        current = current.next


if __name__ == '__main__':
    linked_list_count = int(input().strip())

    linked_list = SinglyLinkedList()

    for _ in range(linked_list_count):
        linked_list_item = int(input().strip())
        linked_list.insert_node(linked_list_item)

    result = deleteDuplicates(linked_list.head)
    print_linked_list(result)
