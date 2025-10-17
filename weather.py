import requests
import json

def get_weather(city):
    # Kita menggunakan format JSON dari wttr.in
    url = f'https://wttr.in/{city}?format=j1'
    
    try:
        response = requests.get(url)
        # Menghasilkan error jika request gagal (cth: 404)
        response.raise_for_status() 
        
        data = response.json()
        
        # Ambil data cuaca saat ini
        current_condition = data['current_condition'][0]
        temp_c = current_condition['temp_C']
        feels_like_c = current_condition['FeelsLikeC']
        description = current_condition['weatherDesc'][0]['value']
        
        print("\n--- Cuaca Saat Ini ---")
        print(f'Kota:         {data["nearest_area"][0]["areaName"][0]["value"]}')
        print(f'Kondisi:      {description}')
        print(f'Suhu:         {temp_c}°C')
        print(f'Terasa Seperti: {feels_like_c}°C')
        
    except requests.exceptions.HTTPError as err:
        print(f"Error: Tidak bisa menemukan kota '{city}'. Coba lagi.")
    except requests.exceptions.RequestException as e:
        print(f"Error koneksi: {e}")

# --- Program Utama ---
while True:
    kota_input = input("Masukkan nama kota (atau ketik 'exit' untuk keluar): ")
    if kota_input.lower() == 'exit':
        break
    
    if kota_input:
        get_weather(kota_input)
    else:
        print("Nama kota tidak boleh kosong.")
