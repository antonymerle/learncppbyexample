#include <print>
#include <ranges>
#include <string>
#include <vector>

void range_views()
{
    std::vector<std::string> cities{"Amsterdam", "Berlin", "Cologne", "LA"};

    auto large = [](const auto& s) { return s.size() > 5; };
    auto sub   = cities | std::views::filter(large) | std::views::reverse | std::views::as_rvalue |
               std::ranges::to<std::vector>();

    std::println("{}", sub);
}
