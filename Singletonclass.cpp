#include<iostream>

class cSingletonClass{
private:
	int m_val;
	static cSingletonClass *m_instance;
	cSingletonClass(){
		m_val = 0;
	}

	cSingletonClass(const cSingletonClass& c_obj){
		this->m_val = c_obj.m_val;
	}

public:
	static cSingletonClass *getInstance();

	void print();
	void incrementVal();
};

cSingletonClass *cSingletonClass::m_instance = NULL;

cSingletonClass *cSingletonClass::getInstance(){
	if(m_instance == NULL){
		m_instance = new cSingletonClass();
	}
	return m_instance;
}

void cSingletonClass::print(){
	std::cout<<"\nValue of m_val = "<<m_val;
}

void cSingletonClass::incrementVal(){
	m_val++;
}

int main(){
	cSingletonClass::getInstance()->print();
	cSingletonClass::getInstance()->incrementVal();
	cSingletonClass::getInstance()->print();
}
