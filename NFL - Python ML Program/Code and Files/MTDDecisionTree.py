# -*- coding: utf-8 -*-
"""
Created on Wed May 13 09:21:04 2020

@author: rg546046
"""

import numpy as np
import math

def findBest(classes, classNames, best):
    numVals = len(classNames)
    count = np.zeros(numVals)
    for i in range(numVals):
        count[i] = np.shape(np.where(classes == classNames[i]))[1]
        
    bestIndex = 0
    for i in range(1, numVals):
        if count[i] == count[bestIndex] and classNames[i] == best:
            bestIndex = i
        elif count[i] > count[bestIndex]:
            bestIndex = i
            
    return classNames[bestIndex]

def entropy(data, classNames):  
    mySum = 0
    total = np.shape(data)[0]
    for cVal in classNames:
        ind = np.where(data == cVal)
        num = np.shape(ind)[1]
        if num > 0:
            mySum -= (num/total)*math.log2(num/total)
    return mySum
    
    

def gain(data, classes, names, index):
    numAttr = np.shape(names)[0]-1
    gVal = 0
    cls = names[numAttr, 3:]
    ent = entropy(classes, cls)
    total = np.shape(data)[0]
    for i in range(int(names[index,2])):
        ind = np.where(data[:,index] == names[index, i+3])
        num = np.shape(ind)[1]
        if num > 0:
            redClasses = classes[ind]
            gVal += (num/total)*entropy(redClasses, cls)
        
    
    return ent - gVal


class DecTreeNode:
    def __init__(self):
        self._children = []
        self._parent = ""
        self._attribute = -1
        self._attrName = ""
        self._value = ""
        self._class = ""
        
    def getValue(self):
        return self._value
    
    def setValue(self, v):
        self._value = v
        
    def classify(self, example):
        if self._class != "":
            return self._class
        else:
            for child in self._children:
                if example[self._attribute] == child.getValue():
                    example = np.delete(example, self._attribute, axis=0)
                    return child.classify(example)
                
        print("OOPS!!")
        
    def print(self, offset):
        if self._class != "":
            print(" "*offset, self._class)
        else:
            print(" "*offset, self._attrName.upper()+"?")
            for child in self._children:
                print(" "*(offset+3), "="+child.getValue())
                child.print(offset+6)
                
    def create(self, data, classes, names, best):

        numAttr = np.shape(names)[0]-1
       
        vals = np.unique(classes)
        if len(vals) == 0:
            self._class = best
            return
        elif len(vals) == 1:
            self._class = vals[0]
            return
        elif numAttr==0:
            self._class = findBest(classes, names[numAttr,3:], best)
            return
        else:
        
            # Find attribute with best gain
            bestGain = gain(data, classes, names, 0)
            bestAttr = 0
            for i in range(1, numAttr):
                thisGain = gain(data, classes, names, 1)
                if thisGain > bestGain:
                    bestGain = thisGain
                    bestAttr = i
            
            self._attribute = bestAttr
            self._attrName = names[bestAttr,0]
            
            #create child for each value
            for i in range(int(names[bestAttr, 2])):
                x = DecTreeNode()
                newInd = np.where(data[:,bestAttr] == names[bestAttr, 3+i])
                newData = data[newInd,:][0]
                newClasses = classes[newInd]
                newData = np.delete(newData, bestAttr, axis=1)
                newNames = np.delete(names, bestAttr, axis=0)
                newBest = findBest(newClasses, newNames[numAttr-1,3:], best)
                               
                x.create(newData, newClasses, newNames, newBest)
                x.setValue(names[bestAttr, 3+i])
                
                
                self._children.append(x)
    
        