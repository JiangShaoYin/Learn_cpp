 /// @date    2018-07-02 13:20:31

#ifndef __THREAD_H__
#define __THREAD_H__
#include "Noncopy.h"
#include <pthread.h>
#include <functional>

namespace wd {
class Thread : private Noncopy{
	public:
		using CallBack = std::function<void()>;
		Thread(CallBack && cb);
		void start();
		void join();
		virtual ~Thread();
	private:
		static void * ThreadFunc(void*);//pthread_create()的求，该函数参数和返回值都是void*
	private:
		pthread_t _pid;
		bool _is_runing;
		CallBack _cb;
};//end of namespace w
}



#endif
