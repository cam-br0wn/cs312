class MyClass
{
public:
	MyClass();
	~MyClass();
	MyClass(const MyClass &) = default;
	MyClass(MyClass &&) = default;
	MyClass &operator=(const MyClass &) = default;
	MyClass &operator=(MyClass &&) = default;

private:
};