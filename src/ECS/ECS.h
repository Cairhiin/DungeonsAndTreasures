#pragma once

#include <vector>
#include <bitset>
#include <algorithm>
#include <memory>
#include <array>

class Component;
class Entity;

inline std::size_t GetComponentTypeId() {
	static std::size_t last_id = 0;
	return last_id++;
}

template <typename T>
inline std::size_t GetComponentTypeId() {
	static size_t type_id = GetComponentTypeId();
	return type_id;
}

constexpr std::size_t max_components = 32;

class Component {
public:
	Entity* entity;

	virtual ~Component() {}

	virtual void init() {}
	virtual void update() {}
	virtual void draw() {}

};

class Entity {
public:
	void update() {
		for (auto& c : components_)
			c->update();
	}

	void draw() {
		for (auto& c : components_)
			c->draw();
	}

	bool isActive() const { return active; }

	void Destroy() { active = false; }
	
	template <typename T>
	bool hasComponent() {
		return componentBitset_[GetComponentTypeId<T>];
	}

	template <typename T, typename... TArgs>
	T& AddComponent(TArgs&&... mArgs) {
		T* c(new T(std::forward<TArgs>(mArgs)...));
		c->entity = this;
		std::unique_ptr<Component> uPtr{ c };
		components_.emplace_back(std::move(uPtr));

		componentArray_[GetComponentTypeId<T>()] = c;
		componentBitset_[GetComponentTypeId<T>()] = true;

		c->init();
		return *c;
	}

	template <typename T>
	T& GetComponent() const {
		auto ptr(componentArray_[GetComponentTypeId<T>()]);
		return *static_cast<T*>(ptr);
	}

private:
	bool active = true;
	std::vector<std::unique_ptr<Component>> components_;
	std::bitset<max_components> componentBitset_;
	std::array<Component*, max_components> componentArray_;
};

class Manager {
public:
	void update() {
		for (auto& e : entities)
			e->update();
	}

	void draw() {
		for (auto& e : entities)
			e->draw();
	}

	void refresh() {
		entities.erase(std::remove_if(entities.begin(), entities.end(),
			[](const std::unique_ptr<Entity>& entity) {
				return !entity->isActive();
			}),
			entities.end()
		);
	}

	Entity& AddEntity() {
		Entity* e = new Entity();
		std::unique_ptr<Entity> uPtr{ e };
		entities.emplace_back(std::move(uPtr));
		return *e;
	}

private:
	std::vector<std::unique_ptr<Entity>> entities;
};