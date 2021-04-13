#include <vector>
#include "edge.h"

class Graph {

public:

	Graph () = default;
	Graph (int new_size = 0) : size(new_size), relations(new_size) {}

	~Graph () = default;
	Graph& operator= (const Graph& graph) = default;

	void AddEdge (int from, int to, int color);
	
	void SetFifthLvl (int new_fifth_lvl = 0) { fifth_lvl = new_fifth_lvl; }
	void SetThirdLvl (std::vector<int> new_third_lvl_courses) { third_lvl_courses = new_third_lvl_courses; }

	int GetFifthLvl () { return fifth_lvl; }
	std::vector<int> GetThirdLvl () { return third_lvl_courses; }
	std::vector<std::vector<Edge> > GetRelations () { return relations; }

private:

	std::vector<std::vector<Edge> > relations;
	int size = 0;

	int fifth_lvl = 0;
	std::vector<int> third_lvl_courses;
};

void Graph::AddEdge (int from, int to, int color) {

	Edge new_edge (to, color);
	relations[from].push_back (new_edge);
}