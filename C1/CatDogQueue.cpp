#include <iostream>
#include <queue>
#include <random>
#include <cmath>
#include <string>

class Pet
{
public:
    Pet(std::string type)
    {
        type_ = type;
    }
    std::string getPetType()
    {
        return type_;
    }
    virtual ~Pet() = default;

private:
    std::string type_;
};

class Dog : public Pet
{
public:
    Dog() : Pet("dog") {}
};

class Cat : public Pet
{
public:
    Cat() : Pet("cat") {}
};

class CatDogQueue
{
private:
    std::queue<std::pair<Cat, size_t>> CatQueue;
    std::queue<std::pair<Dog, size_t>> DogQueue;
    size_t time_stamp = 1;

public:
    void add(Pet &pet)
    {
        std::cout << " add a new pet of " << pet.getPetType();
        if (pet.getPetType() == "dog")
        {
            DogQueue.push(std::make_pair(dynamic_cast<Dog &>(pet), time_stamp));
        }
        else
        {
            CatQueue.push(std::make_pair(dynamic_cast<Cat &>(pet), time_stamp));
        }
        std::cout << ", " << time_stamp << std::endl;
        time_stamp++;
    }
    bool isEmpty()
    {
        return (CatQueue.empty() && DogQueue.empty());
    }
    bool isDogEmpty()
    {
        return DogQueue.empty();
    }
    bool isCatEmpty()
    {
        return CatQueue.empty();
    }
    void pollAll()
    {
        std::cout << "pollAll DogCat Queue: ";
        while (!isEmpty())
        {
            size_t dogLatestTimeStamp, catLatestTimeStamp;
            if (!isDogEmpty())
            {
                dogLatestTimeStamp = DogQueue.front().second;
            }
            else
                dogLatestTimeStamp = 0;
            if (!isCatEmpty())
            {
                catLatestTimeStamp = CatQueue.front().second;
            }
            else
                catLatestTimeStamp = 0;
            if (dogLatestTimeStamp && dogLatestTimeStamp < catLatestTimeStamp || !catLatestTimeStamp)
            {
                std::cout << "(" << DogQueue.front().first.getPetType() << ", " << dogLatestTimeStamp << ") ";
                DogQueue.pop();
            }
            else if (catLatestTimeStamp && catLatestTimeStamp < dogLatestTimeStamp || !dogLatestTimeStamp)
            {
                std::cout << "(" << CatQueue.front().first.getPetType() << ", " << catLatestTimeStamp << ") ";
                CatQueue.pop();
            }
        }
        std::cout << "Done!" << std::endl;
    }
    void pollCat()
    {
        std::cout << "poll Cat Queue: ";
        while (!isCatEmpty())
        {
            std::cout << "(" << CatQueue.front().first.getPetType() << ", " << CatQueue.front().second << ") ";
            CatQueue.pop();
        }
        std::cout << "Done!" << std::endl;
    }
    void pollDog()
    {
        std::cout << "poll dog Queue: ";
        while (!isDogEmpty())
        {
            std::cout << "(" << DogQueue.front().first.getPetType() << ", " << DogQueue.front().second << ") ";
            DogQueue.pop();
        }
        std::cout << "Done!" << std::endl;
    }
};

int main(int argc, char **argv)
{
    CatDogQueue testDogCatQueue;

    std::random_device r;
    std::default_random_engine v1(r());
    std::default_random_engine v2(r());
    std::uniform_int_distribution<int> uniform_dist(0, 15);
    std::uniform_int_distribution<int> uniform_bool(0, 1);
    try
    {
        for (int i = 0; i < 15; ++i)
        {
            std::cout << "[Step " << i << "]:  ";
            int op_pet = std::round(uniform_bool(v2));
            int op_queue = std::round(uniform_dist(v1));
            if (op_queue > 8)
            {
                if (op_pet)
                    testDogCatQueue.pollCat();
                else
                    testDogCatQueue.pollDog();
            }
            else
            {

                if (op_pet)
                {
                    Cat cat;
                    testDogCatQueue.add(cat);
                }
                else
                {
                    Dog dog;
                    testDogCatQueue.add(dog);
                }
            }
        }
        testDogCatQueue.pollAll();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}