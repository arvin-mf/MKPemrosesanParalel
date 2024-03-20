import threading
import requests

class WeatherRequests(threading.Thread):

    def __init__(self, city, wb, ws, i, **kwargs):
        self._city = city
        self._workbook = wb
        self._sheet = ws
        self._count = i
        super(WeatherRequests, self).__init__(**kwargs)
        self.start()

    def _send_weather_request(self):
        key = '[api_key]'
        city = self._city
        api = 'http://api.weatherapi.com/v1/current.json'
        payload = {
            "key": key,
            "q": city,
            "aqi": 'no'
        }
        response = requests.get(api, params=payload, timeout=1000)
        # print(response.json())
        data = response.json()['current']
        self._sheet.cell(column=5, row=4+self._count, value=data['temp_c'])
        self._sheet.cell(column=6, row=4+self._count, value=data['humidity'])
        self._sheet.cell(column=7, row=4+self._count, value=data['condition']['text'])
        self._sheet.cell(column=8, row=4+self._count, value=data['wind_mph'])
        self._sheet.cell(column=9, row=4+self._count, value=data['wind_dir'])
        self._sheet.cell(column=10, row=4+self._count, value=data['uv'])

        self._workbook.save('C:/Users/Public/Avrin/Provinsi/Gorontalo.xlsx')
                

    def run(self):
        self._send_weather_request()