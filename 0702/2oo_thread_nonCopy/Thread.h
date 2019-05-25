 /// @date    2018-07-02 13:20:31

#ifndef __THREAD_H__
#define __THREAD_H__
#include "Noncopy.h"
#include <pthread.h>

namespace wd {
class Thread : private Noncopy{
	public:
		Thread();
		void start();
		void join();
		virtual ~Thread();
	private:
		virtual void run() = 0;
		static void * ThreadFunc(void*);//pthread_create()的求，该函数参数和返回值都是void*
	private:
		pthread_t _pid;
		bool _is_runing;
};//end of namespace w
}



#endif
