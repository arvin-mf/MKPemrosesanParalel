import threading
import requests

class SubdistrictRequests(threading.Thread):

    def __init__(self, code, wb, ws, list, **kwargs):
        self._city = code
        self._workbook = wb
        self._sheet = ws
        self._names = list
        super(SubdistrictRequests, self).__init__(**kwargs)
        self.start()

    def _send_subdistrict_request(self):
        kota = self._city
        key = '[api_key]'
        api = 'https://api.goapi.io/regional/kecamatan'
        payload = {
            "kota_id": kota,
            "api_key": key
        }
        
        response = requests.get(api, params=payload, timeout=1000)
        for r in response.json()['data']:
            self._names.append(r['name'])
                

    def run(self):
        self._send_subdistrict_request()