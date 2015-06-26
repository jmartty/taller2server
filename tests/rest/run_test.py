import os
import threading
import unittest
import subprocess
import requests
from Test_rest import TestRestApi

if __name__ == '__main__':
	suite = unittest.TestLoader().loadTestsFromTestCase(TestRestApi)
	unittest.TextTestRunner().run(suite)
#Se cierra el server, para que se escriban los archivos del coverage
	try:
                requests.get("http://localhost:5000" + "/test")
        except:
                pass

 	
