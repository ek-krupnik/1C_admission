#include <vector.h>
#include <edge.h>

class Graph {

public:

	Graph () = default;
	Graph (int new_size = 0) : size(new_size), relations(new_size) {}

	~Graph () = default;
	Graph operator= () = default;

	void AddEdge (int from, int to, int color);


private:

	std::vector<std::vector<Edge> > relations;
	int size = 0;

};

void Graph::AddEdge (int from, int to, int color) {

	Edge new_edge (to, color);
	relations.push_back (new_edge);
}