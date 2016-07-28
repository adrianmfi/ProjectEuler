import urllib.request
import time
from queue import PriorityQueue

				

def get_matrix():

	matrix_txt = urllib.request.urlopen(("https://projecteuler.n"
	                               "et/project/resources/p082_matrix.txt"))
	matrix_str = matrix_txt.read().decode("UTF-8")

	matrix = [vec.split(",") for vec in matrix_str.split()]
	matrix = [[int(n) for n in vec] for vec in matrix]
	return matrix


def set_minimum_cost_column(matrix,current_column):
	pass

def main(): 
	matrix = get_matrix()
	number_of_columns = len(matrix[0])
	
	current_column = 1
	while(current_column < number_of_columns:
		set_minimum_cost_column(matrix,current_column)

		current_column += 1

if __name__ == '__main__':
	start_time = time.time()
	main()	
	end_time =time.time()
	print("Time = {}" . format(end_time - start_time))
