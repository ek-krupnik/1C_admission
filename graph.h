#include <vector>
#include "edge.h"

class Graph {

public:

	Graph () = default;
	Graph (int new_size = 0) : size(new_size), relations(new_size), levels(new_size), dependence(new_size) {}

	~Graph () = default;
	Graph& operator= (const Graph& graph) = default;

	void AddEdge (int from, int to, int color);
	
	void SetLevels (std::vector<int> new_levels) { levels = new_levels; }
	void SetFifthLvl (int new_fifth_lvl = 0) { fifth_lvl = new_fifth_lvl; }
	void SetDependence (std::vector<int> new_dependence) { dependence = new_dependence; }
	void SetThirdLvl (std::vector<int> new_third_lvl_courses) { third_lvl_courses = new_third_lvl_courses; }

	int GetFifthLvl () const { return fifth_lvl; }
	std::vector<int> GetLevels () const { return levels; }
	std::vector<int> GetDependence () const { return dependence; } 
	std::vector<int> GetThirdLvl () const { return third_lvl_courses; }
	std::vector<std::vector<Edge> > GetRelations () { return relations; }

private:

	std::vector<std::vector<Edge> > relations;
	int size = 0;

	int fifth_lvl = 0;
	std::vector<int> third_lvl_courses;
	std::vector<int> levels;
	std::vector<int> dependence;
};

void Graph::AddEdge (int from, int to, int color) {

	Edge new_edge (to, color);
	relations[from].push_back (new_edge);
}