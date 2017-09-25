/*
 * Code by Ivan Petukhov
 */

#include <iostream>
#include <vector>
#include <set>
#define MAX 10000
#define INF 100000

using namespace std;

vector<int> Graph[MAX];
set<pair <long long, int>> q;
long long len[MAX];
int prnt[MAX];
vector <long long> res;

void findShortPath(vector<int> *Graph, int a, int b, int n, int m){
	for (int i = 0; i < n; i++)
		len[i] = INF;
    len[a] = 0;
    q.insert (make_pair (len[a], a));
   	while (!q.empty()) {
       	int v = q.begin()->second;
       	q.erase (q.begin());
       	for (int i = 0; i < Graph[v].size(); i++){
        	int end = Graph[v][i];
           	if (len[v] < len[end]) {
	               q.erase (make_pair (len[end], end));
	               len[end] = len[v] + 1;
	               prnt[end] = v;
	               q.insert (make_pair (len[end], end));
            }
        }
    }
	if (len[b] == INF) {
		long long r = -1;
    	res.push_back(r);
       	return;
	} 
	res.push_back(len[b]);
	return;
}
 
int main(){
    int N, M;
    cin >> N;
	cin >> M;
    for (int i = 0; i < M; i++){
        int start, end;
        cin >> start;
		start -= 1;
		cin >> end;
		end -= 1;
        Graph[end].push_back(start);
        Graph[start].push_back(end);
    }

	int Q;
	cin >> Q;

	int start, end;
	for (int i = 0; i < Q; i++){
    	cin >> start;
		start -= 1;
		cin >> end;
		end -= 1;
		findShortPath(Graph, start, end, N, M);
	}
	for (vector<long long>::iterator iter = res.begin(); iter < res.end(); iter++){
		cout << *(iter) << endl;
	}
    return 0;
}