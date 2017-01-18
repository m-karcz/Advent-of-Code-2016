import hashlib;

passcode="ngcjuoqr";

def get_hash(_str):
	md5hash=hashlib.md5();
	md5hash.update(_str.encode("utf8"));
	return md5hash.hexdigest();

def check_if_contains(num):
	result=get_hash(passcode+str(num));
	last=result[0];
	for digit in result[1:]:
		if last[-1]==digit:
			last+=digit;
			if len(last)==3:
				return [True, digit];
		else:
			last=digit;
	return [False];

def check_if_contains_digit(num, checked_digit):
	result=get_hash(passcode+str(num));
	last=result[0];
	for digit in result[1:]:
		if last[-1]==digit and digit==checked_digit:
			last+=digit;
			if len(last)==5:
				return True;
		else:
			last=digit;
	return False;

found=0;
num=0;
while found<64:
	if len(check_if_contains(num))==2:
		digit=check_if_contains(num)[1];
		if any([check_if_contains_digit(i, digit) for i in range(num+1, num+1000)]):
			found+=1;
			if found==64:
				print(num);
				break;
	num+=1;

