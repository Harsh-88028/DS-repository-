4. Given an adjacency matrix of a graph, write a program to check whether a given set of vertices {v1,v2,v3.....,vk}
   forms an Euler path / Euler Circuit (for circuit assume vk=v1).

#include<iostream>
#include<vector>
#define NODE 5
using namespace std;
int graph[NODE][NODE] = {{0, 0, 1, 1, 0},
   {1, 0, 1, 0, 0},
   {0, 0, 0, 1, 0},
   {0, 1, 0, 0, 1},
   {1, 0, 0, 0, 0}};
void traverse(int u, bool visited[]) {
   visited[u] = true; //mark v as visited
   for(int v = 0; v<NODE; v++) {
      if(graph[u][v]) {
         if(!visited[v])
            traverse(v, visited);
      }
   }
}
bool isConnected() {
   bool *vis = new bool[NODE];
   //for all vertex u as start point, check whether all nodes are visible or not
   for(int u; u < NODE; u++) {
      for(int i = 0; i<NODE; i++)
         vis[i] = false; //initialize as no node is visited
         traverse(u, vis);
      for(int i = 0; i<NODE; i++) {
         if(!vis[i]) //if there is a node, not visited by traversal, graph is not connected
            return false;
      }
   }
   return true;
}
bool hasEulerPath() {
   int an = 0, bn = 0;
   if(isConnected() == false){ //when graph is not connected
      return false;
   }
   vector<int> inward(NODE, 0), outward(NODE, 0);
   for(int i = 0; i<NODE; i++) {
      int sum = 0;
      for(int j = 0; j<NODE; j++) {
         if(graph[i][j]) {
            inward[j]++; //increase inward edge for destination vertex
            sum++; //how many outward edge
         }
      }
      outward[i] = sum;
   }
   //check the condition for Euler paths
   if(inward == outward) //when number inward edges and outward edges for each node is same
      return true; //Euler Circuit, it has Euler path
   for(int i = 0; i<NODE; i++) {
      if(inward[i] != outward[i]) {
         if((inward[i] + 1 == outward[i])) {
            an++;
         } else if((inward[i] == outward[i] + 1)) {
            bn++;
         }
      }
   }
   if(an == 1 && bn == 1) { //if there is only an, and bn, then this has euler path
      return true;
   }
   return false;
}
int main() {
   if(hasEulerPath())
      cout << "Euler Path Found.";
   else
   cout << "There is no Euler Circuit.";
}


Output -

Euler Path Found.
