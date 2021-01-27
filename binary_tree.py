class Node:

    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class BinarySearchTree:

    def __init__(self, root):
        self.root = Node(root)
        self.nodes = 1

    def __len__(self):
        return self.nodes

    def __contains__(self, data):

        return self._find_node(node=self.root, data=data)

    def add_node(self, data):
        try:
            self._add_node(self.root, data)
            self.nodes += 1
        except ValueError:
            pass

    def _add_node(self, curr_node, data):
        if data < curr_node.data:   # Go left?
            if curr_node.left:
                self._add_node(curr_node.left, data)
            else:
                curr_node.left = Node(data)

        elif data > curr_node.data:     # Go right
            if curr_node.right:
                self._add_node(curr_node.right, data)
            else:
                curr_node.right = Node(data)

        else:
            raise ValueError('Cannot add duplicate values')

    def delete_node(self, data):
        try:
            self._delete_node(curr_node=self.root, parent=None, data=data)
            self.nodes -= 1

        except ValueError:
            pass

    def _delete_node(self, curr_node, parent, data):
        if curr_node:

            if data == curr_node.data:
                if parent.data > curr_node.data:    # went left
                    if curr_node.right:
                        parent.left = curr_node.right
                        parent.left.left = curr_node.left
                    else:
                        parent.left = curr_node.left

                else:
                    if curr_node.right:
                        parent.right = curr_node.right
                        parent.right.left = curr_node.left
                    else:
                        parent.right = curr_node.right

                return
            else:
                next_node = curr_node.left if data < curr_node.data else curr_node.right
                self._delete_node(curr_node=next_node, parent=curr_node, data=data)

        else:
            raise ValueError('Value not in tree')

    @staticmethod
    def _find_node(node, data):
        while node:
            if node.data == data:
                return True

            if data < node.data:
                node = node.left
            else:
                node = node.right

        return False

    def traverse(self, order='in order'):
        if order == 'in order':
            self._in_order(self.root)

    def _in_order(self, node):
        if node:
            self._in_order(node=node.left)
            print(node.data)
            self._in_order(node=node.right)


bst = BinarySearchTree(10)

bst.add_node(2)
bst.add_node(7)
bst.add_node(18)
bst.add_node(4)
bst.add_node(0)
bst.add_node(11)
bst.add_node(3)
bst.delete_node(11)
bst.traverse()
print('len =', len(bst))
print(4 in bst)

