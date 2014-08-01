#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
#define EPS 1.0E-6
typedef vector<vector<pair<double,double>>> Graph;
typedef std::vector<std::pair<double,double>> Points;

struct Node
{
	double x;
	double y;
	vector<Node*> pNodes;
	
	Node() : x(0), y(0) {}
	bool operator==(pair<double,double> pr)
	{
		return abs(pr.first-x)<EPS && abs(pr.second-y)<EPS;
	}
	
	Node operator=(pair<double,double> pr)
	{
		x=pr.first;
		y=pr.second;
		return *this;
	}
	

	friend ostream& operator<<(ostream& os, Node obj)
	{
		os << "("<< obj.x <<"," << obj.y << ") ";
		return os;
	}

};

//class that handles vector of entered points
class Handler
{
	int size; // number of points
	Points crossPts; // vector of cross points for all segments
	Graph graph; // Nodes with connections to other nodes
	vector<Node> node;
public:
	Handler() {}
	void InputPoints(Points & obj);
	void ShowInput(const Points & obj) const;
	void FindCrossPoint(const Points& obj, int s1, int s2, int s3, int s4);
	void ShowCrossPoints() const;
	void cycle(const Points& obj);
	void showGraph() const;
	void findNeibours(const Points& obj, int s1 , int s2);
	void fillNode();
	void findFigure();
	friend ostream& operator<<(ostream& os, const pair<double,double> & obj);
	friend ostream& operator<<(ostream& os, const vector<pair<double,double>> & obj);
};

bool myfunction (pair<double,double> i, pair<double,double> j) 
		{ return abs(i.first-j.first)<EPS && abs(i.second-j.second)<EPS; }

bool pairComp(pair<double,double> i, pair<double,double> j)
{
	if(abs(i.first-j.first)< EPS)
		return i.second < j.second;
	else return i.first < j.first;
}

//user input-point-function
void Handler::InputPoints(Points & obj)
{
	
	cout << "Input number of points > 3: ";
	cin >> size;
	obj.resize(size);
	cout << "Enter " << size << " points in format: x y\n";
	for(int i=0; i<size; ++i)
	{
		cout << "#" << i+1 << ": ";
		cin >> obj[i].first >> obj[i].second;
	}
}

//shows what did used input
void Handler::ShowInput(const Points & obj) const
{
	int i=1;
	for(Points::const_iterator it = obj.begin(); it != obj.end();++it,++i)
		cout << "\n#" << i << *it;
}

ostream& operator<<(ostream& os,const pair<double,double> & obj)
{
	os << "(" << obj.first << "," << obj.second << ") ";
	return os;
}
		
ostream& operator<<(ostream& os, const vector<pair<double,double>> & obj)
{
	int i=1;
	for(Points::const_iterator it = obj.begin(); it != obj.end();++it,++i)
		os << "(" << (*it).first << "," << (*it).second << ") ;";
	return os;
}


// looking for cross point of 2 segments and pushing into vector of cross points
void Handler::FindCrossPoint(const Points& obj, int s1 , int s2, int s3, int s4)
{
	double a1,a2,b1,b2,c1,c2; //coefs
	double x,y; //cross point coordinates
	
	a1 = obj[s1].second - obj[s2].second; // ax+by+c=0
	a2 = obj[s3].second - obj[s4].second;//
	b1 = obj[s2].first - obj[s1].first;//
	b2 = obj[s4].first - obj[s3].first;//
	c1 = obj[s1].first * obj[s2].second - obj[s2].first * obj[s1].second;
	c2 = obj[s3].first * obj[s4].second - obj[s4].first * obj[s3].second;

	if( abs(a1-a2) < EPS && abs(b1-b2) < EPS ) 
		return; // paralel no points, even if segments have conjunction that point wont matter
	
	x = ( b1*c2 - b2*c1 ) / (a1*b2-a2*b1);
	y = (a2*c1 - a1*c2) / (a1*b2 - a2*b1);

	//checking if point belongs the segments
	if(    x <= max(obj[s1].first, obj[s2].first) && x >= min(obj[s1].first, obj[s2].first) 
		&& x <= max(obj[s3].first, obj[s4].first) && x >= min(obj[s3].first, obj[s4].first) 
		&& y <= max(obj[s1].second, obj[s2].second) && y >= min(obj[s1].second, obj[s2].second) 
		&& y <= max(obj[s3].second, obj[s4].second) && y >= min(obj[s3].second, obj[s4].second))
		crossPts.push_back(make_pair(x,y));

}

