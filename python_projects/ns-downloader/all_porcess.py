from multiprocessing import Process
import multiprocessing
from time import sleep
import requests
import threading
import queue
import os
import glob


def convert_to_cc(num: int):
    """Convert a number to a 2 digit string"""
    fc = str(int(num/10))
    sc = str(num % 10)
    return str(fc + sc)


def convert_to_cccc(num: int):
    """Convert a number to a 4 digit string"""
    res = ''
    r = 0

    for i in range(0, 4):
        r = num % 10
        res = str(r) + res
        num = num // 10
    return res


def download(address, folder, file):
    website_is_up = False
    request_response = requests.head(address)
    status_code = request_response.status_code
    website_is_up = status_code == 200

    if(website_is_up):
        response = requests.get(address)
        file = open(str(folder + '/' + file + '.jpg'), "wb")
        file.write(response.content)
        file.close()
        return True
    else:
        return False


def create_address(url, page, file):

    base = 'https://'
    end = '.jpg'
    address = base + url + '/' + \
        convert_to_cccc(page) + '/' + convert_to_cc(file) + end
    return str(address)


def make_directory(dir: str):
    if(not(os.path.exists(dir))):
        print((" Directory created: " + dir + ' ').center(80, '+'))
        os.mkdir(dir)


def remember_page(folder):

    list_of_pages = glob.glob(folder + '/*')
    if(len(list_of_pages) == 0):
        return str("0001")
    else:
        latest_file = max(list_of_pages, key=os.path.getctime)
        print((" Last page: " + latest_file + " ").center(80, 'o'))
        return str(latest_file)


def remember_file(folder):

    list_of_files = glob.glob(folder + '/*.jpg')
    if(len(list_of_files) == 0):
        return int(0)
    else:
        latest_file = max(list_of_files, key=os.path.getctime)
        res = latest_file.split('/')[-1].split('.')[0]
        print((" Last file: " + res + " ").center(80, 'x'))
        return int(res)


def nsd(j):
    sleep(3)
    err_file = 0
    err_url = 0

    make_directory(str(url[j]))

    page = int(remember_page(url[j]).split('/')[-1])
    file = remember_file(remember_page(url[j]))

    address = create_address(url[j], page, file)
    sleep(3)
    while True:
        make_directory(str(url[j] + '/' + convert_to_cccc(page)))
        print((" Download started: " +
              url[j] + str(page) + ' ').center(80, '*'))

        if(download(address, str(url[j] + '/' + convert_to_cccc(page)), convert_to_cc(file))):
            err_file = 0
            err_url = 0
            print((" Downloaded: " + str(address) + ' ').center(80, '|'))
            file = file + 1
            address = create_address(url[j], page, file)

        elif(err_file < 5):
            file = file + 1
            err_file = err_file + 1
            address = create_address(url[j], page, file)

        elif(err_file >= 5 and err_url < 50):
            err_file = 0
            file = 0
            err_url = err_url + 1
            page = page + 1
            address = create_address(url[j], page, file)
        else:
            print("Error occurred: "+create_address(url[j], page, file))
            break

    print("".center(80, '$'))
    print("".center(80, '$'))
    print(str(' ' + proc.name + "terminated ").center(80, '-'))
    print("".center(80, '$'))
    print("".center(80, '$'))


if __name__ == "__main__":  # confirms that the code is under main function

    names = []

    with open('links.txt') as f:
        names = f.readlines()

    url = []

    for i in range(0, len(names)):
        url.append(names[i].strip("\n"))

    procs = []
    # instantiating without any argument
    proc = Process(target=nsd, args=(0,))
    procs.append(proc)
    proc.start()

    # instantiating process with arguments
    for i in range(1, len(names)):
        proc = Process(target=nsd, args=(i,))
        print("".center(80, '$'))
        print(str(' ' + proc.name + "started ").center(80, '-'))
        print("".center(80, '$'))
        procs.append(proc)
        proc.start()

    # complete the processes
    for proc in procs:
        proc.join()
