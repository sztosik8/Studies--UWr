class TreeItem:
    def __init__(self, value):
        self.val = value
        self.right = None
        self.left = None

def insert(root, value):
    if root == None: return TreeItem(value)
    if value < root.val:
        root.left = insert(root.left, value)
    else:
        if value > root.val:
            root.right = insert(root.right, value)
    return root

### zad 2 ###
def number_of_elements(root):
    if root == None: return 0
    if root.left != None:
        nodes_left = number_of_elements(root.left)
    else:
        nodes_left = 0
    if root.right != None:
        nodes_right = number_of_elements(root.right)
    else:
        nodes_right = 0
    return 1 + nodes_right + nodes_left

### zad 3 ###
def height(root):
    if root == None: return 0
    else:
        if root.left != None:
            left_height = height(root.left)
        else:
            left_height = 0
        if root.right != None:
            right_height = height(root.right)
        else:
            right_height = 0
        return 1 + max(left_height, right_height)

### zad 4 ###
def print_positive(root):
    if root == None:
        return
    if root.val > 0:
        if root.left != None:
            print_positive(root.left)
        print(root.val, end=" ")
    if root.right != None:
        if root.val > 0:
            print_positive(root.right)

### zad 5 ###
def is_bst(root, min, maks):
    if root == None:
        return 1
    if root.val >= maks:
        return 0
    if root.val <= min:
        return 0
    return is_bst(root.right, root.val, maks) and is_bst(root.left, min, root.val)

### zad 6 ###
def merge(root1, root2):
    if root1 == None:
        return root2
    if root2 == None:
        return root1
    if root1.val > root2.val:
        if root1.left != None:
            root1.left = merge(root1.left, root2)
        else:
            root1.left = root2
    else:
        if root1.right != None:
            root1.right = merge(root1.right, root2)
        else:
            root1.right = root2
    return root1

### zad 7 ###
def non_recursive_insert(root, value):
    root1 = root
    while root.left != None or root.right != None:
        if value < root.val:
            root = root.left
        else:
            root = root.right
    root = TreeItem(value)
    return root1


def non_recursive(root, key):

    newnode = TreeItem(key)
    x = root
    y = None
    while (x != None):
        y = x
        if (key < x.key):
            x = x.left
        else:
            x = x.right

    if (y == None):
        y = newnode
    elif (key < y.key):
        y.left = newnode
    else:
        y.right = newnode


T1 = TreeItem(1)
T2 = TreeItem(11)
T1 = insert(T1, 2)
T1 = insert(T1, 3)
T1 = insert(T1, 4)
T1 = insert(T1, 5)
T1 = insert(T1, 6)
T1 = insert(T1, 7)
T2 = insert(T2, 9)
T2 = insert(T2, 13)
T2 = insert(T2, 8)
T2 = insert(T2, 10)
T2 = insert(T2, 12)
T2 = insert(T2, 14)

# print(T1.val)
# print(height(T2))
# print(number_of_elements(T2))
# print_positive(T1)
# print()
# print_positive(T2)
T3 = merge(T1, T2)
# print()
print_positive(T3)
# min = float('-inf')
# maks = float('inf')
# # print()
# print(is_bst(T3, min, maks))