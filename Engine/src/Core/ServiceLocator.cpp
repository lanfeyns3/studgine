#include "ServiceLocator.h"

namespace studgine
{
	ServiceLocator& ServiceLocator::GetInstance()
	{
		if (!s_instance)
			s_instance = new ServiceLocator();
		return *s_instance;
	}
	void ServiceLocator::Shutdown()
	{
		delete &GetInstance();
	}
}