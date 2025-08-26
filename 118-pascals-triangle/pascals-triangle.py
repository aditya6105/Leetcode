class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        l = []
        for i in range(1, numRows+1):
            temp = [1]
            a = 1
            for j in range(1, i):
                a = a * (i - j)//j
                temp.append(a)
            l.append(temp)
        return l