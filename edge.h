
struct Edge {

	int to;
	// in case if there are more than one option to choose
	int color;

	Edge (int new_to = -1, int new_color = -1) : to(new_to), color(new_color) {}
};