import unittest

from P82 import get_matrix

class test(unittest.TestCase):
	def setUp(self):
		print("Setting up")

	def tearDown(self):
		print("Tearing down")

	def test_returns_correct_matrix(self):
		matrix = get_matrix()
		self.assertTrue([4445,2697] == matrix[0][0:2])
		self.assertTrue([3406,7981] == matrix[79][-2:], 
			"Last two indexes does not match, they were: {}".format(matrix[79][-2:])
			)

if __name__ == '__main__':
	unittest.main()
