#!/bin/python3
# This challenge was solved together by users: cakdemir, emitrani, Batuhan Altundas, tgurkan
import sys

#[size,lowest[]]

def deleteFile(filenames, key, number):
    size = filenames[key][0]
    if size == 0 :
        filenames.pop(key, None)
        return
    else:
        filenames[key][0] -= 1
    if(number == -1):
        filenames[key].append(int(0))
    else:
        filenames[key].append(number)
        
    
    
def createFile(filenames, key):
    if key not in filenames:
        filenames[key] = [0]
        return 0
    filenames[key][0]+=1
    toPrint =  str(filenames[key][0]) 
    if len(filenames[key]) > 1:
        num = min(filenames[key][1:])
        filenames[key].remove(num)
        if num == 0:
            return 0
        else:
            return str(num)
     
    return toPrint       
    
    
q = int(input().strip())
filenames = {}
# Process each command
for a0 in range(q):
    # Read the first string denoting the command type
    command = input().strip().split()
    # Write additional code to read the command's file name(s) and process the command
    
    cmd = command[0]
    file = command[1].split("(")
    key = file[0]
    number = -1
    if len(file) > 1:
         number = int(file[1].strip(')'))  
    if key not in filenames:
        filenames[key] = [0]
        print("+ " + key)
        continue
        # Print the output string appropriate to the command
        
        
    if cmd[0] == 'r':
        #TODO
        file2 = command[2].split("(")
        key2 = file2[0]
        deleteFile(filenames, key, number)
        if key2 not in filenames:
            filenames[key2] = [0]
            if(number != -1 ):
                print("r " + key + '(' + str(number) + ')' + " -> " + key2 )
            else:
                print("r " + key + " -> " + key2)
            continue
        number2 = createFile(filenames, key2)
        if(number == -1 and number2 == 0):
            print("r " + key + " -> " + key2)
        elif(number == -1 and number2 != 0):
            print("r " + key + " -> " + key2 + '(' + number2 + ')')
        elif(number != -1 and number2 != 0):
            print("r " + key + '(' + str(number) + ')' + " -> " + key2 + '(' + number2 + ')')
        else:
            print("r " + key + '(' + str(number) + ')' + " -> " + key2)
        
        
        
    elif cmd[0] == 'd':
        deleteFile(filenames, key, number)
        if(number == -1):
            print("- " + key)
        else:
            print("- " + key + "(" + str(number) + ")")
                        
    else :
        #TODO
        toPrint = createFile(filenames, key)
        if(toPrint == 0):
             print("+ " + key)
        else:
            print("+ " + key + '(' + str(toPrint) + ')')
       
