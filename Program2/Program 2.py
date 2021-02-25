# -*- coding: utf-8 -*-
"""
@author: Alex Rhomberg, Ryan Gooch, Duncan McCain, Kegan Huntley
Original K-NN code provided by Michael Thompson
"""

import numpy as np

def knn(k, data, dataClass, inputs):
    nInputs = np.shape(inputs)[0]
    closest = np.zeros(nInputs)
    
    for n in range(nInputs):
        distances = np.sum((data-inputs[n,:])**2,axis = 1)
        indices = np.argsort(distances, axis=0)
        
        classes = np.unique(dataClass[indices[:k]])
        if len(classes) == 1:
            closest[n] = np.unique(classes)
        else:
            counts = np.zeros(max(classes)+1)
            for i in range(k):
                counts[dataClass[indices[i]]] += 1
            closest[n] = np.argmax(counts)
            
    return closest

def normalizeData(data, names):
    nameRows = np.shape(names)[0]
    dataRows = np.shape(data)[0]
    normalized = np.zeros((dataRows, 1))
    
    for i in range(nameRows - 1):
        if names[i][1] == "D": #Finding the Discrete attributes/values
            for j in range(int(names[i][2])):
                newColumn = np.zeros((dataRows, 1))
                ind = np.where(data[:,i] == names[i][j + 3])
                newColumn[ind] = 1
                normalized = np.append(normalized, newColumn, axis=1)
        if names[i][1] == "C": #Finding the continuous attributes/values
            newColumn = np.zeros((dataRows, 1))
            for k in range(dataRows):
                newColumn[k] = data[k,i]
                newColumn[k] = newColumn[k] - float(names[i][2])
                newColumn[k] = newColumn[k] / (float(names[i][3]) - float(names[i][2]))
                newColumn[k] = newColumn[k] * 2
            normalized = np.append(normalized, newColumn, axis = 1)
    
    normalized = np.delete(normalized, 0, axis = 1) #Deleting the first column of 0's from normalized array
    return normalized

def convert(array, ogvalue, newvalue):
    for i in range(np.shape(array)[0]):
        if array[i] == ogvalue:
            array[i] = newvalue
     
    
#start the main
def main():

    myNames = np.genfromtxt('cars.names', delimiter=',', dtype = 'str')
    myTrain = np.genfromtxt('cars2.train', delimiter=',', dtype = 'str')
    myTest = np.genfromtxt('cars2.test', delimiter=',', dtype = 'str')
    
   
    # Determines the number of training examples.
    numAttributes = np.shape(myNames)[0]
    
    #divide the training data into the data and the class
    myTrainClass = myTrain[:,np.shape(myTrain)[1]-1]
    myTrain = myTrain[:,:np.shape(myTrain)[1]-1]
    myTrain = normalizeData(myTrain, myNames)
    
    
    #divide the testing data into the data and the class
    myTestClass = myTest[:,np.shape(myTest)[1]-1]
    myTest = myTest[:,:np.shape(myTest)[1]-1]
    myTest = normalizeData(myTest, myNames)
    
    #convert the numeric strings in the data to floats
    myTrain = myTrain.astype(np.float)
    myTest = myTest.astype(np.float)
    
    #Calling convert to change discrete values to continuous
    for j in range(int(myNames[numAttributes - 1][2])):
        convert(myTrainClass, myNames[numAttributes - 1][j+3], j)
        convert(myTestClass, myNames[numAttributes - 1][j+3], j)
    
    #convert the numeric strings in the class to int since they will index the count array
    myTrainClass = myTrainClass.astype(np.int)
    myTestClass = myTestClass.astype(np.int)
    
    perm = np.random.permutation(np.shape(myTrain)[0])
    myTrain = myTrain[perm,:]
    myTrainClass = myTrainClass[perm]
    
    #Creating the 80% and 20% split of our data
    eighty = (np.shape(myTrain)[0] // 5) * 4
    myVald = myTrain[:eighty,:]
    myValdTest = myTrain[eighty:,:]
    
    myValdClass = myTrainClass[:eighty]
    myValdTestClass = myTrainClass[eighty:]
    
    best = knn(1, myVald, myValdClass, myValdTest)
    bestIndex = 1
    
    for i in range(2, 16):
        newData = knn(i,myVald, myValdClass, myValdTest)
        
        bestDiff = myValdTestClass - best  #any results that are different will be nonzero
        bestDiff = np.where(bestDiff!=0,0,1)  #give incorrect (nonzero) results a vaule of 0, and correct ones 1
        bestCorrect = np.sum(bestDiff)
        bestCorrectness = 100*bestCorrect/np.shape(bestDiff)[0]
        
        newDiff = myValdTestClass - newData  #any results that are different will be nonzero
        newDiff = np.where(newDiff!=0,0,1)  #give incorrect (nonzero) results a vaule of 0, and correct ones 1
        newCorrect = np.sum(newDiff)
        newCorrectness = 100*newCorrect/np.shape(newDiff)[0]
        
        if newCorrectness > bestCorrectness:
            best = newData
            bestIndex = i
    
    #Using the best index or k to test our orginal testing set
    final = knn(bestIndex, myTrain, myTrainClass, myTest)
    finalDiff = myTestClass - final  #any results that are different will be nonzero
    finalDiff = np.where(finalDiff!=0,0,1)  #give incorrect (nonzero) results a vaule of 0, and correct ones 1
    finalCorrect = np.sum(finalDiff)
    finalCorrectness = 100*finalCorrect/np.shape(finalDiff)[0]
    
    print("Correctness:", finalCorrectness, "%")
    print("The best k value is", bestIndex)

if __name__ == "__main__":
    main()