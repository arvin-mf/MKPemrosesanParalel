import time
import requests
from  WeatherReq.weather_req import WeatherRequests

cities = []

def get_subdistricts(id):
    kota = id
    key = '{key masing-masing ges}'
    api = 'https://api.goapi.io/regional/kecamatan'
    payload = {
        "kota_id": kota,
        "api_key": key
    }
    response = requests.get(api, params=payload, timeout=1000)
    # print(response.json())
    for r in response.json()['data']:
        cities.append(r['name'])


def main():
    get_subdistricts('35.07')   # 35.07: id kab. Malang
    start_time = time.time()

    current_requests = []
    for c in cities:
        weather_req = WeatherRequests(city=c)
        current_requests.append(weather_req)

    for r in current_requests:
        r.join()

    print("Getting weathers information took: {}".format(time.time() - start_time))


if __name__ == "__main__":
    main()
