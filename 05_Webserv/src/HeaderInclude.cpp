#include "HeaderIncludes.hpp"

std::string getTime()
{
std::time_t now = std::time(nullptr);
std::tm* timeinfo = std::localtime(&now);

std::ostringstream oss;
oss << std::put_time(timeinfo, "%a %b %d %H:%M:%S %Y");

return oss.str();
}
