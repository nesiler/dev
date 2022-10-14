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


def validate_address(address):
    website_is_up = False
    request_response = requests.head(address)
    status_code = request_response.status_code
    website_is_up = status_code == 200
    return website_is_up


def generate_address(names):

    name = []
    address_name = []
    address_list = []
    temp = ''

    print(" Addresses generating ".center(40, '.'))

    for i in range(0, len(names)):

        name.append(names[i].strip('\n').replace(' ', '-').split('-'))
        address_name.append(names[i].strip('\n').replace(' ', '-'))

        temp = name[i][0][0] + '/'
        temp += name[i][0][1] + '/'
        temp += address_name[i]
        address_list.append(temp)

    return address_list


def create_folders(names):

    folders = []
    for name in names:
        folder = str(name.strip('\n'))
        folders.append(folder)

        if(not(os.path.exists(folder))):
            os.mkdir(folder)
            print(("Directory created: " + name + " ").center(40, '+'))

    return folders


def download(address, folder, file_name):
    response = requests.get(address)
    file = open(str(folder + '/' + file_name + '.jpg'), "wb")
    file.write(response.content)
    file.close()


def get_number(number):
    res = int(number / 1000) + 1
    return (res*1000)


def remember(folder):

    list_of_files = glob.glob(folder + '/*.jpg')
    if(len(list_of_files) == 0):
        return int(1)
    else:
        latest_file = max(list_of_files, key=os.path.getctime)
        res = latest_file.split('/')[-1].split('.')[0]
        print(("Last downloaded file: " + res + " ").center(40, '_'))
        return int(res)


def nsd(num):

    base = ''
    end = '.jpg'

    folders = create_folders(names)
    addresses = generate_address(names)
    number = 1000
    temp = ''
    address = ''
    file = remember(folders[num])
    err = 0

    current_base = base + addresses[num] + '/'
    address = current_base + str(number) + '/' + '1' + end

    while True:

        if(validate_address(address)):
            print(address)
            download(address, folders[num], str(file))
            err = 0
            file = file + 1

            if((file % 1000) == 0):
                number = get_number(file)

            address = current_base + str(number) + '/' + str(file) + end

        elif(err < 50):
            file = file + 1

            if((file % 1000) == 0):
                number = get_number(file)
            print("Error : " + address)
            address = current_base + str(number) + '/' + str(file) + end
            print(("Error counter: " + str(err) + " ").center(40, '!'))
            err = err + 1
        else:
            break


names = []

with open('done.txt') as f:
    names = f.readlines()

exitFlag = 0


class myThread (threading.Thread):
    def __init__(self, threadID, name, counter):
        threading.Thread.__init__(self)
        self.threadID = threadID
        self.name = name
        self.counter = counter

    def run(self):
        nsd(int(self.threadID-1))


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
