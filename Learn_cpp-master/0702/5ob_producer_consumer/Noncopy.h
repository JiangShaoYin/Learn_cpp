 /// @date    2018-07-02 20:42:56
 
#ifndef __NONCOPY_H__
#define __NONCOPY_H__
class Noncopy {
	public:
		Noncopy() {}
		~Noncopy(){}
	private:
		Noncopy(const Noncopy&);
		Noncopy operator=(Noncopy &rhs);
};
#endif