void Handler::ShowCrossPoints() const
{
	int i=1;
	cout << "\nCross points: ";
	for(Points::const_iterator it = crossPts.begin(); it != crossPts.end(); ++it, ++i)
		cout << "\n#"<<i << " " << *it; 
}

void Handler::cycle(const Points& obj)
{
	for(int i=0; i<size-2; i++)
		for(int j=i+1; j<size-1; j++)
			FindCrossPoint(obj, i,i+1,j,j+1);
	for(int i=0; i<size-1;i++)
		FindCrossPoint(obj,size-1,0,i,i+1);
	// making all crosspoints unique
	Points::iterator it;
	sort(crossPts.begin(), crossPts.end(),pairComp);
	it = unique(crossPts.begin(), crossPts.end(), myfunction );
	crossPts.resize(distance(crossPts.begin(),it));
	Points tempVec(1);
	for(int i=0; i<crossPts.size();i++)
	{
		tempVec[0]=crossPts[i];
		graph.push_back(tempVec);
	}

	for(int i=0; i<size-1; i++)
		findNeibours(obj, i,i+1);
	findNeibours(obj,size-1,0);
}

void Handler::showGraph() const
{
	Graph::const_iterator it;
	cout << "\nConnected points:\n";
	int i=1;
	for(it = graph.begin(); it != graph.end(); ++it, ++i)
		cout << "#" << i << *it << endl;
}

void Handler::findNeibours(const Points& obj,int s1 , int s2)
{
	double a,b,c; //coefs
		
	a = obj[s1].second - obj[s2].second; // ax+by+c=0
	b = obj[s2].first - obj[s1].first;//
	c = obj[s1].first * obj[s2].second - obj[s2].first * obj[s1].second;
	Points tempVec;
	vector<int> indexCrossPts; // index for relation between CrossPts and tempVec: crossPts[indexCrossPts[i]] == tempVec[i];
	for(int i=0; i<crossPts.size(); i++)//belonging point to segment
		if( abs(a*crossPts[i].first + b*crossPts[i].second + c)< EPS
		&& crossPts[i].first <= max(obj[s1].first, obj[s2].first) 
		&& crossPts[i].first >= min(obj[s1].first, obj[s2].first)
		&& crossPts[i].second <= max(obj[s1].second, obj[s2].second) 
		&& crossPts[i].second >= min(obj[s1].second, obj[s2].second) )
		{	
			tempVec.push_back(make_pair(crossPts[i].first,crossPts[i].second));
			indexCrossPts.push_back(i);//index in crossPts is value of indexCrossPts
		}
	
	for(int i=0; i<tempVec.size();i++)
		if(myfunction(crossPts[indexCrossPts[i]],tempVec[i]))
		{
			if(i != 0)  graph[indexCrossPts[i]].push_back(tempVec[i-1]);
			if( i != (tempVec.size()-1) ) graph[indexCrossPts[i]].push_back(tempVec[i+1]);
		}
}

void Handler::fillNode()
{
	Node tempnode;
	for(int i=0; i< graph.size(); i++)
	{
		tempnode = graph[i][0];
		node.push_back(tempnode);
	}
	
	for(int i=0; i<graph.size();i++) 
		for(int j=1; j < graph[i].size(); j++)
			for(int k=0; k < node.size(); k++)
				if( node[k] == graph[i][j])
				{
					node[i].pNodes.push_back(&node[k]);
					break;
				}
	for(int i=0; i<node.size();i++) 
	{
		cout << endl;
		for(int j=0; j < node[i].pNodes.size(); j++)
				cout << *(node[i].pNodes[j]) << " ";
	}
}

