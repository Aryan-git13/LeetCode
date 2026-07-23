class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        gs = 0
        cs = 0
        start = 0
        tot = 0

        for it in gas:
            gs += it

        for it in cost:
            cs += it

        if gs < cs:
            return -1

        for i in range(len(gas)):
            tot += gas[i] - cost[i]

            if tot < 0:
                start = i + 1
                tot = 0

        return start