class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        grp = {}

        for s in strs:
            # Fixed 1: Correctly create a sorted string key
            key = "".join(sorted(s))
            
            # Fixed 2 & 3: Group elements into a list
            if key not in grp:
                grp[key] = []
            grp[key].append(s)

        return list(grp.values())
