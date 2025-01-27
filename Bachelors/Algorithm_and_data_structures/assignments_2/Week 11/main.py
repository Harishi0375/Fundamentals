from hash import HashTable

def main() -> None: 
    table = HashTable()

    print(table.isEmpty())
    

    table.insertNode(5, 6)
    print(table.get(5))
    table.insertNode(5,100)
    print(table.get(5))
    table.insertNode(6,300)
    print(table.get(6))

    # should print 2
    print(table.current_size)

    print(table.isEmpty())


if __name__ == "__main__":
    main()