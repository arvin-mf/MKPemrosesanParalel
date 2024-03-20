import threading
import requests

class WeatherRequests(threading.Thread):

    def __init__(self, city, **kwargs):
        self._city = city
        super(WeatherRequests, self).__init__(**kwargs)
        self.start()

    def _send_weather_request(self):
        key = '{key masing-masing ges}'
        city = self._city
        api = 'http://api.weatherapi.com/v1/current.json'
        payload = {
            "key": key,
            "q": city,
            "aqi": 'no'
        }
        response = requests.get(api, params=payload, timeout=1000)
        print(response.json())

    def run(self):
        self._send_weather_request()

