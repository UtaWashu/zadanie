#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <ctime>

class DocumentVersionSystem {
private:
    std::map<int, std::vector<std::string>> versions;

public:
    void addNewVersion(int docId, const std::string& date) {
        if (versions.find(docId) == versions.end()) {
            std::vector<std::string> newVersion;
            newVersion.push_back(date);
            versions.insert({docId, newVersion});
        } else {
            versions[docId].push_back(date);
        }
    }

    std::string getLastVersionDate(int docId) {
        if (versions.find(docId) != versions.end() && !versions[docId].empty()) {
            return versions[docId].back();
        } else {
            return "Document not found or no versions available";
        }
    }
};

int main() {
    DocumentVersionSystem dvs;

    dvs.addNewVersion(1, "2021-10-01");
    dvs.addNewVersion(1, "2021-10-05");
    dvs.addNewVersion(1, "2021-10-10");

    std::cout << "Last version date for document 1: " << dvs.getLastVersionDate(1) << std::endl;

    std::cout << "Last version date for document 2: " << dvs.getLastVersionDate(2) << std::endl;

    return 0;
}