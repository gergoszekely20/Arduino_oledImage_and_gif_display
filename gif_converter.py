import serial
import time
from PIL import Image, ImageSequence

gif_path = "D:\\Egyetem\\PMP\\PROJECT\\GIF\\horse.gif"

def process_frame(frame):
    resized_frame = frame.resize((128, 64))
    return resized_frame.convert("1")

ser = serial.Serial('COM12', 9600)
time.sleep(2)

ser.write(b'\xAA')  # Send a unique byte indicating the start of communication

gif = Image.open(gif_path)

for frame in ImageSequence.Iterator(gif):
    processed_frame = process_frame(frame)
    frame_bytes = bytearray(processed_frame.tobytes())
    
    # Send a unique byte indicating the start of a new frame
    ser.write(b'\xBB')
    ser.write(frame_bytes)
    time.sleep(1)

ser.close()
