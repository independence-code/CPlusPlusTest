import std;
using namespace std;
class SpreadsheetCell
{
public:
	SpreadsheetCell() = default;//��ʽĬ�ϵ�Ĭ�Ϲ��캯��
	SpreadsheetCell(int c);
	SpreadsheetCell(double s);
	explicit SpreadsheetCell(int c, double s);//��ʽת�����캯��
	SpreadsheetCell(const string& name);//ί�й��캯��
	SpreadsheetCell& operator=(const SpreadsheetCell& rhs);//����ֵ�����ÿ�����ʹ�õȺ�
	int a{ 0 };
	double double_a{};
	vector<int> int_A{};
};

SpreadsheetCell& SpreadsheetCell::operator=(const SpreadsheetCell& rhs)
{
	//�����Ը�ֵ
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
	cout << format("INT���캯��{}",a)<< endl;
}
SpreadsheetCell::SpreadsheetCell(int c, double s) :a{ c }, double_a{ s }
{
	cout << format("INT,DOUBLE���캯��{},{}", a, double_a) << endl;
}
SpreadsheetCell::SpreadsheetCell(const string& name):SpreadsheetCell(10)
{
	cout << "ί�й��캯��" << endl;
}
SpreadsheetCell ::SpreadsheetCell(double s):double_a{s}
{

	cout << format("DOUBLE���캯��{}",double_a) << endl;
}

class EvenSequnce
{
public:
	//��ʼ���б��캯��
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
int main()
{
    EvenSequnce p1{ 1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0 };
	p1.dump();
	try {
		EvenSequnce p2{ 1.0,2.0,3.0 };
	}catch (const invalid_argument& e) {
		cout<<e.what()<<endl;
	}
	SpreadsheetCell cell3[3];
	SpreadsheetCell cell("nihao");
	SpreadsheetCell cell1{ 1 };
	cell1 = 6.0;
	cell1 = SpreadsheetCell{ 2,12.0 };
	cout << "------------" << endl;
	SpreadsheetCell cell2;
	cell2 = cell1;
	cout << cell2.a << endl << cell2.double_a << endl;
	cout << "------------" << endl;
	return 0;
}