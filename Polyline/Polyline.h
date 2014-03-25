#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

typedef std::vector<std::pair<double,double>> Points;

//class that handles vector of entered points
class Handler
{
	int size; // number of points
	Points crossPts; // vector of cross points for all segments
public:
	void InputPoints(Points & obj);
	void ShowInput(const Points & obj) const;
	friend ostream& operator<<(ostream& os, const pair<double,double> & obj);
	void crossPoint(const Points& obj, int s1, int s2, int s3, int s4);
	void ShowCrossPoints() const;
	void cycle(const Points& obj);
};

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
	double a1,a2,b1,b2; //coefs
	double x,y; //cross point coordinates
	a1 = (obj[s2].second - obj[s1].second)/(obj[s2].first - obj[s1].first); // y=a1*x+b
	a2 = (obj[s4].second - obj[s3].second)/(obj[s4].first - obj[s3].first);//
	b1 = obj[s1].second - a1*obj[s1].first;//
	b2 = obj[s3].second - a2*obj[s3].first;//
	if(a1 == a2 ) return; // paralel no points
	x = (b2-b1)/(a1-a2);
	y = a1*x + b1;
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
		for(int j=i; j<size-2; j++)
			crossPoint(obj, i,i+1,j+1,j+2);
	for(int i=0; i<size-1;i++)
		crossPoint(obj,size-1,0,i,i+1);
}
