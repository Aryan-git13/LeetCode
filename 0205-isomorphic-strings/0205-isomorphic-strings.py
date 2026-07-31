class Solution(object):
    def isIsomorphic(self, s, t):
       m1={}
       m2={}

       for i in range(len(s)):
        if s[i] in m1 and m1[s[i]]!=t[i]:
            return False

        if t[i] in m2 and m2[t[i]]!=s[i]:
            return False

        m1[s[i]]=t[i]
        m2[t[i]]=s[i]

       return True
        