#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

struct Stat
{
    std::string label;
    std::string value;
};

std::string makeStat(const Stat& stat)
{
    std::stringstream ss;

    ss << std::left
       << std::setw(14)
       << stat.label
       << ": "
       << stat.value;

    return ss.str();
}

void drawText(std::ofstream& file,
              int x,
              int y,
              const std::string& text,
              int size)
{
    file << R"(<?xml version="1.0" encoding="UTF-8"?>

    <text
    xml:space="preserve" x=")";

    file << x;

    file << R"(" y=")";

    file << y;

    file << R"(" fill="#cdd6f4"
    font-family="monospace"
    font-size=")";

    file << s:wize;

    file << R"(" > )";

    file << text;

    file << R"(
    </text>

)";
}

int main()
{
    std::ofstream file("card/card.svg");

    file << R"(<?xml version="1.0" encoding="UTF-8"?>

<svg width="400" height="210"
xmlns="http://www.w3.org/2000/svg">

<rect
  width="400"
  height="210"
  fill="#1e1e2e"
/>

<rect
  x="10"
  y="20"
  width="380"
  height="180"
  rx="8"
  fill="#1e1e2e"
  stroke="#6c7086"
  stroke-width="1"
/>

)";

    drawText(file, 20, 40, "ashansud@nixos", 20);

    file << R"(

<line
  x1="20"
  y1="50"
  x2="380"
  y2="50"
  stroke="#cdd6f4"
  stroke-width="2"
/>

)";

    std::vector<Stat> stats =
    {
        {"OS",        "NixOS"},
        {"Shell",     "fish"},
        {"WM",        "Hyprland"},
        {"Language",  "C++"},
        {"Repos",     "6"},
        {"Followers", "2"},
        {"Streaks",   "1 days"}
    };

    int y = 70;

    for(const auto& stat : stats)
    {
        drawText(
            file,
            20,
            y,
            makeStat(stat),
            18
        );

        y += 20;
    }

    file << "\n</svg>\n";
}
