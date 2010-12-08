'''
Created on Oct 29, 2010

@author: MF
'''
import unittest
import eureqa_python

# TODO: excpetions while type conversion

class Test(unittest.TestCase):

    def testServerInfo(self):
        server_info = eureqa_python.ServerInfo()
        
        server_info.is_valid()
        server_info.summary()
        
        server_info.hostname = 'text1'
        self.assertEqual(server_info.hostname, 'text1')
        
        server_info.operating_system = 'text2'
        self.assertEqual(server_info.operating_system, 'text2')
        
        server_info.eureqa_version = 1
        self.assertEqual(server_info.eureqa_version, 1)
        
        server_info.cpu_cores = 2
        self.assertEqual(server_info.cpu_cores, 2)
        
    def testSearchProgress(self):
        search_progress = eureqa_python.SearchProgress()
        
        search_progress.is_valid()
        search_progress.summary()
        
        search_progress.generations = 1
        self.assertEqual(search_progress.generations, 1)
        
        search_progress.generations_per_sec = 2
        # TODO: check it
        # self.assertEqual(search_progress.generations_per_sec, 2)

        search_progress.evaluations = 3
        self.assertEqual(search_progress.evaluations, 3)
        
        search_progress.evaluations_per_sec = 4
        self.assertEqual(search_progress.evaluations_per_sec, 4)
        
        search_progress.total_population_size = 5
        self.assertEqual(search_progress.total_population_size, 5)
        
    def testSolutionInfo(self):
        solution_info = eureqa_python.SolutionInfo()
        
        solution_info = eureqa_python.SolutionInfo("text1")
        self.assertEqual(solution_info.text, 'text1')
        
        solution_info.text = 'text2'
        self.assertEqual(solution_info.text, 'text2')
        
        solution_info.score = 1
        self.assertEqual(solution_info.score, 1)
        
        solution_info.fitness = 2
        self.assertEqual(solution_info.fitness, 2)
        
        solution_info.complexity = 3
        self.assertEqual(solution_info.complexity, 3)
        
        solution_info.age = 4
        self.assertEqual(solution_info.age, 4)
        
        
        solution_info_1 = eureqa_python.SolutionInfo()
        solution_info_2 = eureqa_python.SolutionInfo()
        
        solution_info_1.score = 0
        solution_info_1.fitness = 0
        solution_info_1.complexity = 0
        solution_info_1.age = 0
        
        solution_info_2.score = 0
        solution_info_2.fitness = 0
        solution_info_2.complexity = 100
        solution_info_2.age = 0

        result_1 = solution_info_1.dominates(solution_info_2)
        result_2 = solution_info_2.dominates(solution_info_1)
        
        self.assertEqual(result_1, True)
        self.assertEqual(result_2, False)
        
        result_1 = solution_info_1.matches(solution_info_2)
        result_2 = solution_info_2.matches(solution_info_1)       
        self.assertEqual(result_1, result_2)
 
    def testSearchOptions(self):
        search_options = eureqa_python.SearchOptions()
        
        search_options = eureqa_python.SearchOptions('text1')
        self.assertEquals(search_options.search_relationship, 'text1')
        
        building_blocks = eureqa_python.StringVector()
        building_blocks.append('text_v')
        search_options.building_blocks = building_blocks
        self.assertEqual(search_options.building_blocks[0], 'text_v')
        
        search_options.search_relationship = 'text2'
        self.assertEquals(search_options.search_relationship, 'text2')
        
        search_options.fitness_metric = 1
        self.assertEquals(search_options.fitness_metric, 1)
        
        search_options.implicit_derivative_dependencies = 'text3'
        self.assertEquals(search_options.implicit_derivative_dependencies, 'text3')

        search_options.max_delays_per_variable = 3
        self.assertEquals(search_options.max_delays_per_variable, 3)

        search_options.max_history_fraction = 4
        self.assertEquals(search_options.max_history_fraction, 4)

        search_options.min_implicit_variables_used = 5
        self.assertEquals(search_options.min_implicit_variables_used, 5)

        search_options.normalize_fitness_by = 6
        self.assertEquals(search_options.normalize_fitness_by, 6)

        search_options.predictor_crossover_probability = 7
        self.assertEquals(search_options.predictor_crossover_probability, 7)

        search_options.predictor_mutation_probability = 8
        self.assertEquals(search_options.predictor_mutation_probability, 8)

        search_options.predictor_population_size = 9
        self.assertEquals(search_options.predictor_population_size, 9)

        search_options.solution_crossover_probability = 11
        self.assertEquals(search_options.solution_crossover_probability, 11)
        
        search_options.solution_mutation_probability = 12
        self.assertEquals(search_options.solution_mutation_probability, 12)
        
        search_options.solution_population_size = 13
        self.assertEquals(search_options.solution_population_size, 13)
        
        search_options.trainer_population_size = 14
        self.assertEquals(search_options.trainer_population_size, 14)
 
    def testSolutionFrontier(self):
        solution_frontier = eureqa_python.SolutionFrontier()
        
        solution_info_1 = eureqa_python.SolutionInfo()
        solution_info_2 = eureqa_python.SolutionInfo()
        solution_info_3 = eureqa_python.SolutionInfo()
        
        solution_info_1.score = 100
        solution_info_1.fitness = 0.1
        solution_info_1.complexity = 100
        solution_info_1.age = 10
        
        solution_info_2.score = 100
        solution_info_2.fitness = 0.1
        solution_info_2.complexity = 10
        solution_info_2.age = 10

        solution_info_3.score = 100
        solution_info_3.fitness = 0.1
        solution_info_3.complexity = 1
        solution_info_3.age = 10
        
        self.assertTrue(solution_frontier.add(solution_info_1))
        
        result = not (solution_info_1.dominates(solution_info_2) or solution_info_1.matches(solution_info_2))
        self.assertEquals(solution_frontier.test(solution_info_2), result)
        
        self.assertTrue(solution_frontier.to_string() != '')
        
        self.assertEquals(solution_frontier.size(), 1)
        
        solution_frontier.remove(0)

        self.assertEquals(solution_frontier.size(), 0)
        
        self.assertTrue(solution_frontier.add(solution_info_1))
        
        self.assertEquals(solution_frontier.size(), 1)
        
        solution_frontier.clear()
        
        self.assertEquals(solution_frontier.size(), 0)
        
    def testDataSet(self):
        data_set = eureqa_python.DataSet()
        
        self.assertEquals(data_set.is_valid(), False)
        
        data_set = eureqa_python.DataSet(10, 11)
        
        self.assertEquals(data_set.is_valid(), True)
        
        data_set.set_default_symbols()
        
        self.assertEquals(data_set.size(), 10)
        
        self.assertEquals(data_set.num_vars(), 11)
        
        self.assertEquals(data_set.special_vars(), 0)
        
        data_set.clear()
        
        self.assertEquals(data_set.size(), 0)
        
        self.assertEquals(data_set.num_vars(), 0)
        
        self.assertEquals(data_set.special_vars(), 0)
        
        with open('data.txt', 'w') as file:
            file.write('x' + '\t' + 'y' + '\t' + 'z' + '\n')
            for i in range(0,100):
                file.write(str(i) + '\t' + str(i+1) + '\t' + str(i+2) + '\n')
                           
        data_set_2 = eureqa_python.DataSet('data.txt')
        
        self.assertEquals(data_set_2.size(), 100)
        
        self.assertEquals(data_set_2.num_vars(), 3)
        
        self.assertEquals(data_set_2.special_vars(), 0)
        
        data_set.swap(data_set_2)
        
        self.assertEquals(data_set.size(), 100)
        
        self.assertEquals(data_set.num_vars(), 3)
        
        self.assertEquals(data_set.special_vars(), 0)
        
        data_set.resize(200,400)
        
        self.assertEquals(data_set.size(), 200)
        
        self.assertEquals(data_set.num_vars(), 400)
        
        self.assertEquals(data_set.empty(), False)
        
        data_set.clear()
        
        self.assertEquals(data_set.empty(), True)
        
        # TODO: check len(x_symbols)     
        
if __name__ == "__main__":
    #import sys;sys.argv = ['', 'Test.testName']
    unittest.main()