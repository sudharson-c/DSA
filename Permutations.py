n = "ABC"

res = []

def backtrack(i,currStr):
    if(len(currStr)==len(n)):
        res.append(currStr)
        return

    for c in n:
        if c not in currStr:
            backtrack(i+1,currStr+c)
if n:
    backtrack(0,"")
print(res)
print("Permutation count: ",len(res))