#ifndef SALES_ITEM_HPP
#define SALES_ITEM_HPP

#include<iterator>
#include<iostream>
#include<stdint.h>

class Sales_Item
{
	public:
		uint64_t getIsbn() const;
		void setIsbn(uint64_t nIsbn);

		uint64_t getCopiesSold() const;
		void setCopiesSold(uint64_t nCopiesSold);

		double getRevenue() const;
		void setRevenue(double revenue);

		friend std::ostream& operator<<(std::ostream& out, Sales_Item& s);
		friend std::istream& operator>>(std::istream& in, Sales_Item& s);
	private:
		uint64_t m_nIsbn;
		uint64_t m_nCopiesSold;
		double m_dRevenue;
};

#endif
