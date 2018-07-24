#include <bits/stdc++.h>

using namespace std;

struct Edge {
	Edge(int a, int b){to = a;cap = b;}
	int to, cap;
};

class Dinic {
public:
	Dinic(int n) {
		edges.resize(n);
		this->n = n;
	}

	int maxFlow(int src, int sink) {
		int ans = 0;
		while(bfs(src, sink)) {
			int flow;
			pt.assign(n, 0);
			while(flow = dfs(src, sink)) ans += flow;
		}
		return ans;
	}

	void addEdge(int from, int to, int cap) {
		edges[from].push_back(list.size());
		list.push_back(Edge(to, cap));
		edges[to].push_back(list.size());
		list.push_back(Edge(from, 0));
	}

private:
	int n;
	vector<vector<int> > edges;
	vector<Edge> list;
	vector<int> h, pt;

	int dfs(int on, int sink, int flow = 1e9) {
		if(flow == 0) return 0;
		if(on == sink) return flow;
		for(; pt[on] < edges[on].size(); pt[on]++) {
			int cur = edges[on][pt[on]];
			if(h[on] + 1 != h[list[cur].to]) continue;
			int got = dfs(list[cur].to, sink, min(flow, list[cur].cap));
			if(got) {
				list[cur].cap -= got;
				list[cur ^ 1].cap += got;
				return got;
			}
		}
		return 0;
	}

	bool bfs(int src, int sink) {
		h.assign(n, n + 10);
		h[src] = 0;
		queue<int> q;
		q.push(src);
		while(!q.empty()) {
			int on = q.front();
			q.pop();
			for(auto a:edges[on]) {
				if(list[a].cap == 0) continue;
				int to = list[a].to;
				if(h[to] > h[on] + 1) {
					h[to] = h[on] + 1;
					q.push(to);
				}
			}
		}
		return h[sink] <= n;
	}
};

const int ms = 1e2;

struct Node {
  int node, cap;
};

map<int, Node> vals[ms];

int q;

Node new_node(int c) {
  Node ans;
  ans.node = q++;
  ans.cap = c;
  return ans;
}

int v[ms];

int main() {
  int n, m;
  cin >> n >> m;
  for (int j = 0;  j < n; j++) {
    int a;
    scanf("%d", &a);
    v[j] = a;
    for (long long i = 2; i * i <= a; i++) {
      if (a % i) continue;
      int c = 0;
      while (a % i == 0) {
        c++;
        a /= i;
      }
      vals[j][i] = new_node(c);
    }
    if (a != 1) {
      vals[j][a] = new_node(1);
    }
  }
  int src = q++, sink = q++;
  Dinic g(q);
  for (int i = 0; i < n; i++) {
    for (auto &it : vals[i]) {
      if (i & 1) {
        g.addEdge(it.second.node, sink, it.second.cap);
      } else {
        g.addEdge(src, it.second.node, it.second.cap);
      }
    }
  }
  for (int j = 0; j < m; j++) {
    int x, y;
    scanf("%d %d", &x, &y);
    x--;
    y--;
    if (x & 1) swap(x, y);
    int a = __gcd(v[x], v[y]);
    for (long long i = 2; i * i <= a; i++) {
      if (a % i) continue;
      int c = 0;
      while (a % i == 0) {
        c++;
        a /= i;
      }
      g.addEdge(vals[x][i].node, vals[y][i].node, c);
    }
    if (a != 1) {
      g.addEdge(vals[x][a].node, vals[y][a].node, 1);
    }
  }
  cout << g.maxFlow(src, sink) << endl;
}
