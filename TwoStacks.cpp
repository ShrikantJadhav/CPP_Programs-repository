#include<iostream>
#include<algorithm>
#include<iterator>

using namespace std;

template<typename T>
class TwoStacks
{
public:
  explicit TwoStacks(int size):
            m_size(size),
            m_top1(-1),
            m_top2(size)
  {
    m_arr = new(nothrow) T[m_size];
    if( m_arr )
      fill(m_arr, m_arr+m_size,0);
  }

  ~TwoStacks()
  {
    if( m_arr )
      delete[] m_arr;
  }

  bool pushToStack1(const T& element)
  {
    if( m_arr && m_top1+1 < m_top2 )
    {
      m_arr[++m_top1] = element;
      return true;
    }
    return false;
  }

  bool pushToStack2(const T& element)
  {
    if( m_arr && m_top1+1 < m_top2 )
    {
      m_arr[--m_top2] = element;
      return true;
    }
    return false;
  }

  void popFromStack1()
  {
    if( m_arr && m_top1 > -1 )
    {
      m_arr[m_top1] = 0;
      m_top1--;
    }
  }

  void popFromStack2()
  {
    if( m_arr && m_top2 < m_size )
    {
      m_arr[m_top2] = 0;
      m_top2++;
    }
  }

  T topOfStack1()
  {
    if( m_arr && m_top1 > -1 )
    {
      return m_arr[m_top1];
    }
  }

  T topOfStack2()
  {
    if( m_arr && m_top2 < m_size )
    {
      return m_arr[m_top2];
    }
  }

  void printStack()
  {
    copy(m_arr, m_arr+m_size, ostream_iterator<T>(cout," "));
    cout<<endl;
  }

private:
  T *m_arr;
  int m_size;
  int m_top1;
  int m_top2;
};

int main()
{
  TwoStacks<int> t(10);
  t.printStack();

  t.pushToStack1(1);
  t.pushToStack1(2);
  t.printStack();

  t.pushToStack2(11);
  t.pushToStack2(12);
  t.printStack();

  t.pushToStack2(110);
  t.pushToStack2(120);
  t.printStack();

  t.pushToStack2(11);
  t.pushToStack2(12);
  t.printStack();

  t.pushToStack1(211);
  t.pushToStack1(212);
  t.printStack();

  t.pushToStack1(211);
  t.pushToStack1(212);
  t.printStack();

  t.popFromStack1();
  t.popFromStack2();
  t.printStack();

  TwoStacks<char> c(10);
  c.printStack();
  c.pushToStack1('a');
  c.pushToStack1('b');
  c.printStack();

  c.pushToStack2('r');
  c.pushToStack2('s');
  c.printStack();

  TwoStacks<double> d(10);
  d.printStack();
  d.pushToStack1(10.98);
  d.pushToStack1(98.10);
  d.printStack();

  d.pushToStack2(99.78);
  d.pushToStack2(89.78);
  d.printStack();

  TwoStacks<string> s(10);
  s.printStack();
  s.pushToStack1("abcd");
  s.pushToStack1("cefg");
  s.printStack();

  s.pushToStack2("iokl");
  s.pushToStack2("po");
  s.printStack();
  return 0;
}
