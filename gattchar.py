# [00:60:37:0A:AF:77] Connected
# [00:60:37:0A:AF:77] Resolved services
# [00:60:37:0A:AF:77]  Service [bfe433cf-6b5e-4368-abab-b0a59666a402]
# [00:60:37:0A:AF:77]    Characteristic [bfe433cf-6b5f-4368-abab-b0a59666a402] --Seems to be all Zeros in binary
# [00:60:37:0A:AF:77]  Service [aa386520-826c-c0cd-accf-40096d5876de]
# [00:60:37:0A:AF:77]    Characteristic [aa386521-826c-c0cd-accf-40096d5876de]
# [00:60:37:0A:AF:77]    Characteristic [aa386523-826c-c0cd-accf-40096d5876de]
# [00:60:37:0A:AF:77]    Characteristic [aa386524-826c-c0cd-accf-40096d5876de]
# [00:60:37:0A:AF:77]    Characteristic [aa386522-826c-c0cd-accf-40096d5876de]
# [00:60:37:0A:AF:77]  Service [00001801-0000-1000-8000-00805f9b34fb]
# [00:60:37:0A:AF:77]    Characteristic [00002a05-0000-1000-8000-00805f9b34fb]
# [00:60:37:0A:AF:77]  Service [01ff5550-ba5e-f4ee-5ca1-eb1e5e4b1ce0]
# [00:60:37:0A:AF:77]    Characteristic [01ff5551-ba5e-f4ee-5ca1-eb1e5e4b1ce0]
#-------------------------------------------------------------------------------------------------------------------
# [00:60:37:0A:AF:77]  Service [159499cd-113c-480e-9a7f-2eb10f0222b0]
# [00:60:37:0A:AF:77]    Characteristic [159499cd-113c-480e-9a7f-2eb10f0222b9] --magy
# [00:60:37:0A:AF:77]    Characteristic [159499cd-113c-480e-9a7f-2eb10f0222ba] --magz
# [00:60:37:0A:AF:77]    Characteristic [159499cd-113c-480e-9a7f-2eb10f0222b3] --gyroy
# [00:60:37:0A:AF:77]    Characteristic [159499cd-113c-480e-9a7f-2eb10f0222b4] --gyroz
# [00:60:37:0A:AF:77]    Characteristic [159499cd-113c-480e-9a7f-2eb10f0222b8] --magx
# [00:60:37:0A:AF:77]    Characteristic [159499cd-113c-480e-9a7f-2eb10f0222b5] --accelx
# [00:60:37:0A:AF:77]    Characteristic [159499cd-113c-480e-9a7f-2eb10f0222b6] --accely
# [00:60:37:0A:AF:77]    Characteristic [159499cd-113c-480e-9a7f-2eb10f0222b7] --accelz
# [00:60:37:0A:AF:77]    Characteristic [159499cd-113c-480e-9a7f-2eb10f0222b1] --RGBChar
# [00:60:37:0A:AF:77]    Characteristic [159499cd-113c-480e-9a7f-2eb10f0222b2] --gyrox
# [00:60:37:0A:AF:77]  Service [1305b3ca-096e-4366-9f68-1ae8df01f278]
# [00:60:37:0A:AF:77]    Characteristic [1305b3ca-096e-4366-9f68-1ae8df01f279] --tempChar
# [00:60:37:0A:AF:77]    Characteristic [1305b3ca-096e-4366-9f68-1ae8df01f27c] --PressureChar
# [00:60:37:0A:AF:77]    Characteristic [1305b3ca-096e-4366-9f68-1ae8df01f27d] --AirQualityChar
# [00:60:37:0A:AF:77]    Characteristic [1305b3ca-096e-4366-9f68-1ae8df01f27a] --HumidityChar
# [00:60:37:0A:AF:77]    Characteristic [1305b3ca-096e-4366-9f68-1ae8df01f27e] --TapCountChar
# [00:60:37:0A:AF:77]    Characteristic [1305b3ca-096e-4366-9f68-1ae8df01f27b] --LightChar

import gatt
import struct
import time
import sys

characteristic_lable = {
        'non_motion_service':'1305b3ca-096e-4366-9f68-1ae8df01f278',
        'motion_service':'159499cd-113c-480e-9a7f-2eb10f0222b0',
        'tempChar':'1305b3ca-096e-4366-9f68-1ae8df01f279',
        'HumidityChar':'1305b3ca-096e-4366-9f68-1ae8df01f27a',
        'LightChar':'1305b3ca-096e-4366-9f68-1ae8df01f27b',
        'PressureChar':'1305b3ca-096e-4366-9f68-1ae8df01f27c',
        'AirQualityChar':'1305b3ca-096e-4366-9f68-1ae8df01f27d',
        'TapCountChar':'1305b3ca-096e-4366-9f68-1ae8df01f27e',
        'RGBChar':'159499cd-113c-480e-9a7f-2eb10f0222b1',
        'gyroX':'159499cd-113c-480e-9a7f-2eb10f0222b2',
        'gyroY':'159499cd-113c-480e-9a7f-2eb10f0222b3',
        'gyroZ':'159499cd-113c-480e-9a7f-2eb10f0222b4',
        'accelX':'159499cd-113c-480e-9a7f-2eb10f0222b5',
        'accelY':'159499cd-113c-480e-9a7f-2eb10f0222b6',
        'accelZ':'159499cd-113c-480e-9a7f-2eb10f0222b7',
        'magX':'159499cd-113c-480e-9a7f-2eb10f0222b8',
        'magY':'159499cd-113c-480e-9a7f-2eb10f0222b9',
        'magZ':'159499cd-113c-480e-9a7f-2eb10f0222ba'

    }

