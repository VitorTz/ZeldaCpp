//
// Created by vitor on 1/28/24.
//

#ifndef ZELDACPP_ECS_H
#define ZELDACPP_ECS_H
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include "../util/Rect.h"


namespace ze {


    class GameObj;

    class Component {

    public:
        const std::string name;

    protected:
        ze::GameObj* gameObj;

    public:
        Component(Component&& ) = default;
        explicit Component(std::string name) : name(std::move(name)), gameObj(nullptr) { };
        virtual ~Component() = default;
        virtual void update([[maybe_unused]] float dt) { };
        virtual void draw([[maybe_unused]] sf::RenderWindow& window) { };
        virtual void setGameObj(ze::GameObj* gameObj_) { this->gameObj = gameObj_; };

    };


    enum GroupId {
        AllGroup,
        CollideGroup,
        TreesGroup,
        CameraGroup
    };


    class Group {

    public:
        const GroupId id;

    private:
        std::set<ze::GameObj*> allObjs;

    public:
        explicit Group(GroupId id) : id(id) { };
        ~Group() = default;
        virtual void update(float dt);
        virtual void add(ze::GameObj* gameObj);
        virtual void rmv(ze::GameObj* gameObj);
        virtual void rmvAll();
        virtual std::set<ze::GameObj*>* getAllObjs();

    };



    class GameObj {

    public:
        const std::string name;
        const int zIndex;

    public:
        sf::Vector2f direction;
        float speed;
        float rotation;
        float scale;
        ze::Rect rect;

    private:
        std::map<std::string, std::unique_ptr<ze::Component>> componentMap;
        std::set<ze::Group*> groups;

    public:
        GameObj(
                std::string name,
                int zIndex
        ) : name(std::move(name)), zIndex(zIndex), speed(0), rotation(0), scale(1.f) { };
        ~GameObj();
        void addComponent(std::unique_ptr<ze::Component> component);
        ze::Component* getComponent(const std::string& componentName);
        void addToGroup(ze::Group* group);
        void rmvFromGroup(ze::Group* group);
        void update(float dt);
        void draw(sf::RenderWindow& window);

    };

    class GroupPool {

    private:
        static std::map<ze::GroupId, std::unique_ptr<ze::Group>> groupMap;

    public:
        static void create(ze::GroupId id);
        static void create(const std::vector<ze::GroupId>& groups);
        static void create(std::unique_ptr<ze::Group> group);
        static ze::Group* get(ze::GroupId id);
        static void clear();

    };


    class GameObjPool {

    private:
        static std::map<std::string, std::unique_ptr<ze::GameObj>> gameObjMap;

    public:
        static ze::GameObj* create(const std::string& name, int zIndex, const std::vector<ze::GroupId>& groups);
        static ze::GameObj* get(const std::string& name);
        static void erase(const std::string& name);
        static void clear();

    };

}

#endif //ZELDACPP_ECS_H
