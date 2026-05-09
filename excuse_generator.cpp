/*
 * ============================================================
 *  ExcuseMaster 9000 - Homework Excuse Generator
 *  Description : Asks for a student name, picks a random
 *                excuse from a list, replaces {name} with
 *                the real name, and prints the result.
 * ============================================================
 */

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>   // srand, rand
#include <ctime>     // time

/* ---------- helper: replace {name} placeholder with actual name ---------- */
void replaceName(std::string &text, const std::string &name)
{
    const std::string placeholder = "{name}";
    size_t pos = 0;
    while ((pos = text.find(placeholder, pos)) != std::string::npos)
    {
        text.replace(pos, placeholder.length(), name);
        pos += name.length();
    }
}

int main()
{
    /* -------------------------------------------------------
     *  Seed random number generator with current time so
     *  a different excuse is picked on every run.
     * ------------------------------------------------------- */
    srand(static_cast<unsigned int>(time(nullptr)));

    /* -------------------------------------------------------
     *  Excuse templates stored in a vector.
     *  {name} is the placeholder replaced at runtime.
     * ------------------------------------------------------- */
    std::vector<std::string> excuses = {
        "{name} could not finish homework because laptop battery died at 99%.",
        "{name} was ready to submit but the file disappeared into the void.",
        "{name} wanted to study but Windows started updating — still updating.",
        "{name}'s dog ate the notebook and then looked very proud about it.",
        "{name} finished the assignment but accidentally emailed it to NASA.",
        "{name} tried to print the work but printer demanded ink, paper, and a sacrifice.",
        "{name} saved the file — on a USB drive that has been missing since 2022.",
        "{name} was about to submit when the internet decided to take a personal day.",
        "{name} wrote everything by hand but the pen turned out to be a highlighter.",
        "{name} studied all night but the assignment was for the wrong subject.",
        "{name} opened the textbook and immediately fell into a deep, peaceful sleep.",
        "{name} completed the homework but the teacher's email bounced back from space.",
    };

    /* -------------------------------------------------------
     *  Ask the student to enter their name.
     * ------------------------------------------------------- */
    std::string name;
    std::cout << "==========================================\n";
    std::cout << "      ExcuseMaster 9000 is Ready!        \n";
    std::cout << "==========================================\n";
    std::cout << "Enter student name: ";
    std::getline(std::cin, name);

    /* Use a fallback name if user just presses Enter */
    if (name.empty())
        name = "The Student";

    /* -------------------------------------------------------
     *  Pick a random excuse, replace placeholder, display it.
     * ------------------------------------------------------- */
    int index = rand() % static_cast<int>(excuses.size());
    std::string excuse = excuses[index];   // copy so original stays safe
    replaceName(excuse, name);             // swap {name} with real name

    std::cout << "\n------------------------------------------\n";
    std::cout << "  EXCUSE : " << excuse << "\n";
    std::cout << "------------------------------------------\n";
    std::cout << "  Good luck,  " << name << ". They might believe it.\n";
    std::cout << "------------------------------------------\n";

    return 0;
}
