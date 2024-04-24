# Katarzy Trzos
# Lista 9
# Zadanie 1
import matplotlib.pyplot as plt
import requests

def end(year, month):
    if (month == '02'):
        return f'{year}-{month}-28'
    if month in ['01', '03', '05', '07', '08', '10', '12']:
        return f'{year}-{month}-31'
    else:
        return f'{year}-{month}-30'


def get_data_nbp(year, ax1, ax2, ax3):
    table = 'A'
    code1 = 'EUR'
    code2 = 'USD'
    code3 = 'CHF'
    months = ['01', '02', '03', '04', '05',
              '06', '07', '08', '09', '10', '11', '12']

    ys_eur = []
    ys_usd = []
    ys_chf = []

    for month in months:
        startDate = f'{year}-{month}-01'

        endDate = end(year, month)
        url1 = f"http://api.nbp.pl/api/exchangerates/rates/{table}/{code1}/{startDate}/{endDate}/"
        url2 = f"http://api.nbp.pl/api/exchangerates/rates/{table}/{code2}/{startDate}/{endDate}/"
        url3 = f"http://api.nbp.pl/api/exchangerates/rates/{table}/{code3}/{startDate}/{endDate}/"

        res_eur = requests.get(url1)
        res_usd = requests.get(url2)
        res_chf = requests.get(url3)

        dane_eur = res_eur.json()
        dane_usd = res_usd.json()
        dane_chf = res_chf.json()
        mid_eur = [entry['mid'] for entry in dane_eur['rates']]
        mid_usd = [entry['mid'] for entry in dane_usd['rates']]
        mid_chf = [entry['mid'] for entry in dane_chf['rates']]

        avg_mid_eur = sum(mid_eur) / len(mid_eur)
        avg_mid_usd = sum(mid_usd) / len(mid_usd)
        avg_mid_chf = sum(mid_chf) / len(mid_chf)
        ys_eur.append(avg_mid_eur)
        ys_usd.append(avg_mid_usd)
        ys_chf.append(avg_mid_chf)


    ax1.plot(months, ys_eur, label=f"{year}")
    ax2.plot(months, ys_usd, label=f"{year}")
    ax3.plot(months, ys_chf, label=f"{year}")

    ax1.set_ylabel("EURO")
    ax1.legend()

    ax2.set_ylabel("DOLAR")
    ax2.legend()

    ax3.set_xlabel("miesiace")
    ax3.set_ylabel("FRANK SZWAJCARSKI")
    ax3.legend()


def inflation(ax):
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

    months = ['01', '02', '03', '04', '05',
              '06', '07', '08', '09', '10', '11', '12']

    ax.plot(months, ys_21, marker='o', label='2021')
    ax.plot(months, ys_22, marker='o', label='2022')

    plt.title("Porownanie wskaznikow inflacji w 2021 i 2022 roku.")
    ax.set_xlabel("Miesiace")
    ax.set_ylabel("Wskaznik inflacji w poszczegolnych miesiacach")
    ax.legend()


fig1, (ax1, ax2, ax3) = plt.subplots(3, 1)

get_data_nbp(2021, ax1, ax2, ax3)
get_data_nbp(2022, ax1, ax2, ax3)


# dane o wskazniku cen towarowi uslug pobralam recznie z adres:
# https://stat.gov.pl/download/gfx/portalinformacyjny/pl/defaultstronaopisowa/4741/1/1/miesieczne_wskazniki_cen_towarow_i_uslug_konsumpcyjnych_od_1982_roku_15-11-2023.csv
# i potrzebne dane zapisalam w pliku dane.txt
fig2, ax = plt.subplots(1, 1)
inflation(ax)
plt.show()
