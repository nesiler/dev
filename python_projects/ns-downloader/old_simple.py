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

base = 'http://'
end = '.jpg'

temp = []
url = []
name = []
folder = []

with open('list.txt') as f:
    names = f.readlines()

    for i in range(0, len(names)):

        # definitions
        print("Download list getting ready...")
        url.append(names[i])
        name.append(names[i].strip('\n').split('-')[0])
        folder.append(str(names[i].strip('\n').strip('-')))


print(str(len(folder)) + " Libraries will be downloaded...")

for j in range(0, len(names)):

    if(not(os.path.exists(folder[j]))):
        print("=== Directory created successfully: " + folder[j] + " ===")
        os.mkdir(folder[j])

    for i in range(1, 50):
        address = base + folder[j] + '/' + str(i) + end

        if(validate_address(address)):
            print("=== Address Validated ===\n" + address)
            filename = wget.download(address, folder[j])
            print("+++ Downloaded: " + filename + "+++")
        else:
            break
