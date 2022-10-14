from os import remove


def url_delimiter():
    # url delimiter

    with open('urls.txt', 'r') as f:
        names = f.readlines()

    res = []
    for url in names:
        res.append(url.split('/')[:5][-1])

    with open('res.txt', 'w') as f:
        for line in res:
            f.write(line)
            f.write('\n')


def duplicates():

    def duplicate_remover(x):
        return list(dict.fromkeys(x))

    with open('dup.txt', 'r') as f:
        rows = f.readlines()

    urls = []

    for url in rows:
        urls.append(url.strip("\n"))

    urls = duplicate_remover(urls)

    with open('dup.txt', 'w') as f:
        for line in urls:
            f.write(line)
            f.write('\n')


def delimiter():
    with open('newx.txt', 'r') as f:
        names = f.readlines()

    res = []
    for url in names:
        res.append(url.split("\"")[0])

    print(res[1])
    print(type(res[1]))

    res1 = []
    for url in res:
        res1.append(url.split(".")[0])

    print(res1[1])
    print(type(res1[1]))

    with open('set.txt', 'w') as f:
        for line in res1:
            f.write(line)
            f.write('\n')


def name_to_folder():
    with open('a.txt', 'r') as f:
        names = f.readlines()

    res = []
    for url in names:
        res.append(url.split("\n")[0].replace(" ", "-").lower())

    with open('set.txt', 'w') as f:
        for line in res:
            f.write(line)
            f.write('\n')


def remover():

    with open('dup.txt', 'r') as f:
        rows = f.readlines()

    urls = []

    for url in rows:
        urls.append(url.strip("\n").replace("th/", ""))

    with open('dup.txt', 'w') as f:
        for line in urls:
            f.write(line)
            f.write('\n')


