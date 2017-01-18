import hashlib;

passcode="ngcjuoqr";
found=0;
num=0;
buff=[];

def get_hash(_str):
	md5hash=hashlib.md5();
	md5hash.update(_str.encode("utf8"));
	result=md5hash.hexdigest();
	for i in range(0, 2016):
		md5hash=hashlib.md5();
		md5hash.update(result.encode("utf8"));
		result=md5hash.hexdigest();
	return result

def check_if_contains(proc):
	result=proc;
	last=result[0];
	for digit in result[1:]:
		if last[-1]==digit:
			last+=digit;
			if len(last)==3:
				return [True, digit];
		else:
			last=digit;
	return [False];

def check_if_contains_digit(hashstr, checked_digit):
	result=hashstr;
	last=result[0];
	for digit in result[1:]:
		if last[-1]==digit and digit==checked_digit:
			last+=digit;
			if len(last)==5:
				return True;
		else:
			last=digit;
	return False;

for i in range(0, 1000):
	buff.append(get_hash(passcode+str(i)));

while found<64:
	proc=buff[0];
	buff=buff[1:]+[get_hash(passcode+str(num+len(buff)))];
	if len(check_if_contains(proc))==2:
		digit=check_if_contains(proc)[1];
		if any([check_if_contains_digit(hashstr, digit) for hashstr in buff]):
			found+=1;
			if found==64:
				print(num);
				break;
	num+=1;

