class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ""
        mnLen = 1000000000
        for str in strs:
            mnLen = min(mnLen, len(str))
        ans = ""
        for l in range(1, mnLen + 1, 1):
            ok = True
            currentPrefix = ""
            for str in strs:
                if currentPrefix == "":
                    currentPrefix = str[0: l]
                else:
                    nowPrefix = str[0: l]
                    if nowPrefix != currentPrefix:
                        ok = False
            if ok:
                ans = currentPrefix
        return ans