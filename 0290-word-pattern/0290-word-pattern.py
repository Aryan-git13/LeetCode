class Solution(object):
    def wordPattern(self, pattern, s):
        words=s.split()
        if(len(pattern)!=len(words)):
            return False
        m1={}
        m2={}

        for i in range(len(pattern)):
            if pattern[i] in m1 and m1[pattern[i]]!=words[i]:
                return False
            if words[i] in m2 and m2[words[i]]!=pattern[i]:
                return False
            m1[pattern[i]]=words[i]
            m2[words[i]]=pattern[i]

        return True
        