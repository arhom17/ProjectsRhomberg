"""
Program Name: Naive Bayes Calculator
Programmers: Ryan Gooch, Kegan Huntley, Duncan McCain, Alex Rhomberg.
Date: 3/19/2020
Program Discription: This program is able to calculate Naive Bayes when provided training file, testing file, and a names file. 
These files should be formated in '.csv'. It will the output whether or not our testing data accuracy predicted the testing data's classification
by computing the number of correct guesses divided by the total number of test categories.
"""

# Imports numpy, allows the use of np.shape, np.array, np.append, etc.
import numpy as np

# This function takes in an array, a column, and a value and categorizes an array so that it is only focuses on one class header.
def reduceArray(ary, col, val):
    empty = True
    for i in range(np.shape(ary)[0]):
        if ary[i,col] == val:
            if empty:
                empty = False
                a2 = np.array([ary[i,:]])
            else:
                a2 = np.append(a2, [ary[i,:]], axis=0)
    if empty:
        return False
    else:
        return a2

# This function takes in an array, a column, and a value and returns how many times that value appears in that array and column.
def countVals(ary, col, val):
    count = 0
    for v in ary[:,col]:
        if v == val:
            count += 1
            
    return count

# This is the main function.
def main():
    
    # Reads in the data from the '.csv' files.
    trainData = np.genfromtxt('Train.csv', delimiter=',', dtype = 'str')
    testData = np.genfromtxt('Test.csv', delimiter = ',', dtype = 'str')
    names = np.genfromtxt('Names.csv', delimiter = ',', dtype = 'str')
    
    # Determines the number of training examples.
    totalTrain = np.shape(trainData)[0]
    totalTest = np.shape(testData)[0]
    totalNames = np.shape(names)[1]
    numAttributes = np.shape(names)[0]
    
    # Sets the number of correct classifications to zero.
    correct = 0
    
    # For each testing example
    for i in range(totalTest):
        #For each possible output class:
        for j in range(1, totalNames):
            # Reduce the dataset to only contain examples of that output class
            if names[numAttributes - 1, j] != 'x':
                examples = reduceArray(trainData, (numAttributes - 1), names[numAttributes - 1, j])
                # Generate the first fraction for Naive Bayes and make it be a part of the running product.
                runningTotal = (np.shape(examples)[0])/totalTrain
                # For each non-output attribute:
                for k in range(numAttributes - 1):
                    count = countVals(examples, k, testData[i, k])
                    #Find the fraction for that attribute and multiply that by the running product.
                    runningTotal = runningTotal * (count/np.shape(examples)[0])
                # Compare the product to the best product and update the best product and class if necessary.
                if j == 1 and names[numAttributes - 1, j] != 'x':
                    bestClass = names[numAttributes - 1, j]
                    bestProduct = runningTotal
                elif runningTotal > bestProduct:
                    bestClass = names[numAttributes - 1, j]
                    bestProduct = runningTotal
        # Check to see if the best class matches the target class of the examples and count it if necessary.
        if bestClass == testData[i, numAttributes - 1]:
            correct = correct + 1
    
    # Calculating and printing the accuracy.
    accuracy = correct/totalTest
    print("We were", accuracy* 100, "percent correct.")
    
    
if __name__ == "__main__":
    main()