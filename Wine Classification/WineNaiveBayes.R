library(e1071)
library(gmodels)
library(class)

mydataRaw <- read.csv("WineClassification.csv")
mydata <- mydataRaw[sample(nrow(mydataRaw)),]
str(mydata)

train <- mydata[1:1299,]
test <- mydata[1300:6497,]

trainingdata <- train[, 1:7]
trainingclass <- train[, 8]

testingdata <- test[, 1:7]
testingclass <- test[, 8]

mynb <- naiveBayes(trainingdata, trainingclass, laplace = 1)
mynbpredict <- predict(mynb, testingdata)

table <- CrossTable(mynbpredict, testingclass)

table$t

accuracy <- sum(diag(table$t)) / sum(table$t)
accuracy
