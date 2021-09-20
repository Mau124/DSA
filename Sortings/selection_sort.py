def selection_sort(lst):
    for i in range(len(lst)-1):
        minVal = i
        for j in range(i+1, len(lst)):
            if lst[j] < lst[minVal]:
                minVal = j
        lst[i], lst[minVal] = lst[minVal], lst[i]

if __name__ == "__main__":
    lst = [9, 7, 5, 6, 2, 1, 4, 3, 0, 8]
    print("Unsorted list")
    print(lst)
    print("Sorted list")
    selection_sort(lst)
    print(lst)


