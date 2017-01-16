import hashlib;

[max_x, min_y]=[3, -3];
class Level:
	left_moves=[];
	path="";
	location=[0,0];
	possibilities="";
	def __init__(self, path, location, move):
		self.path=path+move;
		self.location=location[:];
		if move=="U":
			self.location[1]+=1;
		if move=="D":
			self.location[1]-=1;
		if move=="L":
			self.location[0]-=1;
		if move=="R":
			self.location[0]+=1;
		self.get_possibilities();
	def get_possibilities(self):
		passcode = "udskfozm";
		cipher = hashlib.md5();
		cipher.update((passcode+self.path).encode("utf8"));
		to_check=cipher.hexdigest();
		self.possibilities="";
		for i, direction in enumerate("UDLR"):
			if to_check[i] in "bcdef":
				self.possibilities+=direction;
		if self.location[0]==0:
			self.possibilities=self.possibilities.replace("L", "");
		if self.location[0]==max_x:
			self.possibilities=self.possibilities.replace("R", "");
		if self.location[1]==0:
			self.possibilities=self.possibilities.replace("U", "");
		if self.location[1]==min_y:
			self.possibilities=self.possibilities.replace("D", "");
	def get_next(self):
		next_one=Level(self.path, self.location[:], self.possibilities[-1]);
		self.possibilities=self.possibilities[:-1];
		return next_one;
	
max_level=0;
stack=[Level("", [0,0], "")];
while len(stack)!=0:
	if stack[-1].possibilities=="" or stack[-1].location==[3,-3]:
		stack.pop();
	else:
		stack.append(stack[-1].get_next());
		if len(stack)>max_level and stack[-1].location==[3,-3]:
			max_level=len(stack);
print(max_level-1);
