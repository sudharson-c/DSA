#Longest Common Subsequence

text1 = "bacbacbd"
text2 = "bacbd"
string = ""

dp = [ [0 for i in range(len(text2)+1)] for j in range(len(text1)+1)]

for i in range(len(text1)-1,-1,-1):
    for j in range(len(text2)-1,-1,-1):
        if text1[i] == text2[j]:
            dp[i][j] = 1 + dp[i+1][j+1]
        else:
            dp[i][j] = max(dp[i+1][j],dp[i][j+1])
print(dp[0][0])
#To print the common sequence

i,j = 0,0
while i<len(text1) and j<len(text2):
    if text1[i]==text2[j]:
        string += text1[i]
        i+=1
        j+=1
    elif dp[i+1][j]>dp[i][j+1]:
        i+=1
    else:
        j+=1

print(string)