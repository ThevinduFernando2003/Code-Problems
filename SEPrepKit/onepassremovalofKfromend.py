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
# Complete the 'removeKthFromEnd' function below.
#
# The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
# The function accepts following parameters:
#  1. INTEGER_SINGLY_LINKED_LIST head
#  2. INTEGER k
#

def removeKthFromEnd(head, k):
    if k < 0:
        return head

    dummy = SinglyLinkedListNode(0)
    dummy.next = head
    slow = fast = dummy

    for _ in range(k + 1):
        if fast is None:
            return head
        fast = fast.next

    if fast is None:
        return head

    while fast.next:
        slow = slow.next
        fast = fast.next

    slow.next = slow.next.next
    return dummy.next


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

    k = int(input().strip())

    result = removeKthFromEnd(linked_list.head, k)
    print_linked_list(result)
