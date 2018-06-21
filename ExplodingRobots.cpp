#include <iostream>
#include <set>
#include <vector>

using namespace std;


class ExplodingRobots
{
	struct point
	{
		int x;
		int y;
		point (int x1, int y1):x(x1),y(y1)
		{
		}

		bool operator<(const point& p2) const
		{
			return (x == p2.x)?y < p2.y : x < p2.x;
		}

		bool operator==(const point& p2) const
		{
			return ((x == p2.x) && (y == p2.y));
		}
	};

	public:
		void getNextpoint(point& p, char command)
		{
			switch( command )
			{
				case 'R':
					p.x = p.x + 1;
					break;
				case 'L':
					p.x = p.x - 1;
					break;
				case 'U':
					p.y = p.y + 1;
					break;
				case 'D':
					p.y = p.y - 1;
					break;
			}
		}

		string canExplode(int x1,int y1,int x2,int y2, string strCommand)
		{
			string strExplosion = "Explosion";
			string strSafe = "Safe";

			int n = strCommand.length();
			point p1(x1,y1);
			point p2(x2,y2);

			set<point> set1;
			set<point> set2;
			set1.insert(p1);
			set2.insert(p2);

			for(int i = 0; i < n; ++i)
			{
				vector<point> vec;
				for(set<point>::iterator itr = set1.begin();
							itr != set1.end(); ++itr)
				{
					point p((*itr).x,(*itr).y);
					getNextpoint(p,strCommand[i]);
					vec.push_back(p);
				}

				vector<point> vec1;
				for(set<point>::iterator itr = set2.begin();
							itr != set2.end(); ++itr)
				{
					point p((*itr).x,(*itr).y);
					getNextpoint(p,strCommand[i]);
					vec1.push_back(p);
				}

				for(int i = 0; i < vec.size(); ++i)
				{
					set1.insert(vec[i]);
				}

				for(int i = 0; i < vec1.size(); ++i)
				{
					set2.insert(vec1[i]);
				}
			}

			for(set<point>::iterator itr = set1.begin();
						itr != set1.end(); ++itr)
			{
				if( set2.count(*itr) > 0 )
				{
					return strExplosion;
				}
			}

			return strSafe;
		}
};


int main()
{
	ExplodingRobots ER;
	cout<<ER.canExplode(1,0,2,0,"L")<<endl;
	cout<<ER.canExplode(1,0,2,0,"U")<<endl;
	cout<<ER.canExplode(1,0,2,0,"UL")<<endl;
	cout<<ER.canExplode(3,3,5,5,"LURLL")<<endl;
	cout<<ER.canExplode(10,5,-9,-10,"LULULULLLUULRULULULULULULLULULLULD")<<endl;
	cout<<ER.canExplode(-10,-14,12,-7,"ULLULLLLURLDLLDUUUUUDLLLUUDLUULULLLLLUUULLL")<<endl;
	cout<<ER.canExplode(-13, -24, -24, 4, "RUR")<<endl;
}
