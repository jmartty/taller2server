import subprocess

subprocess.call("g++ dataload.cpp -o dataload", shell=True)
subprocess.call("g++ dataget.cpp -o dataget", shell=True)
subprocess.call("./dataload", shell=True)
subprocess.call("./dataget", shell=True)

