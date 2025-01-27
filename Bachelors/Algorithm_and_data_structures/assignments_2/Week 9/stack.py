from dataclasses import dataclass

@dataclass 
class Node:
    data: any
    next: 'Node' = None
    prev: 'Node' = None


class Stack:
    def __init__(self, data: any = None, size: int=10) -> None:
        self.root = Node(data)
        self.top = self.root
        self.size = size
        self.current_size = 0

    def isEmpty(self) -> bool:
        return self.current_size == 0

    def push(self, data: any) -> None:
        if self.current_size == self.size:
            print("Stack Overflow")
            return

        new_node = Node(data)
        new_node.prev = self.top
        self.top.next = new_node  # Link the new node to the previous top node
        self.top = new_node
        self.current_size += 1

    def pop(self) -> any:
        if self.isEmpty():
            print("Stack underflow")
            return None

        temp = self.top.data
        self.top = self.top.prev
        self.top.next = None  # Remove the link to the popped node
        self.current_size -= 1
        return temp

    def print(self) -> None:
        cursor = self.root
        while cursor is not None:
            print(cursor.data)
            cursor = cursor.next


class Queue:
    def __init__(self) -> None:
        self.enqueue_stack: Stack = Stack()
        self.dequeue_stack: Stack = Stack()

    def enqueue(self, data: any) -> None:
        self.enqueue_stack.push(data)

    def dequeue(self) -> any:
        if self.dequeue_stack.isEmpty():
            # Transfer elements from enqueue stack to dequeue stack
            while not self.enqueue_stack.isEmpty():
                self.dequeue_stack.push(self.enqueue_stack.pop())

        # Pop from dequeue stack
        return self.dequeue_stack.pop()

    def print(self) -> None:
        dequeue_stack_empty = self.dequeue_stack.isEmpty()
        enqueue_stack_empty = self.enqueue_stack.isEmpty()

        if not dequeue_stack_empty or not enqueue_stack_empty:
            print("Elements in the queue:")

        if not dequeue_stack_empty:
            self.dequeue_stack.print()

        if not enqueue_stack_empty:
            self.enqueue_stack.print()

