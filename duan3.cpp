#include <bits/stdc++.h>
#include <fstream>
#include <vector>
using namespace std;
int no_parents=-1;
vector<int> q;
void dfs(int A[100][100], int n, int start, vector<bool>& visited){
    q.push_back(start);
    visited[start]=true;
    for(int i=0; i<n; i++){
        if(A[start][i]==1 && (!visited[i])){
            dfs(A,n,i,visited);
        }
    }
}
void bfs(int A[100][100], int n, int start){
    vector<bool> visited(n,false);
    vector<int> queue;
    queue.push_back(start);
    visited[start]=true;
    int vis;
    while(!queue.empty()){
        vis=queue[0];
        cout<<vis<<" ";
        queue.erase(queue.begin());
        for(int i=0; i<n; i++){
            if(A[vis][i]==1 && (!visited[i])){
                queue.push_back(i);
                visited[i]=true;
            }
        }
    }
}
void adj_list(int A[100][100], int n){
    vector<vector<int>> list(n);
    for(int i=0; i<n; i++){;
        for(int j=0; j<n; j++){
            if(A[i][j]==1){
                list[i].push_back(j);
            }
        }
    }
    cout<<"\nDanh sach ke: "<<endl;
    for(int i=0;i<list.size();i++){
        cout<<i;
        for(int j=0;j<list[i].size(); j++){
            if(j==list[i].size()-1){
                cout<<" "<<list[i][j];
                break;
            }
            else cout<<" "<<list[i][j];
        }
        cout<<endl;
    }
    cout<<"So bac: "<<endl;
    for(int i=0; i<list.size(); i++){
        cout<<i<<": "<<list[i].size()<<endl;
    }
}
void print_path(int current, vector<int> parents){
    if(current==no_parents){
        return;
    }
    print_path(parents[current],parents);
    cout<<current<<" ";
}
void print_solution(int start,vector<int> distances, vector<int> parents){
    int nVertices=distances.size();
    cout << "\nVertex \t\t Distance\tPath";
    for (int i = 0; i < nVertices;
         i++) {
        if (i != start) {
            cout << "\n" << start << " -> ";
            cout << i << " \t\t ";
            cout << distances[i] << "\t\t";
            print_path(i, parents);
        }
    }
}
void dijkstra(int A[100][100], int n, int start){
    vector<int> shortest_dist(n);
    vector<bool> added(n);
    for(int i=0;i<n; i++){
        shortest_dist[i]=INT_MAX;
        added[i]=false;
    }
    shortest_dist[start]=0;
    vector<int> parents(n);
    parents[start]=no_parents;
    for(int i=1; i<n; i++){
        int nearest=-1;
        int shortest=INT_MAX;
        for(int vertexIndex=0; vertexIndex<n; vertexIndex++){
            if(!added[vertexIndex] && shortest_dist[vertexIndex]<shortest){
                nearest=vertexIndex;
                shortest=shortest_dist[vertexIndex];
            }
        }
        added[nearest]=true;
        for(int vertexIndex=0; vertexIndex<n; vertexIndex++){
            int edge_dist=A[nearest][vertexIndex];
            if(edge_dist>0 &&  ((shortest+edge_dist)<shortest_dist[vertexIndex])){
                parents[vertexIndex]=nearest;
                shortest_dist[vertexIndex]=shortest+edge_dist;
            }
        }
    }
    print_solution(start, shortest_dist, parents);

}
int main(){
    ifstream fo("matran.txt");
    int n;
    fo>>n;
    cout<<n<<endl;
    int A[100][100];
    int B[100][100];
    for(int i=0; i<n; i++){
        for(int j=0;j<n;j++){
            fo>>A[i][j];
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    fo.close();
    adj_list(A,n);
    vector<bool> visited(n,false);
    dfs(A,n,0,visited);
    cout<<"DFS: ";
    for(int i=0; i<n; i++){
        cout<<q[i]<<" ";
    }
    cout<<"\nBFS: ";
    bfs(A,n,0);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(A[i][j]==1){
                cout<<"Nhap trong so tu dinh "<<i<<" den dinh "<<j<<": "; cin>>B[i][j];  
            }
           else B[i][j]=0;
        }
    }
    dijkstra(B,n,1);
}
