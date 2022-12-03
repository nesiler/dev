from bs4 import BeautifulSoup
import re
import codecs

f = open("index.html", 'r')

cleantext = BeautifulSoup(f, "lxml").text

text = ""


def func(value):
    return ''.join(value.split())


textt = func(cleantext)


for line in textt:
    text += line.strip().replace(':', '')

print(text)