uuid_lable = {
    '1305b3ca-096e-4366-9f68-1ae8df01f278':'non_motion_service',
    '159499cd-113c-480e-9a7f-2eb10f0222b0':'motion_service',
    '1305b3ca-096e-4366-9f68-1ae8df01f279':'tempChar',
    '1305b3ca-096e-4366-9f68-1ae8df01f27a':'HumidityChar',
    '1305b3ca-096e-4366-9f68-1ae8df01f27b':'LightChar',
    '1305b3ca-096e-4366-9f68-1ae8df01f27c':'PressureChar',
    '1305b3ca-096e-4366-9f68-1ae8df01f27d':'AirQualityChar',
    '1305b3ca-096e-4366-9f68-1ae8df01f27e':'TapCountChar',
    '159499cd-113c-480e-9a7f-2eb10f0222b1':'RGBChar',    
    '159499cd-113c-480e-9a7f-2eb10f0222b2':'gyroX',
    '159499cd-113c-480e-9a7f-2eb10f0222b3':'gyroY',   
    '159499cd-113c-480e-9a7f-2eb10f0222b4':'gyroZ',
    '159499cd-113c-480e-9a7f-2eb10f0222b5':'accelX',
    '159499cd-113c-480e-9a7f-2eb10f0222b6':'accelY',
    '159499cd-113c-480e-9a7f-2eb10f0222b7':'accelZ',
    '159499cd-113c-480e-9a7f-2eb10f0222b8':'magX',
    '159499cd-113c-480e-9a7f-2eb10f0222b9':'magY',
    '159499cd-113c-480e-9a7f-2eb10f0222ba':'magZ'
}

manager = gatt.DeviceManager(adapter_name='hci0')

class AnyDevice(gatt.Device):
    def services_resolved(self):
        super().services_resolved()

        non_movement_service = next(
            s for s in self.services
            if s.uuid == characteristic_lable['non_motion_service'])
        time.sleep(0.5)
        temperature_characteristic = next(
            c for c in non_movement_service.characteristics
            if c.uuid == characteristic_lable['tempChar'])
        time.sleep(0.5)
        humidity_characteristic = next(
            c for c in non_movement_service.characteristics
            if c.uuid == characteristic_lable['HumidityChar'])      
        time.sleep(0.5)        
        light_characteristic = next(
            c for c in non_movement_service.characteristics
            if c.uuid == characteristic_lable['LightChar'])
        time.sleep(0.5)
        pressure_characteristic = next(
            c for c in non_movement_service.characteristics
            if c.uuid == characteristic_lable['PressureChar'])    
        time.sleep(0.5)
        air_quality_characteristic = next(
            c for c in non_movement_service.characteristics
            if c.uuid == characteristic_lable['AirQualityChar']) 
        time.sleep(0.5)
        tap_counter_characteristic = next(
            c for c in non_movement_service.characteristics
            if c.uuid == characteristic_lable['TapCountChar'])

        movement_service = next(
            s for s in self.services
            if s.uuid == characteristic_lable['motion_service'])
        time.sleep(0.5)
        RGB_characteristic = next(
            c for c in movement_service.characteristics
            if c.uuid == characteristic_lable['RGBChar'])
        time.sleep(0.5)
        gyroX_characteristic = next(
            c for c in movement_service.characteristics
            if c.uuid == characteristic_lable['gyroX'])      
        time.sleep(0.5)        
        gyroY_characteristic = next(
            c for c in movement_service.characteristics
            if c.uuid == characteristic_lable['gyroY'])
        time.sleep(0.5)
        gyroZ_characteristic = next(
            c for c in movement_service.characteristics
            if c.uuid == characteristic_lable['gyroZ'])    
        time.sleep(0.5)
        accelX_characteristic = next(
            c for c in movement_service.characteristics
            if c.uuid == characteristic_lable['accelX'])      
        time.sleep(0.5)        
        accelY_characteristic = next(
            c for c in movement_service.characteristics
            if c.uuid == characteristic_lable['accelY'])
        time.sleep(0.5)
        accelZ_characteristic = next(
            c for c in movement_service.characteristics
            if c.uuid == characteristic_lable['accelZ'])    
        time.sleep(0.5)
        magX_characteristic = next(
            c for c in movement_service.characteristics
            if c.uuid == characteristic_lable['magX'])      
        time.sleep(0.5)        
        magY_characteristic = next(
            c for c in movement_service.characteristics
            if c.uuid == characteristic_lable['magY'])
        time.sleep(0.5)
        magZ_characteristic = next(
            c for c in movement_service.characteristics
            if c.uuid == characteristic_lable['magZ'])    
        time.sleep(0.5)

        temperature_characteristic.read_value()
        humidity_characteristic.read_value()
        light_characteristic.read_value()
        pressure_characteristic.read_value()
        air_quality_characteristic.read_value()
        tap_counter_characteristic.read_value()
        RGB_characteristic.read_value()
        gyroX_characteristic.read_value()
        gyroY_characteristic.read_value()
        gyroZ_characteristic.read_value()
        accelX_characteristic.read_value()
        accelY_characteristic.read_value()
        accelZ_characteristic.read_value()
        magX_characteristic.read_value()
        magY_characteristic.read_value()
        magZ_characteristic.read_value()

    def characteristic_value_updated(self, characteristic, value):
        uint_list = ['LightChar', 'PressureChar', 'AirQualityChar', 'TapCountChar', 'RGBChar']
        if (uuid_lable[characteristic.uuid] in uint_list):
            print(uuid_lable[characteristic.uuid])
            print(struct.unpack('I', value)) 
        else:
            print(uuid_lable[characteristic.uuid])
            print(struct.unpack('f', value))


device = AnyDevice(mac_address='00:60:37:0A:AF:77', manager=manager)
device.connect()

manager.run()