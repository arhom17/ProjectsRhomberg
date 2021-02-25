install.packages("class")
install.packages("gmodels")

library('class')
library('gmodels')

mydataRaw <- read.csv("NFLDataSet.csv")
mydata <- mydataRaw[sample(nrow(mydataRaw)),]
str(mydata)

train <- mydata[1:427,]
test <- mydata[428:532,]

trainingdata <- train[, 1:16]
trainingclass <- train[, 17]

testingdata <- test[, 1:16]
testingclass <- test[, 17]

myknn <- knn(trainingdata, testingdata, trainingclass, k = 1)
myknn

t <- CrossTable(myknn, testclass)

sum(diag(t$t))/sum(t$t)