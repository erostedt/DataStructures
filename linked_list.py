class Node:

    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:

    def __init__(self):
        self.head = None

    def __len__(self):
        curr_node = self.head
        length = 0
        while curr_node:
            curr_node = curr_node.next
            length += 1
        return length

    def add_last(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
        else:
            curr_node = self.head
            while curr_node.next:
                curr_node = curr_node.next
            curr_node.next = new_node

    def add_first(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
        else:
            new_node.next = self.head
            self.head = new_node

    def insert(self, data, index):

        if index == 0:
            self.add_first(data=data)

        else:
            curr_idx = 0
            curr_node = self.head
            while curr_idx < index - 1:
                if not curr_node.next:
                    raise ValueError('Index out of bounds.')

                curr_node = curr_node.next
                curr_idx += 1

            new_node = Node(data)
            new_node.next = curr_node.next
            curr_node.next = new_node

    def delete(self, index):
        if index == 0:
            self.head = self.head.next
        else:
            curr_idx = 0
            curr_node = self.head
            while curr_idx < index - 1:
                if not curr_node.next:
                    raise ValueError('Index out of bounds')

                curr_node = curr_node.next
                curr_idx += 1

            curr_node.next = curr_node.next.next

    def reverse(self):
        prev_node = None
        curr_node = self.head

        while curr_node:
            next_node = curr_node.next
            curr_node.next = prev_node
            prev_node = curr_node
            curr_node = next_node

        self.head = prev_node

    def print_list(self):
        curr_node = self.head
        _print_list = []
        while curr_node:
            _print_list.append(curr_node.data)
            curr_node = curr_node.next

        print(_print_list)
