def insertion_sort(lst):
    for i in range(len(lst)):
        j = i
        while j>0 and lst[j] < lst[j-1]:
            lst[j], lst[j-1] = lst[j-1], lst[j]
            j -= 1

if __name__ == "__main__":
    lst = [9, 7, 5, 6, 2, 1, 4, 3, 0, 8]
    print("Unsorted list")
    print(lst)
    print("Sorted list")
    insertion_sort(lst)
    print(lst)
