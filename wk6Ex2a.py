def get_value_from_array(array, index):
    # Return the element from the array at the specified index
    return array[index]

def main():
    items = [902, 903, 904, 905, 906]
    for i in range(16):
        try:
            ret_val = get_value_from_array(items, i)
            print(f"Returned value at index {i} is {ret_val}")
        except IndexError:
            print(f"Index {i} is out of bounds")

if __name__ == "__main__":
    main()
