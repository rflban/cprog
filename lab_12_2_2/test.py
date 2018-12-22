import ctypes


lib = ctypes.CDLL('./libmyarray.so')

__fill_fiboncci = lib.fill_fiboncci
__fill_fiboncci.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int)
__fill_fiboncci.restype = None

__copy_first_entries = lib.copy_first_entries
__copy_first_entries.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int,
                                 ctypes.POINTER(ctypes.c_int), ctypes.c_int)
__copy_first_entries.restype = None

def fill_fiboncci(source):
    array_len = len(source)
    array = (ctypes.c_int * array_len)(*source)

    res = __fill_fiboncci(array, array_len)

    for i in range(array_len):
        source[i] = array[i]

    return res

def copy_first_entries(source1, source2):
    array1_len = len(source1)
    array2_len = len(source2)
    array1 = (ctypes.c_int * array1_len)(*source1)
    array2 = (ctypes.c_int * array1_len)(*source1)

    for i in range(array2_len):
        array2[i] = 0

    res = __copy_first_entries(array1, array1_len, array2, array2_len)

    for i in range(array2_len):
        source2[i] = array2[i]


def main():
    print('Test fill_fiboncci.')
    array = [0] * 10
    print('Initial array:')
    print(array)
    fill_fiboncci(array)
    print('Result array:')
    print(array)
    
    print()

    print('Test copy_first_entries.')
    array1 = [1, 2, 5, 2, 1, 5, 6, 7, 1]
    array2 = [0] * len(array1)
    print("Initial arrays:")
    print(array1)
    print(array2)
    copy_first_entries(array1, array2)
    print("Result arrays:")
    print(array1)
    print(array2)

if __name__ == '__main__':
    main()