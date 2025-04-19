#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Graph
{
string city[10];
int a[10][10];
int n;
public:
void input();
void display();
void BFS();
void DFS();
};

void Graph::input()
{
cout<<"\nEnter No Of Cities: ";
cin>>n;
cout<<"\nEnter The Names Of Cities: ";
for(int i=0 ; i<n ; i++)
cin >> city[i];

cout<<"\nEnter The Distances: ";
for(int i=0 ; i<n ; i++)
for(int j=i ; j<n ; j++)
{
if(i==j)
{
a[i][j] = 0;
continue;
}

cout<<"\nEnter The Distance Between " << city[i] <<" and " << city[j]<< " : ";
cin >> a[i][j];
a[j][i] = a[i][j];
}
}

void Graph::display()
{
for(int i=0 ; i<n ; i++)
{
cout<<"\n";
for(int j=0 ; j<n ; j++)
{
cout<<a[i][j] << "\t";
}
}
}

void Graph::BFS()
{
cout<<"\n\nBFS Traversal: ";
queue<int> q;
int visit[n];
for(int i=0 ; i<n ; i++)
visit[i] = 0;
string start;
int index;
cout<<"\nEnter Starting City: ";
cin>>start;
for(int i=0 ; i<n ; i++)
if(start == city[i])
index =i;

visit[index] = 1;
cout<<city[index]<<" -> ";
int current = index;
while(1)
{
 for(int i=0 ; i<n ; i++)
{
if(a[current][i]!=0 && visit[i] == 0)
{
visit[i] = 1;
q.push(i);
 cout<<city[i]<<" -> ";
}

}
if(q.empty()!=0)
break;
else
{
current = q.front();
 q.pop();
}
}
}

void Graph::DFS()
{
cout<<"\n\nDFS Traversal: ";
stack<int> s;
int visit[n];
for(int i=0 ; i<n ; i++)
 visit[i] = 0;
string start;
int index;
cout<<"\nEnter Starting City: ";
cin>>start;
for(int i=0 ; i<n ; i++)
if(start == city[i])
index =i;
s.push(index);
visit[index] = 1;
int current = index;
cout << city[index]<<" -> ";
while(1)
{
for(int i=0 ; i<n ; i++)
{
if(a[current][i]!=0 && visit[i]==0)
{
s.push(i);
cout<<city[i]<<" -> ";
visit[i] = 1;
 current = i;
i=0;
}
}

if(s.empty()!=0)
break;

else
{
 current = s.top();
s.pop();
}
}
}
int main()
{
Graph g1;
int choice;
MENU:
cout<<"\n\nGraph Trversal";
cout<<"\n1.Input data";
cout<<"\n2.Display data";
 cout<<"\n3.DFS Traversal";
cout<<"\n4.BFS Traversal";
cout<<"\n5.Exit";
cout<<"\nEnter your choice: ";
cin >> choice;
switch(choice)
{
case 1:
g1.input();
break;
 case 2:
g1.display();
break;
case 3:
g1.DFS();
break;
case 4:
g1.BFS();
break;
case 5:
return 0;
default:
cout<<"\nInvalid choice.";
}
if(choice != 5)
goto MENU;
return 0;
}

