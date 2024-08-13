arr = [-2,-3,4,-1,-2,1,5,-3]

max = -999
sum = 0
for i in arr:
    sum += i
    if sum> max:
        max =sum
    elif sum<0:
        sum = 0

print(max)