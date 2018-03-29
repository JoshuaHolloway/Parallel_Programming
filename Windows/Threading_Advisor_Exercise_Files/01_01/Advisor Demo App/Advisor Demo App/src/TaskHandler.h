#ifndef TASK_HANDLER_H
#define TASK_HANDLER_H

#include <thread>
#include <chrono>

using namespace std;

// The TaskHandler object is a thread which handles asynchronous execution of a given task. 
// It takes in a task to be repeatedly executed on a separate thread. 
class TaskHandler
{
public:
	static const long s_Infinite = -1L;

	// constructors
	TaskHandler();

	// overloaded constructors to allow easier thread initialization
	TaskHandler(const function<void(void)> &f);
	TaskHandler(const function<void(void)> &f, const unsigned long &i, const long repeat = TaskHandler::s_Infinite);

	// starts the timer thread
	void Start(bool Async = true);

	// stops the timer thread via join
	void Stop();

	// check thread alive status flag
	bool IsAlive() const;

	// setter for number of repeats
	void SetTaskRepeatCount(const long r);

	// set thread function 
	void SetTask(const function<void(void)> &f);

	// returns number of task calls left
	long GetTaskCallsLeft() const;

	// returns number of repeats
	long GetTaskRepeatCount() const;

	// set time for thread to sleep for
	void SetThreadSleepTime(const unsigned long &i);

	// get thread sleep time 
	unsigned long GetThreadSleepTime() const;

	// get thread function
	const function<void(void)>& GetTask() const;

private:
	thread m_thread;						// thread for asynchronous execution
	bool m_alive = false;					// is the process alive (running)?
	long m_taskCallNumber = -1L;			// how many times to call a function
	long m_taskCallCount = -1L;				// how many times a function has been called
	chrono::milliseconds m_sleepTime = chrono::milliseconds(0); // time between function calls

	// a pointer to a function (initialized as null)
	function<void(void)> m_task = nullptr;

	// thread functions 
	void SleepAndRun();
	void ThreadTask();

};

#endif // TaskHandler_H