#pragma once
#include <entt/entt.hpp>

namespace studgine
{
	class ECS
	{
	public:

		entt::entity AddEntity();

		template <typename T,typename... _Args>
		inline void AddComponent(entt::entity entity,_Args&&... args)
		{
			m_registry.emplace<T>(entity, std::forward<_Args>(args)...);
		};

		template<typename T>
		inline T& GetComponent(entt::entity entity)
		{
			return m_registry.get<T>(entity);
		};

		template<typename... Components>
		inline auto View()
		{
			return m_registry.view<Components...>();
		}
	private:
		entt::registry m_registry;
	};
}