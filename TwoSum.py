#Two sum

nums = [1,2,3,4,5,6,7]
target =  5

numIndex = {}

def twoSum(nums,target):
    for i,num in enumerate(nums):
        remaining = target - num
        if remaining in numIndex:
            return [numIndex[remaining],i]
        else:
            numIndex[num] = i

print(twoSum(nums,target))