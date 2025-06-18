#ifndef SG_SERVICELOCATOR
#define SG_SERVICELOCATOR

#include <unordered_map>
#include <typeindex>
#include <memory>
#include <mutex>

namespace studgine
{
    class ServiceLocator
    {
    public:
        template<typename T>
        std::shared_ptr<T> GetService()
        {
            std::lock_guard<std::mutex> lock(m_mutex);
            auto it = m_services.find(typeid(T));
            if (it != m_services.end())
            {
                return std::static_pointer_cast<T>(it->second);
            }

            auto service = std::make_shared<T>();
            m_services[typeid(T)] = service;
            return service;
        }

        static ServiceLocator& GetInstance();

        void Shutdown();

    private:
        std::unordered_map<std::type_index, std::shared_ptr<void>> m_services;
        std::mutex m_mutex;

        static inline ServiceLocator* s_instance = nullptr;

        ServiceLocator() = default;
        ~ServiceLocator() = default;

        ServiceLocator(const ServiceLocator&) = delete;
        ServiceLocator& operator=(const ServiceLocator&) = delete;
    };
}

#endif // SG_SERVICELOCATOR
