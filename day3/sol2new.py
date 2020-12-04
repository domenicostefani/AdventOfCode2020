
filename = "input.txt"
f = open(filename, "r")
input = f.readlines()
input = [x.strip() for x in input] 

moves = [[1,1],
         [3,1],
         [5,1],
         [7,1],
         [1,2]]

tot = 1

for moveset in moves:
    print("moveset:" + str(moveset))
    right = moveset[0]
    down = moveset[1]
    trees = 0

    for i in range(len(input)):
        if (i%down == 0):
            horIdx = (i*right)%len(input[i])
            if(input[i][horIdx] == '#'):
                trees += 1
    print("Trees: " + str(trees))
    tot *= trees

print("Tot: " + str(tot))
f.close()