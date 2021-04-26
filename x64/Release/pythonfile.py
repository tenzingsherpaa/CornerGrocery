import re
import string

    
def splitingFood(foodieString):
    
    foodList = foodieString.split()
    
    return foodList

def srchCount(foodieString):
 
    count = 0
    counter = 0
    counts=0
    tester = False
    finList = []
    newList = []
    numList = []
    foodList = splitingFood(foodieString)
    for item in foodList:
        for new in newList:
            if item == new:
                tester = True
        if tester == False:
            newList.append(item)
        tester = False

        
    for item in newList:
        for new in foodList:
            if item == new:
                counter = counter + 1

        freqList.append(str(item) + "\n")
        freqList.append(str(counter) + "\n")
        counter = 0

        
    file1 = open('number.dat', 'w')

    file1.writelines(freqList)

    file1.close()
    
    userInp = input('Which item do you want to search?: ')

    file1 = open('number.dat', 'r')

    Liner = file1.readlines()
    
    for line in Liner:

        if count == 1:
            count = 0
            print(line.strip("\n"))

        if line.strip("\n") == userInp:
            print(line.strip("\n") + " ", end = "")
            count = 1
    
            
    file1.close()
    return 100

def hGram(foodieString):
    counter = 0
    counts=0
    tester = False
    finList = []
    newList = []
    freqList = []
    foodList = splitingFood(foodieString)
    for item in foodList:
        for new in newList:
            if item == new:
                tester = True
        if tester == False:
            newList.append(item)
        tester = False

        
    for item in newList:
        for new in foodList:
            if item == new:
                counter = counter + 1

        freqList.append(str(item) + "\n")
        freqList.append(str(counter) + "\n")
        counter = 0

 
    file1 = open('number.dat', 'w')

    file1.writelines(freqList)

    file1.close()
    file1 = open('number.dat', 'r')

    Liner = file1.readlines()
    
    for line in Liner:

        if counts % 2 == 0:

           print(line.strip("\n"), end = "")

        else:
            container = line.strip("\n")
            numContainer = int(container)
            for item in range(numContainer):
                print("*",end = "")        
            print("")
        
        counts = counts + 1

    file1.close()

  
    return 100

def oneCount(foodieString):
    counter = 0
    tester = False
    newList = []
    foodList = splitingFood(foodieString)
    for item in foodList:
        for new in newList:
            if item == new:
                tester = True
        if tester == False:
            newList.append(item)
        tester = False


       
    for item in newList:
        for new in foodList:
            if item == new:
                counter = counter + 1
        print(str(item) + " " + str(counter))
        counter = 0

    return 100