#!/usr/bin/env python3

while True:
  try:
    para1 = []
    while True:
      line = input()
      if line == "#":
        break
      for word in line.split():
        para1.append(word)

    para2 = []
    while True:
      line = input()
      if line == "#":
        break
      for word in line.split():
        para2.append(word)

    m = len(para1)
    n = len(para2)
    dp = [[-1] * (n + 1) for i in range(m + 1)]
    def LCS(p1, p2):
      for i in range(0, m + 1):
        for j in range(0, n + 1):
          if i == 0 or j == 0:
            dp[i][j] = 0
          elif p1[i - 1] == p2[j - 1]:
            dp[i][j] = dp[i - 1][j - 1] + 1
          else:
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j])
      return dp[m][n]

    def printLCS(p1, p2):
      length = dp[m][n]
      path = [""] * length
      i = m
      j = n
      while i > 0 and j > 0:
        if p1[i - 1] == p2[j - 1]:
          path[length - 1] = p1[i - 1]
          i -= 1
          j -= 1
          length -= 1
        elif dp[i][j - 1] > dp[i - 1][j]:
          j -= 1
        else:
          i -= 1
      print(' '.join(path))

    LCS(para1, para2)
    printLCS(para1, para2)
  except EOFError:
    break
