#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
#define EPS 1.0E-6
typedef vector<vector<pair<double,double>>> Graph;
typedef std::vector<std::pair<double,double>> Points;

//class that handles vector of entered points
class Handler
{
	int size; // number of points
	Points crossPts; // vector of cross points for all segments
	Graph graph;
	
public:
	Handler::Handler() {}
	void InitGraph(const Points& obj);
	void InputPoints(Points & obj);
	void ShowInput(const Points & obj) const;
	friend ostream& operator<<(ostream& os, const pair<double,double> & obj);
	void crossPoint(const Points& obj, int s1, int s2, int s3, int s4);
	void ShowCrossPoints() const;
	void cycle(const Points& obj);
	 // func to compare doubles
	
};

bool myfunction (pair<double,double> i, pair<double,double> j) 
		{ return abs(i.first-j.first)<EPS && abs(i.second-j.second)<EPS; }

bool pairComp(pair<double,double> i, pair<double,double> j)
{
	if(abs(i.first-j.first)< EPS)
		return i.second < j.second;
	else return i.first < j.first;
}


void Handler::InitGraph(const Points& obj)
{
	graph.resize(obj.size());
	graph[0].push_back(obj[0]);
	graph[0].push_back(obj[obj.size()-1]);
	graph[0].push_back(obj[1]);
	
	graph[obj.size()-1].push_back(obj[obj.size()-1]);
	graph[obj.size()-1].push_back(obj[obj.size()-2]);
	graph[obj.size()-1].push_back(obj[0]);
	
	for(int i=1; i < obj.size()-2; i++)
	{
		graph[i].push_back(obj[i]);
		graph[i].push_back(obj[i+1]);
		graph[i].push_back(obj[i-1]);
	}
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
				
// looking for cross point of 2 segments and pushing into vector of points
void Handler::crossPoint(const Points& obj, int s1 , int s2, int s3, int s4)
{
	double a1,a2,b1,b2,c1,c2; //coefs
	double x,y; //cross point coordinates
	
	a1 = obj[s1].second - obj[s2].second; // ax+by+c=0
	a2 = obj[s3].second - obj[s4].second;//
	b1 = obj[s2].first - obj[s1].first;//
	b2 = obj[s4].first - obj[s3].first;//
	c1 = obj[s1].first * obj[s2].second - obj[s2].first * obj[s1].second;
	c2 = obj[s3].first * obj[s4].second - obj[s4].first * obj[s3].second;

	if( abs(a1-a2) < EPS && abs(b1-b2) < EPS ) return; // paralel no points
	
	x = ( b1*c2 - b2*c1 ) / (a1*b2-a2*b1);
	y = (a2*c1 - a1*c2) / (a1*b2 - a2*b1);

	//checking if point belongs the segments
	if(    x <= max(obj[s1].first, obj[s2].first) && x >= min(obj[s1].first, obj[s2].first) 
		&& x <= max(obj[s3].first, obj[s4].first) && x >= min(obj[s3].first, obj[s4].first) 
		&& y <= max(obj[s1].second, obj[s2].second) && y >= min(obj[s1].second, obj[s2].second) 
		&& y <= max(obj[s3].second, obj[s4].second) && y >= min(obj[s3].second, obj[s4].second))
	{
		crossPts.push_back(make_pair(x,y));
		vector <pair<double,double>> point_vector;
		graph.push_back(point_vector);
		graph[graph.size()-1].push_back(make_pair(x,y));//push_back(make_pair(x,y));
		graph[graph.size()-1].push_back(make_pair(obj[s1].first,obj[s1].second));
		graph[graph.size()-1].push_back(make_pair(obj[s2].first,obj[s2].second));
		graph[graph.size()-1].push_back(make_pair(obj[s3].first,obj[s3].second));
		graph[graph.size()-1].push_back(make_pair(obj[s4].first,obj[s4].second));
	}
	
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
		for(int j=i; j<size-2; j++)
			crossPoint(obj, i,i+1,j+1,j+2);
	for(int i=0; i<size-1;i++)
		crossPoint(obj,size-1,0,i,i+1);
	// making all crosspoints unique
	Points::iterator it;
	sort(crossPts.begin(), crossPts.end(),pairComp);
	it = unique(crossPts.begin(), crossPts.end(), myfunction );
	crossPts.resize(distance(crossPts.begin(),it));
}
