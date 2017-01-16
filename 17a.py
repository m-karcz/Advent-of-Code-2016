import hashlib;

def get_possibilites(str_to_check):
	passcode = "udskfozm";
	cipher = hashlib.md5();
	cipher.update((passcode+str_to_check).encode("utf8"));
	to_check=cipher.hexdigest();
	possibilities="";
	for i, direction in enumerate("UDLR"):
		if to_check[i] in "bcdef":
			possibilities+=direction;
	return possibilities;


def get_actual_location(path):
	[x, y]=[0,0];
	for letter in path:
		if letter=='D':
			y-=1;
		if letter=='U':
			y+=1;
		if letter=='L':
			x-=1;
		if letter=='R':
			x+=1;
	return [x,y];

def find_shortest_path():
	[max_x, min_y]=[3, -3];
	paths=[""];
	while True:
		new_paths=[];
		for path in paths:
			[x, y]=get_actual_location(path);
			if [x, y]==[max_x, min_y]:
				return path;
			possibilities=get_possibilites(path);
			if x==0:
				possibilities.replace("L", "");
			if x==max_x:
				possibilities.replace("R", "");
			if y==0:
				possibilities.replace("U", "");
			if y==min_y:
				possibilities.replace("D", "");
			for possibility in possibilities:
				new_paths+=[path+possibility];
		paths=new_paths;

print(find_shortest_path());
