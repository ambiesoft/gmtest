#include "gtest/gtest.h"
#include "MockTurtle.h"

using ::testing::AtLeast;

class Foo {
public:
	virtual ~Foo() {}
	virtual char DoThis(int n) = 0;
	virtual void DoThat(const char* s, int* p) = 0;
};

class FakeFoo : public Foo {
public:
	char DoThis(int n) override {
		return (n > 0) ? '+' :
			(n < 0) ? '-' : '0';
	}

	void DoThat(const char* s, int* p) override {
		*p = (int)strlen(s);
	}
};

class MockFoo : public Foo {
public:
	// Normal mock method definitions using gMock.
	MOCK_METHOD(char, DoThis, (int n), (override));
	MOCK_METHOD(void, DoThat, (const char* s, int* p), (override));

	// Delegates the default actions of the methods to a FakeFoo object.
	// This must be called *before* the custom ON_CALL() statements.
	void DelegateToFake() {
		ON_CALL(*this, DoThis).WillByDefault([this](int n) {
			return fake_.DoThis(n);
			});
		ON_CALL(*this, DoThat).WillByDefault([this](const char* s, int* p) {
			fake_.DoThat(s, p);
			});
	}

private:
	FakeFoo fake_;  // Keeps an instance of the fake in the mock.
};

using ::testing::_;

TEST(AbcTest, Xyz) {
	MockFoo foo;

	foo.DelegateToFake();  // Enables the fake for delegation.

	// Put your ON_CALL(foo, ...)s here, if any.

	// No action specified, meaning to use the default action.
	EXPECT_CALL(foo, DoThis(5));
	EXPECT_CALL(foo, DoThat(_, _));

	int n = 0;
	EXPECT_EQ('+', foo.DoThis(5));  // FakeFoo::DoThis() is invoked.
	foo.DoThat("Hi", &n);  // FakeFoo::DoThat() is invoked.
	EXPECT_EQ(2, n);
}