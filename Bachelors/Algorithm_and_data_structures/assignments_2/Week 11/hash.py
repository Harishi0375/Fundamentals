from dataclasses import dataclass
from typing import Optional

@dataclass
class Node:
    key: int
    value: int

class HashTable:
    
    def __init__(self) -> None:
        self.arr = [[] for _ in range(100)]
        self.maxSize = 100
        self.current_size = 0

    def isEmpty(self) -> bool: return self.current_size == 0

    def get(self, key: int) -> Optional[int]: 
        index = self.hashCode(key)
        for node in self.arr[index]:
            if node.key == key:
                return node.value
            
        return None

    """
    for my hashing function I will use the mutltiplication method
    where I multiply the key by the golden ratio and then mod by the size of the table
    golden ratio as some scientist proved that its the best for most even dispurtion and mod
    m so that no indicie is greater than the max size
    """
    def hashCode(self, key: int) -> int:
        GOLDEN_RATION = 1.618033988749
        return int(GOLDEN_RATION * key % self.maxSize)
        

    def insertNode(self, key: int, value: int) -> None:
        index = self.hashCode(key)
        # Check for existing key and update it
        for node in self.arr[index]:
            if node.key == key:
                node.value = value  # Update the existing value
                return
        # If key is not found, append new node
        self.arr[index].append(Node(key, value))
        self.current_size += 1