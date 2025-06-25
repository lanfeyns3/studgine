#include "ECS.h"

namespace studgine
{
	entt::entity ECS::AddEntity()
	{
		entt::entity entity = m_registry.create();
		return entity;
	}
}