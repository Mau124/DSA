def bubble_sort(lst):
    for i in range(len(lst)):
        for j in range(len(lst)-1):
            if lst[j] > lst[j+1]:
                lst[j], lst[j+1] = lst[j+1], lst[j]

if __name__ == "__main__":
    lst = [9, 7, 5, 6, 2, 1, 4, 3, 0, 8]
    print("Unsorted list")
    print(lst)
    print("Sorted list")
    bubble_sort(lst)
    print(lst)
