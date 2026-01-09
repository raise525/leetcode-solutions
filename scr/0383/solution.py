from collections import defaultdict
class solution:
    def  canconstruct(self,ransomNote:str,magazine:str)->bool:
        if len(ransomNote)>len(magazine):
            return False
        cnt = defaultdict(int)  #自动创建并赋默认值，键值对
        for c in magazine:
            cnt[c]+=1
        for c in ransomNote:
            cnt[c]-=1
        return all(c>=0 for c in cnt.values())
        

# 没有用小技巧：1. 选中变量后，按f2，可以全局中的名字