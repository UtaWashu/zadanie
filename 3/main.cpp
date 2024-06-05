#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, std::string> catch;

    cache["http://example.com/page1"] = "Data for page 1";
    cache["http://example.com/page2"] = "Data for page 2";

    std::string url = "http://example.com/page1";
    if (cache.find(url) != cache.end()) {
        std::cout << "Data found in cache for " << url << ": " << cache[url] << std::endl;
    } else {
        std::cout << "No data found in cache for " << url << std::endl;
    }

    cache.erase("http://example.com/page2");

    url = "http://example.com/page2";
    if (cache.find(url) != cache.end()) {
        std::cout << "Data found in cache for " << url << ": " << cache[url] << std::endl;
    } else {
        std::cout << "No data found in cache for " << url << std::endl;
    }

    return 0;
}
