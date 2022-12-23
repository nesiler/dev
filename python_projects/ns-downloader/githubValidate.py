import requests
names = []
res = []
with open('names.txt', 'r') as f:
    rows = f.readlines()
for row in rows:
    names.append(row.strip("\n"))


def validate_address(address):
    website_is_up = False
    request_response = requests.head(address)
    status_code = request_response.status_code
    website_is_up = status_code == 200
    return website_is_up


head = "https://github.com/"

for name in names:
    address = head + name
    if validate_address(address):
        print("Taken:", name)
    else:
        print("*** Name available: ", name)
        res.append(name)


with open('res.txt', 'w') as f:
    for line in res:
        f.write(line)
        f.write('\n')
