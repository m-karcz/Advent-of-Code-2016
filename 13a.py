import sys;

fav=1350;
def xyfunc(x,y):
	return x*x+3*x+2*x*y+y+y*y;

def is_wall(x,y):
	return (sum(1 for i in bin(xyfunc(x,y)+fav)[2:] if i=='1')%2)==1;

class Vertex:
	def __init__(self, is_wall):
		self.is_wall=is_wall;
	is_wall;
	visited=False;
	upper_bound=sys.maxsize;

class Office:
	level=[[]];
	boss=[];
	def __init__(self, x, y):
		self.level=[[Vertex(is_wall(0,0))]];
		for i in range(0, y+2):
			self.expand_y();
		for i in range(0, x+2):
			self.expand_x();	
		self.boss=[x,y];
	def get_next(self):
		xy=[0,0];
		min_val=sys.maxsize;
		for y, line in enumerate(self.level):
			for x, vert in enumerate(self.level[y]):
				if not self.level[y][x].is_wall and not self.level[y][x].visited and self.level[y][x].upper_bound < min_val:
					min_val=self.level[y][x].upper_bound;
					xy=[x, y];
		return xy;
	def expand_x(self):
		x=len(self.level[0]);
		for y, line in enumerate(self.level):
			self.level[y].append(Vertex(is_wall(x, y)));
	def expand_y(self):
		new_line=[];
		y=len(self.level);
		for x, line in enumerate(self.level[0]):
			new_line.append(Vertex(is_wall(x, y)));
		self.level.append(new_line);
	def show(self):
		for line in self.level:
			for vert in line:
				sys.stdout.write('#' if vert.is_wall else ' ');
			print();
	def find_path(self):
		[x, y]=[1,1];
		self.level[y][x].upper_bound=0;
		while not self.level[self.boss[1]][self.boss[0]].visited :
			[x, y]=self.get_next();
			if x>=len(self.level[0])-2 :
				self.expand_x();
			if y>=len(self.level)-2 :
				self.expand_y();
			for [xx, yy] in [[x+1, y], [x, y+1], [x-1, y], [x, y-1]]:
				if xx>=0 and yy>=0:
					self.level[yy][xx].upper_bound=min(self.level[yy][xx].upper_bound, self.level[y][x].upper_bound+1);
			self.level[y][x].visited=True;
			
		print(self.level[self.boss[1]][self.boss[0]].upper_bound);

off=Office(31, 39);
off.find_path();
	
