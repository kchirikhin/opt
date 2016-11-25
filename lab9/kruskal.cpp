#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>

class Edge
{
public:
  Edge(int _u, int _v, int _w)
    : u(_u), v(_v), w(_w) {}

  bool operator < (const Edge &e)
  {
    return w < e.w;
  }

  int u;
  int v;
  int w;
};

std::vector<Edge> Kruskal(std::vector<Edge> &e, int n)
{
  std::vector<Edge> result;
  std::vector<int> vert(n);
  for (size_t i = 0; i < n; ++i) {
    vert[i] = i;
  }
  std::sort(e.begin(), e.end());
  for (size_t i = 0; i < e.size(); ++i) {
    if (vert[e[i].u] != vert[e[i].v]) {
      result.push_back(e[i]);
      int old_color = vert[e[i].v];
      int new_color = vert[e[i].u];
      bool several_colors = false;
      for (size_t j = 0; j < vert.size(); ++j) {
	if (vert[j] == old_color) {
	  vert[j] = new_color;
	}
	if (j >= 1 && vert[j] != vert[j - 1]) {
	  several_colors = true;
	}
      }

      if (!several_colors) {
	return result;
      }
    }
  }

  return std::vector<Edge>();
}

int main()
{
  std::ifstream ist;
  ist.open("paral.in");
  int n;
  int x1, x2;
  
  ist >> n >> m;
  std::vector<Edge> e;
  for (size_t i = 0; i < m; ++i) {
    ist >> u >> v;
    e.push_back(Edge(u, v, w));
  }
  ist.close();

  std::vector<Edge> res = Kruskal(e, n);

  std::ofstream ost;
  ost.open("paral.out");
  if (res.size() == 0) {
    ost << "-1";
  } else {
    int sum = 0;
    for (size_t i = 0; i < res.size(); ++i) {
      sum += res[i].w;
    }
  }
  ost.close();
  return 0;
}
