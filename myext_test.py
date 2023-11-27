import myext

def main(x):
    for i in range(10000):
        myext.inc(x)

main(2)
print(myext.__name__)
print(myext.inc.__name__)
