import sys

def sol1func(filename,horMove,verMove):
    f = open(filename, "r")
    input = f.readlines()
    input = [x.strip() for x in input] 

    trees = 0
    for i in range(0,len(input),verMove):
        horIndex = (int(i/verMove)*horMove)%len(input[i])
        print(str(horIndex) + " " + str(i))
        charc = input[i][horIndex]
        # print(charc)

        log = list(input[i])
        if(charc == '#'):
            trees+=1
            log[horIndex] = 'X'
        else:
            log[horIndex] = 'O'
        print("".join(log))
                
            
    f.close()   

    return trees




def main(arg1, arg2):
    if len(sys.argv) is not 3:
        print("usage: " + sys.argv[0] + " <horizontalMove> <verticalMove>")
        exit(1)

    horMove = arg1
    verMove = arg2

    print(sol1func("input.txt",horMove,verMove))


if __name__ == "__main__":
    main(int(sys.argv[1]),int(sys.argv[2]))