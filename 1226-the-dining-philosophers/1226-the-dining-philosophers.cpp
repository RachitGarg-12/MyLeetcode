class Semaphore {
private:
	int count;
    mutex mtx;
    condition_variable cv;
	
public:
    Semaphore(int n = 0) : count(n) { }
    void Set(int n) { count = n; }
    void Signal() {
        unique_lock<mutex> lck(mtx);
        ++count;
        cv.notify_one();
    }
    void Wait() {
        unique_lock<mutex> lck(mtx);
        cv.wait(lck, [&](){ return count > 0; }); // standard format of wait() lambda expression
        --count;
    }
};
class DiningPhilosophers {
    Semaphore fork[5];
    mutex m,l;
public:
    DiningPhilosophers() {
        for(int i=0;i<5;i++){
            fork[i].Set(1);
        }
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        {
            lock_guard<mutex> lock(m);
            fork[(philosopher+1)%5].Wait();
            fork[(philosopher)].Wait();
        }
        pickLeftFork();
        pickRightFork();
        
        eat();
        
        putLeftFork();
        fork[(philosopher+1)%5].Signal();
        putRightFork();
        fork[(philosopher)].Signal();
    }
};