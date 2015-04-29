import os
import threading
import unittest
import subprocess
from Test_rest import TestRestApi

if __name__ == '__main__':
	suite = unittest.TestLoader().loadTestsFromTestCase(TestRestApi)
	unittest.TextTestRunner().run(suite)
