#Loading the Dataset
from sklearn.datasets import load_iris
 
data_loaded = load_iris()
X = data_loaded.data
y = data_loaded.target
print("Features: ", data_loaded.feature_names)
print("Labels: ", data_loaded.target_names)

#Splitting the dataset into training and testing variables
from sklearn.model_selection import train_test_split
 
X_train, X_test, y_train, y_test = train_test_split(X,y,test_size=0.30,shuffle=False)
 
#size stores the training percentage e.g.70-30 split is size=0.20

from sklearn.naive_bayes import GaussianNB
 
#Calling the Class
naive_bayes = GaussianNB()
 
#Fitting the data to the classifier
naive_bayes.fit(X_train , y_train)
 
#Predict on test data
y_predicted = naive_bayes.predict(X_test)

#Import metrics class from sklearn
from sklearn import metrics
 
metrics.accuracy_score(y_predicted , y_test)
