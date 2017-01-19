table=[[c!="^" for c in ".^^^^^.^^.^^^.^...^..^^.^.^..^^^^^^^^^^..^...^^.^..^^^^..^^^^...^.^.^^^^^^^^....^..^^^^^^.^^^.^^^.^^"]];

while len(table)<40:
	table.append([left==right for left,right in zip([True]+table[-1][:-1], table[-1][1:]+[True])]);

print(sum(sum(line) for line in table));
