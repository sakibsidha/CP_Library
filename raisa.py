def avg(a, b):
    c = (a+b)/2
    return c
    
a= float (input("Enter first number"))
b= float (input("Enter second number"))
ans = avg(a,b)
print (" Average is ",ans )
print (f"Average is {ans}")




list1 = [1, 2, 3, 6, 7, 9]
for i in list1:
    if i%2==0:
        print(i, end= ",")
print()

n = int (input ("in: "))
for i in range (1, 11):
    if i == 6:
        continue
    if i > 8:
        break
    print ( n, "x" , i , "=", n*i)
        
sum = 0   
for i in range (1, 11):
    sum = sum + i
print (sum)

sum = 0
list1 = [1, 2, 4, 7, 9]
for i in list1:
    if i % 2 == 0:
        sum = sum + i
print (f"sum of even = {sum}")
