/*
 * ============================================================
 *  RoastBot 3000 - Personalized Roast Generator
 *  Description : Asks for a name, picks a random roast from
 *                a pre-loaded list, swaps {name} placeholder
 *                with the real name, and prints the result.
 * ============================================================
 */

#include <iostream>
#include <string>
#include <cstdlib>   // srand, rand
#include <ctime>     // time
#include <algorithm> // replace

/* ---------- helper: replace every occurrence of 'from' with 'to' ---------- */
void replacePlaceholder(std::string &str,
                        const std::string &from,
                        const std::string &to)
{
    size_t pos = 0;
    while ((pos = str.find(from, pos)) != std::string::npos)
    {
        str.replace(pos, from.length(), to);
        pos += to.length();
    }
}

int main()
{
    /* -------------------------------------------------------
     *  Seed the random-number generator once using the
     *  current time so we get a different roast each run.
     * ------------------------------------------------------- */
    srand(static_cast<unsigned int>(time(nullptr)));

    /* -------------------------------------------------------
     *  Roast templates — {name} is the placeholder that will
     *  be swapped out for whatever the user types.
     * ------------------------------------------------------- */
    const std::string roasts[] = {
        "{name} types so slow the keyboard filed for retirement.",
        "{name}'s code is so confusing even the compiler needed therapy.",
        "Scientists confirmed {name}'s Wi-Fi runs on pure disappointment.",
        "{name} tried to write a Hello World program — the world didn't reply.",
        "{name}'s variable names read like a keyboard fell down the stairs.",
        "They say {name} debugs by turning the monitor off and hoping for the best.",
        "{name}'s commit history is just one line: 'fixed stuff (nothing worked)'.",
        "{name} uses Comic Sans in production and calls it 'playful UX'.",
        "NASA called — they need {name}'s code as a crash-landing simulator.",
        "{name}'s Stack Overflow profile is flagged as a public safety concern.",
        "{name} wrote an infinite loop and blamed the CPU for being too slow.",
        "Whenever {name} pushes to main, junior devs quietly update their CVs.",
    };

    /* Total number of roasts in the array */
    const int ROAST_COUNT = sizeof(roasts) / sizeof(roasts[0]);

    /* -------------------------------------------------------
     *  Ask the user for their name
     * ------------------------------------------------------- */
    std::string name;
    std::cout << "========================================\n";
    std::cout << "        Welcome to RoastBot 3000!       \n";
    std::cout << "========================================\n";
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    /* Fallback if the user just hits Enter */
    if (name.empty())
        name = "Mystery Human";

    /* -------------------------------------------------------
     *  Pick a random roast, replace placeholder, print it
     * ------------------------------------------------------- */
    int index = rand() % ROAST_COUNT;
    std::string roast = roasts[index];          // copy so we can modify it
    replacePlaceholder(roast, "{name}", name);   // swap {name} → real name

    std::cout << "\n----------------------------------------\n";
    std::cout << "  " << roast << "\n";
    std::cout << "----------------------------------------\n";

    return 0;
}
