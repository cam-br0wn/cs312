// rand6.cpp
#include <iostream>
#include <random>

// from TCPP2 section 14.5
int rollDice()
{
    using my_engine = std::default_random_engine;
    using my_distribution = std::uniform_int_distribution<>;

    my_engine re{};
    my_distribution one_to_six{1, 6};
    // note &, error in TCPP2
    auto die = [&]() { return one_to_six(re); };
    int x = die();
    return x;
}

int rollDice2()
{
    using my_device = std::random_device;
    using my_engine = std::default_random_engine;
    using my_distribution = std::uniform_int_distribution<>;

    // necessary for different random seed
    my_device rd;
    my_engine re{rd()};
    my_distribution one_to_six{1, 6};
    // note &, error in TCPP2
    auto die = [&]() { return one_to_six(re); };
    int x = die();
    return x;
}

int main()
{
    for (int ix = 0; ix < 10; ++ix)
    {
        std::cout << rollDice() << " ";
    }
    std::cout << std::endl;

    for (int ix = 0; ix < 10; ++ix)
    {
        std::cout << rollDice2() << " ";
    }
    std::cout << std::endl;
}
