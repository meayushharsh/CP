#include<bits/stdc++.h>
using namespace std;
// min priority queue using comparator class , operator overloading
class Comp{
	public:
	bool operator ()(int a,int b){
		return a>b;
	}
};
int main(){
	priority_queue<int, vector<int> , Comp> pq;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	pq.push(i+1);
	cout<<pq.top()<<"\n";
	return 0;
}