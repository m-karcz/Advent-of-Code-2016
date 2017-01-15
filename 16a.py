input_str="00101000101111010";
size=272;

data=[True if i=="1" else False for i in input_str];

while len(data)<size:
	data+=[False] + [not i for i in reversed(data)];

data=data[:size];

while (len(data)%2)==0:
	data=[i==j for i,j in zip(data[0::2], data[1::2])];

print("".join(["1" if i else "0" for i in data]));

