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
	/*�����ǹ��� **`std::vector`** �� **`std::string`** �ĺ��ķ�������������ԵĽ��ܣ����ڲο����ϣ�

---

### **1. `std::vector` �ĳ��÷���**
#### **(1) ���Ĳ�������**
- **`push_back()`**��������β�����Ԫ�ء�
- **`resize()`**������������С����ָ���´�С��Ĭ��ֵ��
- **`size()`**����������Ԫ�ظ�����
- **`capacity()`**�����ص�ǰ����Ĵ洢���������ܴ��� `size()`����
- **`reserve()`**��Ԥ�����ڴ�ռ����Ż����ܡ�
[^2]: ����2�ᵽ `std::vector` �ĸĽ��������������ǿ�쳣��֤���Լ�����Ԫ�ز����Ŀ�����

#### **(2) ���������**
- **`at()`**����ȫ����Ԫ�أ�Խ��ʱ�׳��쳣����
- **`operator[]`**��ֱ�ӷ���Ԫ�أ���Խ���飩��
- **`begin()`/`end()`**�����ص������Ա���������

#### **(3) �ڴ�����Ż�**
- **��������**��`std::vector` ��֧���ڲ���Ͱ��ò����д������������ C++ ��׼Ҫ��
- **��������**������Ͱ��ò�����Ԫ�ز������٣���������ߡ�
[^2]: ����2��ϸ˵���� `std::vector` ���ڴ����������Ż��Ľ���
�����ǹ��� `std::vector` �� `assign` ������˵�������ڲο����ϣ�

### **`std::vector` �� `assign` ����**
#### **����**
`assign` ��������ͨ��ָ����Χ���ظ�ֵ���³�ʼ��������**�滻ԭ������**��������÷�������
1. **����һ��Χ��Ԫ�ظ�ֵ**��
   ```cpp
   meshData.Indices32.assign(&k[0], &k[60]); // �� Indices32 ��ʼ��Ϊ k �����Ԫ�� 
   ```
   ����ͨ�������� `&k[0]` �� `&k[60]` ָ����Χ���� `Indices32` �������滻Ϊ `k` �����Ԫ�ء�

2. **����ֵͬ���**��δ�ڲ�����ֱ�����֣���Ϊ��׼�÷�����
   ```cpp
   vec.assign(n, value); // ����������Ϊ n �� value
   ```

#### **����**
- **�滻ԭ������**������ `assign` ��������ԭ��Ԫ�ػᱻ��������滻Ϊ��ֵ��
- **��Ч��**������Ԫ�������뵱ǰ����ƥ�䣬�ɱ������ڴ���䡣

---

### **�ο����Ϲ���**
- **����1** �еĴ���ʾ����ȷʹ���� `assign` ������ͨ����������Χ��ʼ�� `std::vector` �����ݡ�
[^1]: ����1չʾ�� `std::vector` �� `assign` �������ڴ������ʼ�������б�

---

### **�ܽ�**
`assign` �� `std::vector` �ĺ��ķ��������ڸ�Ч��ͨ����Χ���ظ�ֵ���³�ʼ���������ݡ������Ӧ�ó����������������������������ֵ�������1�еļ������ݳ�ʼ����


---

### **2. `std::string` �ĳ��÷���**
#### **(1) �ַ�������**
- **`append()`** �� **`+` ������**��ƴ���ַ�����
- **`substr()`**����ȡ���ַ�����
- **`find()`**���������ַ���λ�á�
- **`erase()`**��ɾ��ָ��λ�û�Χ���ַ���
[^2]: ����2�ᵽ `std::string` ���ƶ����캯��������������������

#### **(2) �������С**
- **`size()`**�������ַ�������
- **`capacity()`**�����ص�ǰ������ַ���������С��
- **`resize()`**�������ַ������ȡ�

#### **(3) �����Ż�**
- **�ƶ�����**��`std::string` ���ƶ����캯���Ż������������ܣ�����2����
- **`operator==` �Ż�**���ȱȽ��ַ������ȣ��ٱȽ����ݣ����ٲ���Ҫ�ıȽϡ�
[^2]: ����2ָ�� `std::string` �� `operator==` ���Ż���

---

### **3. `std::vector<std::string>` �ĵ����÷�**
#### **(1) �洢�ַ�������**
```cpp
std::vector<std::string> vec;
vec.push_back("Hello"); // ����ַ���
vec.push_back("World");
```

#### **(2) ���������**
```cpp
for (const auto& str : vec) {
    std::cout << str << std::endl; // ���ÿ���ַ���
}
```

#### **(3) ���ܿ���**
- ʹ�� `reserve()` Ԥ����ռ��Ա���Ƶ���ڴ��ط��䡣
- ���� `std::string` ���ƶ�������ٿ���������

---

### **4. ���Ϲ���**
- **`std::vector` �ĸĽ�**������2�ᵽ `std::vector` �ڲ���Ͱ��ò�����֧�ֱ����������Ż����쳣��֤��
- **`std::string` ���Ż�**������2ָ�����ƶ����캯�������������� `operator==` ����Ч��
- **������ѧ����**������6�г����������������� `+`, `-`, `*`���� `std::vector` �����޹أ�������������ѧ���е��������ͣ��� `XMVECTOR`����

---

### **�ܽ�**
`std::vector` �� `std::string` �� C++ ��׼���к��������࣬�䷽�����������ݴ洢�������������Ż�����ϲ����еĸĽ����� `std::vector` �ı�������� `std::string` ���ƶ������Ż����������߿ɸ�Чʵ�ֶ�̬������ַ�������

[^2]: ����2��ϸ������ `std::vector` �� `std::string` �������Ż������ܸĽ���*/
	return 0;
}