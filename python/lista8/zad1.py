# Katarzy Trzos
# Lista 8
# Zadanie 1
# synchronicznie i synchronicznie

import requests
import private
import asyncio
import aiohttp


# --------- using requests ------------

def get_data_sync(base_url, params):

    response = requests.get(base_url, params=params)
    data = response.json()

    if response.status_code == 200:
        print(data)
    else:
        print(f"Error: {data.get('message', 'Unknown error')}")


base_url_nasa = f"https://api.nasa.gov/planetary/apod"
api_key_nasa = private.API_key_nasa()
params_nasa = {
    'date': '2022-11-12',
    'api_key': api_key_nasa,
}
get_data_sync(base_url_nasa, params_nasa)


base_url_weather = "https://api.openweathermap.org/data/2.5/weather"
api_key_weather = private.API_key_weather()
params_weather = {
    'q': 'London',
    'appid': api_key_weather,
}
get_data_sync(base_url_weather, params_weather)


# ----------- using asyncio/aiohttp -----------

async def get_data_async(base_url, params):
    async with aiohttp.ClientSession() as session:
        async with session.get(base_url, params=params) as response:
            data = await response.json()

            if response.status == 200:
                print(data)
            else:
                print(f"Error: {data.get('message', 'Unknown error')}")


async def main():
    base_url_nasa = "https://api.nasa.gov/planetary/apod"
    api_key_nasa = private.API_key_nasa()
    params_nasa = {
        'date': '2022-11-12',
        'api_key': api_key_nasa}

    base_url_weather = "https://api.openweathermap.org/data/2.5/weather"
    api_key_weather = private.API_key_weather()
    params_weather = {
        'q': 'London',
        'appid': api_key_weather}

    tasks = [
        get_data_async(base_url_nasa, params_nasa),
        get_data_async(base_url_weather, params_weather)
    ]

    await asyncio.gather(*tasks)

# Starting asyncio loop and main function
asyncio.run(main())
