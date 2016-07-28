import urllib.request
import time
from unittest import assertIn


def get_matrix():

	matrix_txt = urllib.request.urlopen(("https://projecteuler.n"
	                               "et/project/resources/p082_matrix.txt"))
	matrix_str = matrix_txt.read().decode("UTF-8")

	matrix = [vec.split(",") for vec in matrix_str.split()]
	matrix = [[int(n) for n in vec] for vec in matrix]
	return matrix


def main():
	start_time = time.time()

	matrix = get_matrix()
	assertIn([4445,2697], matrix[0])

	end_time =time.time()
	print("Time = {}" . format(end_time - start_time))



if __name__ == '__main__':
	main()
