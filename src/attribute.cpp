#include "terminalpp/attribute.hpp"
#include <algorithm>
#include <ostream>

namespace terminalpp {

// ==========================================================================
// OPERATOR<<(STREAM, LOW_COLOUR)
// ==========================================================================
std::ostream &operator<<(std::ostream &out, low_colour const &col)
{
    static constexpr struct
    {
        ansi::graphics::colour col;
        char const *text;
    } const colour_to_text[] = {
        { ansi::graphics::colour::black,    "black"   },
        { ansi::graphics::colour::red,      "red"     },
        { ansi::graphics::colour::green,    "green"   },
        { ansi::graphics::colour::yellow,   "yellow"  },
        { ansi::graphics::colour::blue,     "blue"    },
        { ansi::graphics::colour::magenta,  "magenta" },
        { ansi::graphics::colour::cyan,     "cyan"    },
        { ansi::graphics::colour::white,    "white"   },
        { ansi::graphics::colour::default_, "default" }
    };

    auto result = std::find_if(
        std::begin(colour_to_text),
        std::end(colour_to_text),
        [col](auto const &entry)
        {
            return col == entry.col;
        });

    return out << (result == std::end(colour_to_text)
                ? "unknown"
                : result->text);
}

// ==========================================================================
// OPERATOR<<(STREAM, HIGH_COLOUR)
// ==========================================================================
std::ostream &operator<<(std::ostream &out, high_colour const &col)
{
    int const value = col.value_ - 16;
    int const red   = value / 36;
    int const green = (value % 36) / 6;
    int const blue  = value % 6;

    return out << "#"
               << std::to_string(red)
               << std::to_string(green)
               << std::to_string(blue);

}

// ==========================================================================
// OPERATOR<<(STREAM, GREYSCALE_COLOUR)
// ==========================================================================
std::ostream &operator<<(std::ostream &out, greyscale_colour const &col)
{
    int const shade = col.shade_ - 232;
    return out << "#"
               << (shade < 10 ? "0" : "")
               << std::to_string(shade);
}

// ==========================================================================
// OPERATOR<<(STREAM, COLOUR)
// ==========================================================================
std::ostream &operator<<(std::ostream &out, colour const &col)
{
    switch (col.type_)
    {
        default :
            // Fall-through
        case colour::type::low :
            return out << col.low_colour_;

        case colour::type::high :
            return out << col.high_colour_;

        case colour::type::greyscale :
            return out << col.greyscale_colour_;
    }
}

// ==========================================================================
// OPERATOR<<(STREAM, INTENSITY)
// ==========================================================================
std::ostream &operator<<(std::ostream &out, intensity const &value)
{
    switch (value.value_)
    {
        default :
            // Fall-through
        case terminalpp::ansi::graphics::intensity::normal :
            return out << "normal";

        case terminalpp::ansi::graphics::intensity::bold :
            return out << "bold";

        case terminalpp::ansi::graphics::intensity::faint :
            return out << "faint";
    }
}

// ==========================================================================
// OPERATOR<<(STREAM, UNDERLINING)
// ==========================================================================
std::ostream &operator<<(std::ostream &out, underlining const &value)
{
    return out
        << (value.value_ == terminalpp::ansi::graphics::underlining::underlined
          ? "underlined"
          : "not underlined");
}

// ==========================================================================
// OPERATOR<<(STREAM, POLARITY)
// ==========================================================================
std::ostream &operator<<(std::ostream &out, polarity const &value)
{
    return out
        << (value.value_ == terminalpp::ansi::graphics::polarity::positive
          ? "positive"
          : "negative");
}

}
