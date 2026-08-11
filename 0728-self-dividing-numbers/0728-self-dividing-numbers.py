class Solution(object):
    def f(self,x,n):
        if(n==0):
            return True

        y=n%10
        if(y==0 or x%y!=0):
            return False

        return self.f(x,n//10)

    def selfDividingNumbers(self, left, right):
        ans=[]

        for i in range(left,right+1):
            x=i
            if(self.f(x,i)):
                ans.append(x)

        return ans
        