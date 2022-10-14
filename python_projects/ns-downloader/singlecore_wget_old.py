import glob
import os
from audioop import add
from ntpath import join
from posixpath import split
from quopri import encodestring

import requests
import wget
from numpy import append


def validate_address(address):
    website_is_up = False
    print("*** url address validating... ***")
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


base = ''
end = '.jpg'

url = []
name = []
folder = []
file = 1
err = 0

with open('new.txt') as f:
    names = f.readlines()

    for i in range(0, len(names)):
        # definitions
        print(("Download list getting ready").center(40, '.'))
        url.append(names[i])
        name.append(names[i].strip('\n').split('-')[0])
        folder.append(str(names[i].strip('\n').strip('-')))


print((str(len(folder)) + " Libraries will be downloaded").center(40, '*'))

for j in range(0, len(names)):

    if(not(os.path.exists(folder[j]))):
        print(("Directory created: " + str(folder[j])).center(40, '+'))
        os.mkdir(folder[j])

    file = remember(folder[j])

    address = base + folder[j] + '/' + str(file) + end

    while True:

        if(validate_address(address)):
            filename = wget.download(address, folder[j])
            print(("Downloaded: " + str(filename) + " ").center(40, 'o'))
            file = file + 1
            address = base + folder[j] + '/' + str(file) + end

        elif(err < 5):
            file = file + 1
            address = base + folder[j] + '/' + str(file) + end
            print(("Error counter: " + str(err) + " ").center(40, '!'))
            err = err + 1
        else:
            file = 1
            break
