#include "TaskHandler.h"

using namespace std;

TaskHandler::TaskHandler()
{
}

TaskHandler::TaskHandler(const function<void(void)> &f)
{
	m_task = f;
}

TaskHandler::TaskHandler(const function<void(void)> &f, const unsigned long &i, const long repeat)
{
	m_task = f;
	m_sleepTime = chrono::milliseconds(i);
	m_taskCallNumber = repeat;
}

void TaskHandler::Start(bool Async)
{
	if (IsAlive())
		return;

	m_alive = true;
	m_taskCallCount = m_taskCallNumber;

	if (Async)
		m_thread = thread(&TaskHandler::ThreadTask, this);
	else
		this->ThreadTask();
}

void TaskHandler::Stop()
{
	m_alive = false;

	// stops timer
	// joins threads together to stop concurrent execution on main thread
	m_thread.join();
}

bool TaskHandler::IsAlive() const
{
	return m_alive;
}

void TaskHandler::SetTaskRepeatCount(const long r)
{
	if (m_alive)
		return;

	m_taskCallNumber = r;
}

void TaskHandler::SetTask(const function<void(void)> &f)
{
	m_task = f;
}

long TaskHandler::GetTaskCallsLeft() const
{
	return m_taskCallCount;
}

long TaskHandler::GetTaskRepeatCount() const
{
	return m_taskCallNumber;
}

void TaskHandler::SetThreadSleepTime(const unsigned long &i)
{
	if (m_alive)
		return;

	m_sleepTime = chrono::milliseconds(i);
}

unsigned long TaskHandler::GetThreadSleepTime() const
{
	return m_sleepTime.count();
}

const function<void(void)>& TaskHandler::GetTask() const
{
	return m_task;
}

void TaskHandler::SleepAndRun()
{
	this_thread::sleep_for(m_sleepTime);

	if (m_alive)
		GetTask()();
}

void TaskHandler::ThreadTask()
{
	if (m_taskCallNumber == s_Infinite)
	{
		while (m_alive)
			SleepAndRun();
	}
	else
	{
		while (m_taskCallCount--)
			SleepAndRun();
	}
}