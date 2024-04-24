import requests
import readline
import matplotlib.pyplot as plt

with open('./dane.txt', 'r') as file:
    lines = file.readlines()

ys_21 = []
ys_22 = []

for line in lines[1:]:
    data = line.strip().split('\t')

    if data[0] == '2021':
        ys_21.append(float(data[2].replace(',', '.')) - 100)
  
    else:
        ys_22.append(float(data[2].replace(',', '.')) - 100)



xs = ['01', '02', '03', '04', '05',
            '06', '07', '08', '09', '10', '11', '12']

plt.plot(xs, ys_22, label='2323')
plt.plot(xs, ys_21)
plt.show()
