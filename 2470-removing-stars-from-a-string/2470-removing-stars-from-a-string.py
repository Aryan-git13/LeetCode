class Solution(object):
    def removeStars(self, s):
        p=""
        for i in range(len(s)):
            if(s[i]!='*'):
                p+=s[i]
            else:
                p=p[:-1]

        return p

        