#include <iostream>
#include <map>
#include <vector>

struct Meeting {
    int id;
    std::string date;
    std::string time;
};

std::map<int, Meeting> meetingsMap;
std::vector<Meeting> meetingsVector;

void addMeeting(int id, std::string date, std::string time) {
    Meeting newMeeting = {id, date, time};
    meetingsMap[id] = newMeeting;
    meetingsVector.push_back(newMeeting);

    std::cout << "Meeting added successfully with ID: " << id << std::endl;
}

void removeMeeting(int id) {
    auto it = meetingsMap.find(id);
    if (it != meetingsMap.end()) {
        meetingsMap.erase(it);

        for (auto it = meetingsVector.begin(); it != meetingsVector.end(); ++it) {
            if (it->id == id) {
                meetingsVector.erase(it);
                break;
            }
        }
        
        std::cout << "Meeting with ID: " << id << " removed successfully" << std::endl;
    } else {
        std::cout << "Meeting with ID: " << id << " not found" << std::endl;
    }
}

int main() {
    addMeeting(1, "2022-10-15", "10:00");
    addMeeting(2, "2022-10-15", "12:00");

    removeMeeting(1);

    return 0;
}