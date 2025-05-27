import pyautogui
import time
import os
from pynput import keyboard
import threading

last_move_time = time.time()

def prevent_sleep():
    os.system('xset s off')
    os.system('xset -dpms')

def move_mouse():
    x, y = pyautogui.position()
    pyautogui.moveTo(x + 100, y + 100, duration=0.5)
    pyautogui.moveTo(x, y, duration=0.5)

def monitor_mouse():
    global last_move_time
    last_position = pyautogui.position()

    while True:
        current_position = pyautogui.position()
        if current_position != last_position:
            last_position = current_position
            last_move_time = time.time()

        if time.time() - last_move_time > 60:
            move_mouse()
            last_move_time = time.time()

        time.sleep(1)

def on_key_press(key):
    global last_move_time
    last_move_time = time.time()

def start_keyboard_listener():
    with keyboard.Listener(on_press=on_key_press) as listener:
        listener.join()

if __name__ == "__main__":
    prevent_sleep()

    # Klavye dinleyicisini ayrı bir thread'de başlat
    keyboard_thread = threading.Thread(target=start_keyboard_listener, daemon=True)
    keyboard_thread.start()

    # Fare izleme döngüsü
    monitor_mouse()
