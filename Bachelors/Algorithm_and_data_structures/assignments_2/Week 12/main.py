from dp import longest_ordered_subarray, sum_in_triangle

def main() -> None:
    numbers = input("enter your numbers\n").split(" ")
    numbers = [int(num) for num in numbers]


    print(*longest_ordered_subarray(numbers))
    
    

    triangle = []

    while True:
        num = input("")

        if num.lower() == 'n':
            break

        num = num.split(" ")
        
        num = [int(i) for i in num]

        triangle.append(num)

    result = sum_in_triangle(triangle)

    print(triangle)

    print(f"{result[0]}\n{' '.join(map(str, result[1]))}")

if __name__ == "__main__":
    main()