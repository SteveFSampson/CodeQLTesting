def get_value_from_array(array, index):
    # Ensure the index is within the valid range
    if index < 0 or index >= len(array):
        raise IndexError("Index out of bounds")
    # Return the element from the array at the specified index
    return array[index]