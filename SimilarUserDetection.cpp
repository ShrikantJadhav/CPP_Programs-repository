#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class SimilarUserDetection
{
	public:
		string haveSimilar(vector<string> handles)
		{
			string letters = "OIl";
			string numbers = "011";

			size_t n = handles.size();

			for(size_t i = 0; i < n; ++i)
			{
				for(size_t j = 0; j < 3; ++j)
				{
					for(int k = 0; k < handles[i].size(); ++k)
					{
							if( handles[i][k] == letters[j] )
							{
								handles[i][k] = numbers[j];
							}
					}
				}
			}

			set<string> uniq;
			for(size_t i = 0; i < handles.size(); ++i)
			{
				if( uniq.find(handles[i]) != uniq.end() )
					return "Similar handles found";
				uniq.insert(handles[i]);
			}
				return "Similar handles not found";
		}
};

int main()
{
	SimilarUserDetection SUD;
	vector<string> v1 = {"top", "coder", "TOPCODER", "TOPC0DER"};
	cout<<SUD.haveSimilar(v1)<<endl;
	vector<string> v2 = {"Topcoder", "topcoder", "t0pcoder", "topcOder"};
	cout<<SUD.haveSimilar(v2)<<endl;
	vector<string> v3 = {"same", "same", "same", "different"};
	cout<<SUD.haveSimilar(v3)<<endl;
	vector<string> v4 = {"0123", "0I23", "0l23", "O123", "OI23", "Ol23"};
	cout<<SUD.haveSimilar(v4)<<endl;
	vector<string> v5 = {"i23", "123", "456", "789", "000", "o", "O"};
	cout<<SUD.haveSimilar(v5)<<endl;
	return 0;
}
