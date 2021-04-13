#include <graph.h>

class Solver {

public:

	Solver () = default;
	Solver (const Graph &new_graph) : graph (new_graph) {}
	
	~Solver () = default;
	Solver operator= () = default;

	std::vector<int> FindCourses ();

private:

	Graph graph;
};