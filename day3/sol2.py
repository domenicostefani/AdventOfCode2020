import sol1

moves = [ [ 1, 1],
          [ 3, 1],
          [ 5, 1],
          [ 7, 1],
          [ 1, 2]]

tot = 1
for moveset in moves:
    horMove = moveset[0]
    verMove = moveset[1]
    rtrees = sol1.sol1func("input.txt",horMove,verMove)
    print("Trees for " + str(horMove) + " " + str(verMove) + ": " + str(rtrees))
    tot *= rtrees

print("Tot: " + str(tot))