'''
Created on Dec 19, 2010

@author: MF
'''

import unittest
import eureqa_python
import time


class Test(unittest.TestCase):

    def test_basic_client(self):
        # Initialize a data set and import data from a text file
        data = eureqa_python.DataSet()
        res = data.import_ascii_err('default_data.txt')
        
        # Initialize search options
        options = eureqa_python.SearchOptions('y = f(x)')
        
        # Start server -- not present in 'basic_client.cpp'
        eureqa_python.EureqaServerController.start_server('/home/marcin/Portable/eureqa/server/linux/eureqa_server')
        
        # Connect with 10s timeout
        connection = eureqa_python.Connection()
        connection.connect(10)
        
        # Query the server's information
        res = connection.query_server_info()
        
        # Send data set
        connection.send_data_set(data)
            
        # Send options
        connection.send_options(options)
        
        # Start searching
        connection.start_search()
        
        # Monitor the search
        best_solutions = eureqa_python.SolutionFrontier()
        
        starting_time = time.time()
        
        while time.time() - starting_time < 10:
            res = connection.query_progress()
            best_solutions.add(res[1].solution)
            
#        for i in range(best_solutions.size()):
#            print best_solutions[i].text
        
        self.assertNotEquals(best_solutions.size(), 0)
        
if __name__ == "__main__":
    #import sys;sys.argv = ['', 'Test.testName']
    unittest.main()