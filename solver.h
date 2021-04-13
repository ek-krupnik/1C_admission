#include <queue>
#include <algorithm>
#include "graph.h"

const int MIN_SIZE = 21;

class Solver {

public:

	Solver () = default;
	Solver (const Graph &new_graph, int new_size) : graph (new_graph), size (new_size), visited (new_size, false) {}
	
	~Solver () = default;
	Solver& operator= (const Solver& solver) = default;

	std::vector<int> FindCourses ();
	void GetMoreCourses ();

private:

	Graph graph;
	int size = 0;
	std::vector<bool> visited;
};

void SetAnswer () {

	// for first-level
}

void GetMoreCourses () {

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