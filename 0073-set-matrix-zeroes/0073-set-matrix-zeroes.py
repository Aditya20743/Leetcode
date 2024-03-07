class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        
        row=[None]*len(matrix)
        col=[None]*len(matrix[0])
        for x in range(0, len(matrix)):
            for y in range(0,len(matrix[0])):
                if matrix[x][y] == 0:
                    row[x]=0
                    col[y]=0
                
        for x in range(0, len(matrix)):
            for y in range(0,len(matrix[0])):
                if (row[x]==0 or col[y]==0):
                    matrix[x][y]=0;
        
        return matrix