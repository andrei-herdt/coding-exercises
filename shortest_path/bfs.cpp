#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

struct Pos {
  int X;
  int Y;
};

struct EdgeNode {
  int y = -1;
  EdgeNode* next = nullptr;
};

struct Graph {
  Graph(int nvertices) { edges.resize(nvertices, nullptr); }

  vector<EdgeNode*> edges;
};

Pos move(const Pos& init, const Pos& delta) {
  return {.X = init.X + delta.X, .Y = init.Y + delta.Y};
}

bool isValid(const Pos& pos, int grid_size) {
  int max_index = grid_size - 1;
  if (pos.X < 0 || pos.Y < 0) {
    return false;
  }
  if (pos.X > max_index || pos.Y > max_index) {
    return false;
  }
  return true;
}

void printGraph(Graph& graph, std::vector<Pos>& vertices) {
  std::cout << "graph:" << std::endl;
  for (int i = 0; i < graph.edges.size(); i++) {
    if (graph.edges[i]) {
      auto node = vertices[graph.edges[i]->y];
      std::cout << "e" << i << "(" << node.X << "," << node.Y << ")";
      auto next = graph.edges[i]->next;
      while (next != nullptr) {
        auto node = vertices[next->y];
        std::cout << "-";
        std::cout << "(" << node.X << "," << node.Y << ")";
        next = next->next;
      }
      // std::cout << std::endl;
    }
  }
}

void findPath(int start, int end, vector<int>& parents, int& nsteps) {
  if ((start == end) || (end == -1)) {
  } else {
    cout << end << "->";
    nsteps++;
    findPath(start, parents[end], parents, nsteps);
  }
}

/*
 * Complete the 'minimumMoves' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING_ARRAY grid
 *  2. INTEGER startX
 *  3. INTEGER startY
 *  4. INTEGER goalX
 *  5. INTEGER goalY
 */

int minimumMoves(vector<string> grid, int startX, int startY, int goalX,
                 int goalY) {
  // Create vertices
  std::vector<Pos> vertices;
  for (int i = 0; i < grid.size(); i++) {
    const auto& row = grid[i];
    for (int j = 0; j < row.size(); j++) {
      vertices.push_back(Pos{.X = i, .Y = j});
    }
  }
  // Create data structure
  int nvertices = vertices.size() * vertices.size();
  Graph graph(nvertices);
  // Perform a breadth-first search
  vector<bool> processed(nvertices + 1, false);
  vector<int> parents(nvertices + 1, -1);
  vector<bool> discovered(nvertices + 1, false);
  int start = startX * grid.size() + startY;
  int end = goalX * grid.size() + goalY;
  std::deque<int> discovered_nodes({start});
  while (!discovered_nodes.empty()) {
    // Look in all directions for new nodes
    // Look left and right
    const auto& v = discovered_nodes.front();
    const auto& cur_pos = vertices[v];
    const std::vector<Pos> steps = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int y = v;
    // cout << v << ": ";

    // cout << "d:" << discovered_nodes.top();
    for (int i = 0; i < 4; i++) {
      int step = 0;
      bool is_valid = true;
      auto new_pos = move(cur_pos, steps[i]);
      while (isValid(new_pos, grid.size()) &&
             grid[new_pos.X][new_pos.Y] == '.') {
        y = new_pos.X * grid.size() + new_pos.Y;
        // cout << "y" << y <<endl;
        if (!processed[y]) {
          if (!discovered[y]) {
            auto next = graph.edges[v];
            // Put first in list of edges
            graph.edges[v] = new EdgeNode{.y = y, .next = next};
            discovered_nodes.push_back(y);
            parents[y] = v;
            discovered[y] = true;
          }

          // cout << y << " ";

          if (y == end) {
            int nsteps = 0;
            findPath(start, end, parents, nsteps);
            cout << "nsteps: " << nsteps << endl;
            return nsteps;
          }
        }
        // Keep moving in same direction
        new_pos = move(new_pos, steps[i]);
      }
    }
    // cout << endl;
    processed[v] = true;
    while (discovered_nodes.size() > 0 && processed[discovered_nodes.front()]) {
      discovered_nodes.pop_front();
    }
  }

  printGraph(graph, vertices);

  int nsteps = 0;
  cout << "find path" << endl;
  findPath(start, end, parents, nsteps);
  cout << endl;
  cout << "nsteps: " << nsteps << endl;

  return nsteps;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string n_temp;
  getline(cin, n_temp);

  int n = stoi(ltrim(rtrim(n_temp)));

  vector<string> grid(n);

  for (int i = 0; i < n; i++) {
    string grid_item;
    getline(cin, grid_item);

    grid[i] = grid_item;
  }

  string first_multiple_input_temp;
  getline(cin, first_multiple_input_temp);

  vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

  int startX = stoi(first_multiple_input[0]);

  int startY = stoi(first_multiple_input[1]);

  int goalX = stoi(first_multiple_input[2]);

  int goalY = stoi(first_multiple_input[3]);

  int result = minimumMoves(grid, startX, startY, goalX, goalY);

  fout << result << "\n";

  fout.close();

  return 0;
}

string ltrim(const string& str) {
  string s(str);

  s.erase(s.begin(),
          find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

  return s;
}

string rtrim(const string& str) {
  string s(str);

  s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
      s.end());

  return s;
}

vector<string> split(const string& str) {
  vector<string> tokens;

  string::size_type start = 0;
  string::size_type end = 0;

  while ((end = str.find(" ", start)) != string::npos) {
    tokens.push_back(str.substr(start, end - start));

    start = end + 1;
  }

  tokens.push_back(str.substr(start));

  return tokens;
}
