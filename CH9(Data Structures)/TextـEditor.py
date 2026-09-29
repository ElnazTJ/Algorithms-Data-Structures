import sys

class Node:

    def __init__(self, val=""):
        self.val = val
        self.prev = None
        self.next = None

def solve():
    # خواندن یک‌جای تمام داده‌ها با حداکثر سرعت برای q = 100,000
    input_data = sys.stdin.read().split()
    if not input_data:
        return

    q = int(input_data[0])

    head = Node()
    tail = Node()
    head.next = tail
    tail.prev = head

    cursor = head
    ptr = 1

    for _ in range(q):
        op = input_data[ptr]
        ptr += 1

        if op == "+":
            if cursor.next != tail:
                cursor = cursor.next

        elif op == "-":
            if cursor != head:
                cursor = cursor.prev

        elif op == "insert":
            c = input_data[ptr]
            ptr += 1

            new_node = Node(c)

            new_node.next = cursor.next
            cursor.next.prev = new_node
            new_node.prev = cursor
            cursor.next = new_node

            cursor = new_node

    result = []
    curr = head.next
    while curr != tail:
        result.append(curr.val)
        curr = curr.next

    print("".join(result))


if __name__ == "__main__":
    solve()