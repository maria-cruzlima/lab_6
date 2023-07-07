
import time

def y(x):
    return (x**4 + 3)
 

def BoolRegla(a, b):
     

    n = 4
 
    h = ((b - a) / n)
    sum = 0
 

    bl = (7 * y(a) + 32 * y(a + h) + 12 *
        y(a + 2 * h)+32 * y(a + 3 * h)+7 *
        y(a + 4 * h))* 2 * h / 45
 
    sum = sum + bl
    return sum

if __name__ == '__main__':
    start_time = time.time()
    lowlimit = 0
    upplimit = 10
    print("f(x) =",round(BoolRegla(lowlimit, upplimit),4))
    end_time = time.time()

    execution_time = (end_time - start_time) * 1000  

    print(f"Execution Time: {execution_time} ms")
