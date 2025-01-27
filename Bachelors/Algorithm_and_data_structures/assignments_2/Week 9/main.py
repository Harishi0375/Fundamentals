from stack import Stack, Queue
from time import time

# Push time taken 9.5367431640625e-07
def push_time(stack: Stack) -> None:
    start_time = time()
    stack.push(50)
    end_time = time()
    execution_time = end_time - start_time
    print(f"Execution time: {execution_time} seconds")

# pop time 1.1920928955078125e-06
def pop_time(stack: Stack) -> None:
    start_time = time()
    stack.pop()
    end_time = time()
    execution_time = end_time - start_time
    print(f"Execution time: {execution_time} seconds")


def main() -> None:
    q = Queue()

    q.enqueue(5)
    q.enqueue(6)
    q.enqueue(7)
    q.print()

    print(q.dequeue())

    q.print()
    

if __name__ == "__main__":
    main()