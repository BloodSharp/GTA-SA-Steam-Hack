#ifndef CH4_INTERFACE_H
#define CH4_INTERFACE_H

namespace CH4
{
	namespace Interface
	{
		extern bool Enable;
		void GetPointers();
		namespace Render
		{
			void Initialize();
			void Background();
			void Interface();
		}
	}
}

#endif//CH4_INTERFACE_H

