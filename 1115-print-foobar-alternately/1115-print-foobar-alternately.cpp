class FooBar {
private:
    int n;
    mutex mtx;
    condition_variable cv;
    bool fooTurn = true;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);

            cv.wait(lock, [this]() {
                return fooTurn;
            });

            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();

            fooTurn = false;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);

            cv.wait(lock, [this]() {
                return !fooTurn;
            });

            // printBar() outputs "bar". Do not change or remove this line.
            printBar();

            fooTurn = true;
            cv.notify_one();
        }
    }
};