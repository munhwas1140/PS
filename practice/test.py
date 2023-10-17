import traceback
try:
    data = input("Enter list of numbers: ") 
    numbers = map(int, data.split())
    min_ = next(numbers)
    for val in numbers: 
        if min_ > val: 
            min_ = val
        print("Minimum value:", min_)

except:
    traceback.print_exc()