'''
Created on Oct 29, 2010

@author: marcin
'''
import unittest
import eureqa_python


class Test(unittest.TestCase):

    def setUp(self):
        self.dummy = eureqa_python.DummyClass()

    def testDummyClass(self):
        self.assertTrue(self.dummy != "")


if __name__ == "__main__":
    #import sys;sys.argv = ['', 'Test.testName']
    unittest.main()