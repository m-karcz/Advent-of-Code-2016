class AsmInterpreter:
	registers = {"a": 0, "b": 0, "c": 1, "d": 0};
	index = 0;
	lines=[];
	def __init__(self, lines_arr):
		self.lines=lines_arr;
	def __value__(self, x):
		return self.registers[x] if x in self.registers else int(x);
	def __cpy__(self, x, y):
		self.registers[y] = self.__value__(x);
		self.index+=1;
	def __jnz__(self, x, y):
		self.index+= int(y) if self.__value__(x)!=0 else 1;
	def __inc__(self, x):
		self.registers[x]+=1;
		self.index+=1;
	def __dec__(self, x):
		self.registers[x]-=1;
		self.index+=1;
	functions = {"cpy": __cpy__, "jnz": __jnz__, "inc": __inc__, "dec": __dec__};
	def __interpret__(self):
		line_arr=self.lines[self.index].split();
		if len(line_arr) == 3:
			self.functions[line_arr[0]](self, line_arr[1], line_arr[2]);
		else:
			self.functions[line_arr[0]](self, line_arr[1]);
	def interpret(self):
		while self.index < len(self.lines):
			self.__interpret__();
			
x=AsmInterpreter(open("12.txt").readlines());
x.interpret();

print(x.registers["a"]);
