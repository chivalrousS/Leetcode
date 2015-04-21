class Solution:
    # @param num, a list of integer
    # @return an integer
    def findMin(self, num):
        length = len(num)
        index1 = 0
        index2 = length - 1
        midindex = index1
        while (num[index1] >= num[index2]):
            if(index2 == index1 + 1):
                midindex = index2
                break
            midindex = (index1 + index2) / 2
            if(midindex ==index1 and index1 == index2):
                midindex = index1
                break
            if(num[midindex] >= num[index1]):
                index1 = midindex
            elif (num[midindex] <= num[index2]):
                index2 = midindex
        return num[midindex]
        
        