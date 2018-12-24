#ifndef INCLUDE_STATICSTORAGE_H_
#define INCLUDE_STATICSTORAGE_H_


#include <unordered_map>
#include <memory>
#include <string>
#include <typeinfo>

class IOC;

class IOCDestroyer {
 private:
    IOC *p_instance = nullptr;

 public:
    ~IOCDestroyer();

    void execute(IOC *p);
};

class IOC {
    friend class IOCDestroyer;

 private:
    std::unordered_map<std::string, std::shared_ptr<void>> container;

    static IOC *p_instance;

    static IOCDestroyer destroyer;

    IOC() = default;

    ~IOC() = default;

 public:
    IOC(const IOC &) = delete;

    IOC &operator=(IOC &) = delete;

    static IOC &getInstance();

    template<class T>
    void put(std::shared_ptr<T> objectPtr) {
        const std::type_info *typeId = &typeid(T);

        put(typeId->name(), objectPtr);
    }

    template<class T>
    void put(const std::type_info *typeId, std::shared_ptr<T> objectPtr) {
        if (!typeId) {
            throw std::runtime_error("invalid type id");
        }

        put(typeId->name(), objectPtr);
    }

    template<class T>
    void put(const std::string &id, std::shared_ptr<T> objectPtr) {
        auto iterator = container.find(id);

        if (iterator != container.end()) {
            throw std::runtime_error("entry already exists");
        }

        container[id] = objectPtr;
    }

    template<class T>
    std::shared_ptr<T> get() const {
        const std::type_info *typeId = &typeid(T);

        return get<T>(typeId->name());
    }

    template<class T>
    std::shared_ptr<T> get(const std::type_info *typeId) const {
        if (!typeId) {
            throw std::runtime_error("invalid type id");
        }

        return get<T>(typeId->name());
    }

    template<class T>
    std::shared_ptr<T> get(const std::string &id) const {
        auto iterator = container.find(id);

        if (iterator != container.end()) {
            return std::static_pointer_cast<T>(iterator->second);
        }

        throw std::runtime_error("entry not found");
    }

    void remove(const std::string &id);

    bool contains(const std::string &id);
};


#endif  // INCLUDE_STATICSTORAGE_H_
