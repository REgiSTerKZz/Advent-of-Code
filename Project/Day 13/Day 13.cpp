// GIVEN the Day 13 [Explanation](https://adventofcode.com/2022/day/13) this is the implementation by REgiSTerKZz


#include <iostream>
#include <vector>
#include <variant>

// Define my List so I don't have to type that much xD
typedef std::variant<int, std::vector<int>> mINT;       // Variant
typedef std::vector<mINT> mList;                        // List of Variants -> TODO: maybe it wont be used

bool CheckList(mINT &A, mINT &B) {
    // Check types

    // DIFFERENT (Make sure both are lists)
    if (A.index() != B.index())
    {
        // Get the smallest -> Meaning the INT (0)
            // Make INT into a INT List
        if (A.index() < B.index()) {
            A = std::vector<int>{ std::get<int>(A) };
        }
        else {
            B = std::vector<int>{ std::get<int>(B) };
        }
        return CheckList(A, B);
    }

    // BOTH LISTS
    else if (A.index() == 1)
    {
        std::cout << "Both Lists!\n";
        // Get the first elem of the list
        auto aList = std::get<std::vector<int>>(A);
        auto bList = std::get<std::vector<int>>(B);


        int minSze = std::min(aList.size(), bList.size());

        for (int i = 0; i < minSze; i++)
        {
            mINT a = aList[i];
            mINT b = bList[i];

            // Check if there is any item smaller in A than in B
            if (CheckList(a, b))
            {
                return true;
            }
        }
        // If A is smaller list wins
        return aList.size() < bList.size();
    }
    // BOTH INTS
    else
    {
        std::cout << "Both ints!: A{" << std::get<int>(A) << "}B{" << std::get<int>(B) << "}\n";
        return std::get<int>(A) < std::get<int>(B);
    }
}


int main()
{
    mList _list;
    mINT test = std::vector<int>(2, 3);

    _list.push_back(std::vector<int>(4, 13));
    _list.push_back(test);
    _list.push_back(0);
    _list.push_back(2);


    std::cout <<  ((CheckList(_list[0], _list[1])) ? "Smaller": "Larger");

    std::cout << " ";
}