#include <iostream>
#include <solver.h>

const int THIRD_NUM = 3;

int main () {

	int courses_number = 0;
	std::cin >> courses_number;
	Graph course_graph (courses_number);

	for (int i = 0; i < courses_number; i++) {

		int main_course = 0;
		int course_level = 0;
		int relations_number = 0;
		std::cin >> main_course >> course_level >> relations_number;

		for (int color = 0; color < relations_number; color++) {

			// student must choose one course of each color
			int choose_number = 0;
			std::cin >> choose_number;
			
			for (int k = 0; k < choose_number; k++) {

				int dependent_course = 0;
				std::cin >> dependent_course;
				course_graph.AddEdge (main_course, dependent_course, color);
			}
		}
	}

	int second_lvl_number = 0;
	std::cin >> second_lvl_number;
	std::vector<int> second_lvl_courses (second_lvl_number, 0);

	for (int i = 0; i < second_lvl_number; i++) {
		std::cin >> second_lvl_courses[i];
	}

	int fifth_lvl_course = 0;
	std::cin >> fifth_lvl_course;

	std::vector<int> third_lvl_courses (THIRD_NUM, 0);
	for (int i = 0; i < THIRD_NUM; i ++) {
		std::cin >> third_lvl_courses[i];
	}

	Solver solver (graph);
	std::vector<int> result = solver.FindCourses ();

	for (auto i : result) {
		std::cout << i << ' ';
	}
}