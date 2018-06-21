#ifndef SALES_SUMMARY_CPP
#define SALES_SUMMARY_CPP

#include<map>
#include<vector>
#include<shared_ptr>

class Sales_Summary
{
	private:
		map<uint64_t, std::vector<std::shared_ptr<Sales_Item> > > m_vecSalesItem;
};
#endif
