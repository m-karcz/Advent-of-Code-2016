import re

print(sum(any([any((word[i]==word[i+3] and word[i+1]==word[i+2] and word[i]!=word[i+1] for i in range(0, len(word)-3))) for word in re.findall(r"(\w+)+", line)[0::2]]) and not any([any((word[i]==word[i+3] and word[i+1]==word[i+2] and word[i]!=word[i+1] for i in range(0, len(word)-3))) for word in re.findall(r"(\w+)+", line)[1::2]]) for line in open("7.txt").readlines()));

