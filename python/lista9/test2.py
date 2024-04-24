
import requests
import json
import private
import matplotlib.pyplot as plt

api_key_weather = private.API_key_weather()
url = "http://api.openweathermap.org/data/2.5/forecast"
params = {'q': 'Wrocław', 'mode': 'json', 'units': 'metric', 'appid': api_key_weather}


res = requests.get(url, params=params)
with open("prognoza.json", 'w') as fh:
    dane = res.json()
    fh.write(json.dumps(dane))

time = []
temp = []
cisn = []
wiatr = []
for progn in dane['list']:
    time.append(progn['dt_txt'])
    temp.append(progn['main']['temp'])
    cisn.append(progn['main']['pressure'])
    wiatr.append(progn['wind']['speed'])
time = [ cz[5:16] for cz in time ]

plt.plot(time, temp, color='blue')
plt.legend(['temperatura'])
plt.twinx()
plt.plot(time, cisn, color='red')
plt.legend(['ciśnienie'])

#plt.bar(time, wiatr, color='green')

plt.show()
