import re;

class Disc:
	size=0;
	position=0;
	def __init__(self, size, position):
		self.size=size;
		self.position=position;
	def check_if_would_pass(self, num):
		return (self.position+num) % self.size == 0;

class Sculpture:
	discs=[];
	def check_if_all_would_pass(self, num):
		return all([disc.check_if_would_pass(i+num+1) for (i, disc) in enumerate(self.discs)]);
	def rotate_all(self):
		for disc in self.discs:
			disc.rotate()

sculpture=Sculpture();
data=open("15.txt");
time=1;

for line in data.readlines():
	result=re.match(r"^.*has (\d+) positions.*position (\d+)", str(line));
	sculpture.discs.append(Disc(int(result.group(1)), int(result.group(2))));

while not sculpture.check_if_all_would_pass(time):
	time+=1;

print(time);
