
import glob
import os
import queue
import threading
from audioop import add
from concurrent.futures import thread
from fileinput import filename
from ntpath import join
from posixpath import split
from quopri import encodestring

import requests
import wget
import subprocess


def validate_address(address):
    website_is_up = False
    # print("*** url address validating... ***")
    request_response = requests.head(address)
    status_code = request_response.status_code
    website_is_up = status_code == 200
    return website_is_up


def remember(folder):

    list_of_files = glob.glob(folder + '/*.jpg')
    if(len(list_of_files) == 0):
        return int(1)
    else:
        latest_file = max(list_of_files, key=os.path.getctime)
        res = latest_file.split('/')[-1].split('.')[0]
        print(("Last downloaded file: " + res + " ").center(40, '_'))
        return int(res)


def convert_to_cc(num):
    fc = str(int(num/10))
    sc = str(num % 10)
    return str(fc + sc)


def download(address, folder):
    subprocess.run(["wget", "-r", "-nc", "-P", folder, address])


def nsd(j):


    base = ''
    photos = 'photos/'
    end = '.jpg'

    file = 1
    err = 0

    if(not(os.path.exists(str(dir[j])))):
        print(("Directory created: " + str(dir[j])).center(40, '+'))
        os.mkdir(str(dir[j]))

    # file = remember(dir[j])

    address = base + folder[j] + str(file) + end
    # address = base + folder[j] + convert_to_cc(file) + end

    while True:

        if(validate_address(address)):
            print(("Downloaded: " + str(address) + " ").center(40, 'o'))
            download(address, str(dir[j]))
            # filename = wget.download(address, dir[j])
            # print(("Downloaded: " + str(filename) + " ").center(40, 'o'))
            file = file + 1

            address = base + folder[j] + str(file) + end
            # address = base + folder[j] + convert_to_cc(file) + end

        elif(err < 10):
            file = file + 1

            print(("Can not Downloaded: " + str(address) + " ").center(40, '^'))
            address = base + folder[j] + str(file) + end
            # address = base + folder[j] + convert_to_cc(file) + end
            print(("Error counter: " + str(err) + " ").center(40, '!'))
            err = err + 1
        else:
            break


names = []

with open('dup.txt') as f:
    names = f.readlines()

url = []
folder = []
dir = []

for i in range(0, len(names)):
    # definitions
    # print(("Download list getting ready").center(40, '.'))
    url.append(names[i])
    folder.append(str(names[i].strip('\n')))
    dir.append(str(folder[i].split('/')[1]))

class myThread (threading.Thread):
    def __init__(self, threadID, name, counter):
        threading.Thread.__init__(self)
        self.threadID = threadID
        self.name = name
        self.counter = counter

    def run(self):
        nsd(self.threadID-1)


threadList = []
t_name = 'Thread-'

for i in range(1, len(names)+1):
    threadList.append(t_name + str(i))

queueLock = threading.Lock()
workQueue = queue.Queue(len(names))
threads = []
threadID = 1

# Create new threads
for tName in threadList:
    thread = myThread(threadID, tName, workQueue)
    thread.start()
    threads.append(thread)
    threadID += 1
