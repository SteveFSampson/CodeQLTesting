int getValueFromArray(int *array, int len, int index)
{
    if (index >= 0 && index < len)
    {
        return array[index];
    }
    else
    {
        // Handle invalid index
        return -1; // or some other error code
    }
}