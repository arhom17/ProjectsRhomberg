library(e1071)
library(gmodels)
library(class)

mydataRaw <- read.csv("NFLDataSet.csv")
mydata <- mydataRaw[sample(nrow(mydataRaw)),]
str(mydata)

train <- mydata[1:427,]
test <- mydata[428:532,]

trainingdata <- train[, 1:16]
trainingclass <- train[, 17]

testingdata <- test[, 1:16]
testingclass <- test[, 17]

mynb <- naiveBayes(trainingdata, trainingclass, laplace = 1)
mynbpredict <- predict(mynb, testingdata)

table <- CrossTable(mynbpredict, testingclass)

table$t

accuracy <- sum(diag(table$t)) / sum(table$t)
accuracy
