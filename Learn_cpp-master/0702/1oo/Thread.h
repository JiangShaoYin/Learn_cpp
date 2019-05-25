 /// @date    2018-07-02 13:20:31

#ifndef __THREAD_H__
#define __THREAD_H__

#include <pthread.h>


namespace wd {
class Thread {
	public:
		Thread();
		void start();//创建子线程，执行run方法
		void join();//回收本线程(_pid)
		virtual ~Thread();//回收本对象,将线程状态设为detached（由系统自动回收thread资源，无需调用join）
	private:
		virtual void run() = 0;//定义子线程功能的virtual函数,通过start（）方法创建子线程，执行run方法
		//因为pthread_create()第3个参数,要求必须为void* func(void*)型，run不符合，所以再创建ThreadFunc，在此函数内部再调用run（）
		static void * ThreadFunc(void*);//pthread_create()的要求，该函数参数和返回值都是void*
	private:
		pthread_t _pid;
		bool _is_runing;
};//end of namespace w
}



#endif
