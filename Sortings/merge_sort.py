def merge(lst, l , r):
    size = (r-l)+1
    m = l+(r-l)//2
    ptr1 = l
    ptr2 = m+1
    i = 0
    
    aux = [0]  * size
    while ptr1 <= m or ptr2 <= r:
        if ptr1 <= m and ptr2 <= r:
            if lst[ptr1] >= lst[ptr2]:
                aux[i] = lst[ptr2]
                ptr2+=1
            else:
                aux[i] = lst[ptr1]
                ptr1+=1
        elif ptr1 <= m:
            aux[i] = lst[ptr1]
            ptr1+=1
        else:
            aux[i] = lst[ptr2] 
            ptr2+=1
        i+=1

    for i in range(size):
        lst[l+i] = aux[i]

def merge_sort(lst, l, r):
    if l>=r:
        return

    m = l+(r-l)//2
    merge_sort(lst, l, m)
    merge_sort(lst, m+1, r)
    merge(lst, l, r)

if __name__ == "__main__":
    lst = [9, 7, 5, 6, 2, 1, 4, 3, 0, 8]
    print("Unsorted list")
    print(lst)
    print("Sorted list")
    merge_sort(lst, 0, len(lst)-1)
    print(lst)

