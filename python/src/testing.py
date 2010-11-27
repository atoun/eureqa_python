'''
Created on Oct 29, 2010

@author: marcin
'''
import unittest
import eureqa_python


class Test(unittest.TestCase):

    def setUp(self):
        self.server_info = eureqa_python.ServerInfo()
        self.search_progress = eureqa_python.SearchProgress()

    def testServerInfo(self):
        self.server_info.is_valid()
        self.server_info.summary()
        
        self.server_info.hostname = 'blah'
        self.assertEqual(self.server_info.hostname, 'blah')
        
        self.server_info.operating_system = 'blah1'
        self.assertEqual(self.server_info.operating_system, 'blah1')
        
        self.server_info.eureqa_version = 1
        self.assertEqual(self.server_info.eureqa_version, 1)
        
        self.server_info.cpu_cores = 2
        self.assertEqual(self.server_info.cpu_cores, 2)
        
    def testSearchProgress(self):
        self.search_progress.is_valid()
        self.search_progress.summary()
        
        self.search_progress.generations = 1
        self.assertEqual(self.search_progress.generations, 1)
        
        self.search_progress.generations_per_sec = 2
        self.assertEqual(self.search_progress.generations_per_sec, 2)

        self.search_progress.evaluations = 3
        self.assertEqual(self.search_progress.evaluations, 3)
        
        self.search_progress.evaluations_per_sec = 4
        self.assertEqual(self.search_progress.evaluations_per_sec, 4)
        
        self.search_progress.total_population_size = 5
        self.assertEqual(self.search_progress.total_population_size, 5)
        
 

if __name__ == "__main__":
    #import sys;sys.argv = ['', 'Test.testName']
    unittest.main()