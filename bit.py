import serial
import time
from PIL import Image

image_path = "D:\\Egyetem\\PMP\\PROJECT\\whale.jpg"
output_bitmap_path = "D:\\Egyetem\\PMP\\PROJECT\\picture_bitmap.bmp"

image = Image.open(image_path)
resized_image = image.resize((128, 64))
bitmap = resized_image.convert("1")
bitmap.save(output_bitmap_path, "BMP")

bitmap_bytes = bytearray(bitmap.tobytes())

ser = serial.Serial('COM12', 9600)
time.sleep(2)
ser.write(bitmap_bytes)
ser.close()


