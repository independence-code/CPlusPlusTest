import <iostream>;
import <string>;
import <vector>;
import <format>;
import "DirectXMath.h";
import "DirectXPackedVector.h";
import "windows.h";
import config;
import XMVectorTest;
using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

class SpreadsheetCell
{
public:
	SpreadsheetCell() = default;//显式默认的默认构造函数
	SpreadsheetCell(int c);
	SpreadsheetCell(double s);
	explicit SpreadsheetCell(int c, double s);//显式转换构造函数
	SpreadsheetCell(const string& name);//委托构造函数
	SpreadsheetCell& operator=(const SpreadsheetCell& rhs);//返回值是引用可连续使用等号
	int a{ 0 };
	double double_a{};
	vector<int> int_A{};
};

SpreadsheetCell& SpreadsheetCell::operator=(const SpreadsheetCell& rhs)
{
	//避免自赋值
	if (this != &rhs) {
		this->a = rhs.a;
		this->double_a = rhs.double_a;
		this->int_A = rhs.int_A;
	}
	return *this;
}
SpreadsheetCell::SpreadsheetCell(int c)
{
	a = c;
	std::
	cout << std::format("INT构造函数{}", a) << endl;
}
SpreadsheetCell::SpreadsheetCell(int c, double s) :a{ c }, double_a{ s }
{
	cout << format("INT,DOUBLE构造函数{},{}", a, double_a) << endl;
}
SpreadsheetCell::SpreadsheetCell(const string& name) :SpreadsheetCell(10)
{
	cout << "委托构造函数" << endl;
}
SpreadsheetCell::SpreadsheetCell(double s) :double_a{ s }
{

	cout << format("DOUBLE构造函数{}", double_a) << endl;
}

class EvenSequnce
{
public:
	//初始化列表构造函数
	EvenSequnce(initializer_list<double> args)
	{
		if (args.size() % 2 != 0) {
			throw invalid_argument{ "initializer_list should"
			"contain even number of elements." };
		}
		m_sequnce.reserve(args.size());
		for (const auto& value : args) {
			m_sequnce.push_back(value);
		}
	}
	void dump()const
	{
		for (const auto& value : m_sequnce) {
			cout << value << ",";
		}
		cout << endl;
	}
private:
	vector<double> m_sequnce;
};

class base
{
public:
	virtual void overload(){cout << "base" << endl;};
	virtual void overload(int a){cout << format("base{}",a)<< endl;}
	int geta(int a) { return a * b(); }
	virtual  void go(int i=2) { cout << format("base i={}", i) << endl; }
private:
	virtual int b() { return 35; };
};
class derived:public base
{
public:
	using base::overload;
	void overload() override {cout << "derived" << endl;}
	//默认参数不被继承
	void go(int i=7) override { cout << format("derived i={}", i) << endl; }
private:
	int b() override { return 40; }; //c++允许重载私有函数
	
};
int main()
{
	testVector();
	//cout << grid.getA() << endl;
	//base s1;
	//s1.go();
	//derived d1;
	//d1.go();
	//base& s2{ d1 };
	//s2.go();
	//s2.go(1);
	//cout << "derived d1   " << d1.geta(2) << endl;
	//cout << d1.geta(2) << endl;
	//cout << "------" << endl;
	//cout << "base s1  " << s1.geta(2) << endl;
	//cout << "base& s2{ d1 }  " << s2.geta(2) << endl;
	//cout << s2.geta(2) << endl;
	//derived& d2 { dynamic_cast<base>(s1)};

	//base s;
	//cout << s.geta(2) << endl;
	//derived d;
	//cout << d.geta(2) << endl;
	//derived d;
	//d.overload();
	//d.overload(1);
	//EvenSequnce p1{ 1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0 };
	//p1.dump();
	//try {
	//	EvenSequnce p2{ 1.0,2.0,3.0 };
	//}
	//catch (const invalid_argument& e) {
	//	cout << e.what() << endl;
	//}
	//SpreadsheetCell cell3[3];
	//SpreadsheetCell cell("nihao");
	//SpreadsheetCell cell1{ 1 };
	//cell1 = 6.0;
	//cell1 = SpreadsheetCell{ 2,12.0 };
	//cout << "------------" << endl;
	//SpreadsheetCell cell2;
	//cell2 = cell1;
	//cout << cell2.a << endl << cell2.double_a << endl;
	//cout << "------------" << endl;
	
	return 0;
}