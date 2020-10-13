import pandas as pd
from sklearn.neighbors import KNeighborsClassifier
import serial

data=[]
datas=[]
count=0
port='/dev/ttyACM2'
boudrate=9600
timeout=1
##Dataset sepration
    
dataset=pd.read_csv('air_quality_dataset.csv')
dataset.set_index("MQ2",drop=False)
x=dataset.loc[0:999,'MQ2':'MQ135']
y=dataset.loc[0:999,"Quality"]
#print("Features: ")
#print(x)
#print('Labels:- ')
#print(y)

print('features:-')
#print(x.values)
#print("Labels:-\n ")
#print(y.values)
#---------------------------------------------------#


def extractData():
    ser=serial.Serial(port,boudrate,timeout=timeout);
    data=ser.readline().decode()
    d=[]
    datas=[]
    for x in data.split(','):
        print(x)
        d.append(x)
    datas.append(d[:len(d)-1])
    print(datas)S
#Machine Learning

knn=KNeighborsClassifier(n_neighbors=3)
knn.fit(x,y)
#print(knn.predict([[9,175,213,73]]))


while True:
    extractData()
    
#-------------------Testing--------------------------#
