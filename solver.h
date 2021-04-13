#include <queue>
#include <algorithm>
#include "graph.h"

const int MIN_SIZE = 21;
const int MAX_N = 100;

class Solver {

public:

	Solver () = default;
	Solver (const Graph &new_graph, int new_size) : graph (new_graph), size (new_size), visited (new_size, false) {}
	
	~Solver () = default;
	Solver& operator= (const Solver& solver) = default;
	int GetSize () const { return size; }

	std::vector<int> FindCourses ();
	void SetAnswer ();
	void GetMoreCourses ();

private:

	Graph graph;
	int size = 0;
	std::vector<bool> visited;
};

void Solver::SetAnswer () {
	
	int graph_size = GetSize ();

	std::vector<int> levels = graph.GetLevels ();
	std::vector<int> dependence = graph.GetDependence ();
	std::vector<int> answer (graph_size, MAX_N);

	// zero-level-courses need to study one course to finish them
	for (int vertex = 0; vertex < graph_size; vertex++) {
		if (levels[vertex] == 0) {
			answer[vertex] = 1;
		}
	}

	// for first-level courses
	for (int vertex = 0; vertex < graph_size; vertex++) {
		if (levels[vertex] == 1) {
			answer[vertex] = dependence[vertex];
		}
	}

	std::vector<std::vector<Edge> > relations = graph.GetRelations ();
	// for second-level courses
	for (int vertex = 0; vertex < graph_size; vertex++) {
		if (levels[vertex] == 2) {

			answer[vertex] = 1;
			int last_color = -1;
			int rest = 0;
			int min_color_number = MAX_N;

			for (auto edge : relations[vertex]) {
				
				if (last_color != edge.color) {
					answer[vertex] += rest;
					answer[vertex] += answer[edge.to];
				} else {
					rest = min_color_number;
				}

				last_color = edge.color;
				min_color_number = std::min(MAX_N, answer[edge.to]);
			}

			answer[vertex] += rest;
		}
	}

}

void Solver::GetMoreCourses () {

	// starting from courses with smallest number
}

std::vector<int> Solver::FindCourses () {

	std::vector<int> result;

	int start = graph.GetFifthLvl ();

	std::queue<int> vertex_queue;
	vertex_queue.push(start);
	int len = 1;

	std::vector<std::vector<Edge> > relations = graph.GetRelations ();

	while (!vertex_queue.empty()) {

		int vertex = vertex_queue.front();
		vertex_queue.pop();
		result.push_back(vertex);
		visited[vertex] = true;
		len++;

		int last_color = -1;
		for (auto edge : relations[vertex]) {
			
			if (!visited[edge.to]) {

				// in order to pass only different colored way
				if (edge.color != last_color) {

					vertex_queue.push(edge.to);
					last_color = edge.color;
				}
			}
		}
	}

	if (result.size() < MIN_SIZE) {

		// GetMoreCourses ();
	}

	sort(result.begin(), result.end());
	return result;
}