def binary_search(lst, value):
    l = 0
    r = len(lst)-1

    while l<=r:
        m = l+(r-l)//2
        if lst[m] == value:
            return m
        if lst[m] > value:
            r = m-1
        else:
            l = m+1

    return -1

if __name__ == "__main__":
    # List must be sorted
    lst = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    print("Test with a number that is in the list")
    print(binary_search(lst, 10))
    
    print("Test with a number that is not in the list")
    print(binary_search(lst, 0))
