#include "salesItem.hpp"

using namespace std;

uint64_t Sales_Item::getIsbn() const
{
	return m_nIsbn;
}

void Sales_Item::setIsbn(uint64_t nIsbn)
{
	m_nIsbn = nIsbn;
}

uint64_t Sales_Item::getCopiesSold() const
{
	return m_nCopiesSold;
}

void Sales_Item::setCopiesSold(uint64_t nCopiesSold)
{
	m_nCopiesSold = nCopiesSold;
}

double Sales_Item::getRevenue() const
{
	return m_dRevenue;
}

void Sales_Item::setRevenue(double revenue)
{
	m_dRevenue = revenue;
}

std::ostream& operator<<(std::ostream& out, Sales_Item& s)
{
	out<<"ISBN : "<<s.m_nIsbn
	   <<" ; Copies Sold : "<< s.m_nCopiesSold
	   <<" ; Revenue Made : "<< s.m_dRevenue;
	return out;
}

std::istream& operator>>(std::istream& in, Sales_Item& s)
{
	in>>s.m_nIsbn>>s.m_nCopiesSold>>s.m_dRevenue;
	return in;
}

int main()
{
	Sales_Item s;
	s.setIsbn(1001);
	s.setCopiesSold(10);
	s.setRevenue(1000);
	cout<<s<<endl;
	cin>>s;
	cout<<s<<endl;
	return 0;
}
